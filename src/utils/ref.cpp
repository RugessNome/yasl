// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/utils/ref.h"

#include "yasl/core/object.h"

#include <script/classtemplate.h>
#include <script/engine.h>
#include <script/interpreter/executioncontext.h>
#include <script/functionbuilder.h>
#include <script/functiontemplate.h>
#include <script/namespace.h>
#include <script/private/engine_p.h>
#include <script/private/function_p.h>
#include <script/private/value_p.h>
#include <script/templatebuilder.h>

#include <QObject>


namespace callbacks
{

script::Value default_ctor(script::FunctionCall *c)
{
  c->thisObject().impl()->set_qobject(nullptr);
  return c->thisObject();
}

script::Value copy_ctor(script::FunctionCall *c)
{
  script::Value other = c->arg(0);
  c->thisObject().impl()->set_qobject(other.impl()->data.builtin.qobject);
  return c->thisObject();
}

script::Value dtor(script::FunctionCall *c)
{
  c->thisObject().impl()->set_qobject(nullptr);
  c->thisObject().impl()->clear();
  return c->thisObject();
}

script::Value get(script::FunctionCall *c)
{
  /// TODO : throw on error ?
  auto self = c->thisObject();
  QObject *ptr = self.impl()->data.builtin.qobject;
  return ptr->property("_yasl_data_").value<binding::BindingData>().value;
}

script::Value is_null(script::FunctionCall *c)
{
  return c->engine()->newBool(c->thisObject().impl()->data.builtin.qobject == nullptr);
}

script::Value is_valid(script::FunctionCall *c)
{
  return c->engine()->newBool(c->thisObject().impl()->data.builtin.qobject != nullptr);
}

script::Value assign(script::FunctionCall *c)
{
  script::Value other = c->arg(1);
  c->thisObject().impl()->set_qobject(other.impl()->data.builtin.qobject);
  return c->thisObject();
}

script::Value cast(script::FunctionCall *c)
{
  QObject *ptr = c->thisObject().impl()->data.builtin.qobject;
  script::Value ret = c->engine()->construct(c->callee().returnType(), {});
  ret.impl()->set_qobject(ptr);
  return ret;
}

}

static script::Class get_qobject_class(script::Engine *e)
{
  return e->getClass(script::Type::QObject);
}

static script::Class get_ref_instance(const script::Class & qobjectclass)
{
  using namespace script;

  ClassTemplate ct = qobjectclass.engine()->getTemplate(Engine::RefTemplate);
  std::vector<TemplateArgument> args;
  args.push_back(TemplateArgument{ Type{ qobjectclass.id() } });
  return ct.getInstance(args);
}

static void inject_conversions(script::Class & ref, const script::Class & src)
{
  using namespace script;

  if (src.id() == ref.arguments().front().type.baseType().data())
    return;

  // we add a conversion from Ref<T> to Ref<Base>
  ref.Conversion(get_ref_instance(src).id(), callbacks::cast).create();
}

static void inject_conversions_recursively(script::Class & ref, const script::Class & src, const script::Class & qobject)
{
  inject_conversions(ref, src);

  if (src == qobject)
    return;

  inject_conversions_recursively(ref, src.parent(), qobject);
}


static void fill_ref_instance(script::Class & instance, const script::Class & qclass)
{
  using namespace script;

  instance.Constructor(callbacks::default_ctor).create();
  instance.Constructor(callbacks::copy_ctor).params(Type::cref(instance.id())).create();
  instance.Constructor(callbacks::copy_ctor).params(Type::cref(qclass.id())).create();

  instance.newDestructor(callbacks::dtor);

  instance.Method("get", callbacks::get)
    .setConst()
    .returns(Type::ref(qclass.id()))
    .create();

  instance.Method("isNull", callbacks::is_null)
    .setConst()
    .returns(Type::Boolean)
    .create();

  instance.Method("isValid", callbacks::is_valid)
    .setConst()
    .returns(Type::Boolean)
    .create();

  instance.Operation(AssignmentOperator, callbacks::assign)
    .returns(Type::ref(instance.id()))
    .params(Type::cref(instance.id())).create();

  instance.Conversion(Type::ref(qclass.id()), callbacks::get)
    .setConst()
    .create();

  inject_conversions_recursively(instance, qclass, get_qobject_class(qclass.engine()));
}


script::Class ref_template(script::ClassTemplate ref, const std::vector<script::TemplateArgument> & targs)
{
  /// TODO: should we throw on failure

  using namespace script;

  if (targs.size() != 1 || targs.at(0).kind != TemplateArgument::TypeArgument)
    return Class{}; 

  Type T = targs.front().type;
  if (!T.isObjectType() || T.isReference() || T.isRefRef())
    return Class{};

  Engine *e = ref.engine();

  Class qobject_class = get_qobject_class(e);
  Class qclass = e->getClass(T);
  if (!qclass.inherits(qobject_class))
    return Class{};

  ClassBuilder builder{ std::string{} };

  Class result = ref.build(builder, targs);

  fill_ref_instance(result, qclass);

  return result;
}


void register_ref_template(script::Namespace ns)
{
  using namespace script;

  std::vector<TemplateParameter> params;
  params.push_back(TemplateParameter{ TemplateParameter::TypeParameter{}, "T" });

  ClassTemplate ref = Symbol{ ns }.ClassTemplate("Ref")
    .setParams(std::move(params))
    .setScope(Scope{ ns })
    .setCallback(ref_template)
    .get();

  ns.engine()->implementation()->ref_template_ = ref;
}

script::Class register_ref_specialization(script::Engine *e, script::Type object_type, script::Type::BuiltInType type_id)
{
  using namespace script;
 
  auto ref_template = e->getTemplate(Engine::RefTemplate);

  ClassBuilder builder = ClassBuilder::New(std::string{})
    .setId(type_id)
    .setFinal();

  std::vector<TemplateArgument> targs{
    TemplateArgument{ object_type },
  };

  Class ref_type = ref_template.addSpecialization(targs, builder);

  fill_ref_instance(ref_type, e->getClass(object_type));

  return ref_type;
}

script::Value make_ref(script::Engine *e, const script::Type & ref_type, QObject *value)
{
  using namespace script;
  Value v = e->uninitialized(ref_type);
  v.impl()->set_qobject(value);
  v.impl()->type = v.impl()->type.withoutFlag(Type::UninitializedFlag);
  return v;
}

script::Class get_ref_type(script::Engine *e, const script::Type & object_type)
{
  return get_ref_instance(e->getClass(object_type));
}
