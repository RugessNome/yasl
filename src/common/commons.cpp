// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/common/commons.h"

#include <script/engine.h>
#include <script/functionbuilder.h>
#include <script/functiontemplate.h>
#include <script/interpreter/executioncontext.h>
#include <script/namespace.h>
#include <script/templateargumentdeduction.h>
#include <script/templatebuilder.h>


script::Value callback_type_id(script::FunctionCall *c)
{
  int ret = c->callee().arguments().front().type.data();
  return c->engine()->newInt(ret);
}

static void template_type_id_deduce(script::TemplateArgumentDeduction &deduc, const script::FunctionTemplate & variant_value, const std::vector<script::TemplateArgument> & targs, const std::vector<script::Type> & itypes)
{
  if (targs.size() != 1)
    return deduc.fail();
}

static void template_type_id_substitute(script::FunctionBuilder & builder, script::FunctionTemplate type_id, const std::vector<script::TemplateArgument> & targs)
{
  builder.returns(script::Type::Int);
}

static std::pair<script::NativeFunctionSignature, std::shared_ptr<script::UserData>> template_type_id_instantitate(script::FunctionTemplate type_id, script::Function instance)
{
  using namespace script;

  return { callback_type_id, nullptr };
}



void register_commons_utils(script::Engine *e)
{
  // int type_id<T>()
  {
    using namespace script;

    std::vector<TemplateParameter> params;
    params.push_back(TemplateParameter{ TemplateParameter::TypeParameter{}, "T" });

    FunctionTemplate variant_value = Symbol{ e->rootNamespace() }.newFunctionTemplate("type_id")
      .setParams(std::move(params))
      .setScope(Scope{ e->rootNamespace() })
      .deduce(template_type_id_deduce).substitute(template_type_id_substitute).instantiate(template_type_id_instantitate)
      .get();
  }
}
