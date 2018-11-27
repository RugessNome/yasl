// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "project/function.h"

#include <QJsonArray>

const QString Function::staticTypeCode = "function";
const QString Constructor::staticTypeCode = "constructor";
const QString Destructor::staticTypeCode = "destructor";


Function::Function(const QString & n, Qt::CheckState c)
  : Node(n, c)
  , isExplicit(false)
  , isStatic(false)
  , isConst(false)
  , isDeleted(false)
  , bindingMethod(Function::AutoBinding)
{

}

void Function::fillJson(QJsonObject & obj) const
{
  Node::fillJson(obj);

  if (!rename.isEmpty())
    obj["rename"] = rename;

  obj["signature"] = parameters.join(";") + "->" + returnType;

  if(isExplicit)
    obj["explicit"] = isExplicit;
  if(isStatic)
    obj["static"] = isStatic;
  if(isConst)
    obj["const"] = isConst;
  if(isDeleted)
    obj["deleted"] = isDeleted;
  json::writeBindingMethod(obj, bindingMethod);

  if (!defaultArguments.isEmpty())
    obj["defaults"] = defaultArguments.join(';');
}

QSharedPointer<Node> Function::fromJson(const QJsonObject & obj)
{
  auto ret = FunctionRef::create(obj.value("name").toString(), json::readCheckState(obj));
  ret->version = json::readQtVersion(obj);

  ret->rename = obj.value("rename").toString();

  QStringList signature = obj.value("signature").toString().split("->");
  ret->parameters = signature.front().split(';', QString::SkipEmptyParts);
  ret->returnType = signature.size() == 2 ? signature.back() : QString();
  if (ret->returnType.isEmpty())
    ret->returnType = "void";

  ret->isExplicit = obj.contains("explicit") ? obj.value("explicit").toBool() : false;
  ret->isStatic = obj.contains("static") ? obj.value("static").toBool() : false;
  ret->isConst = obj.contains("const") ? obj.value("const").toBool() : false;
  ret->isDeleted = obj.contains("deleted") ? obj.value("deleted").toBool() : false;
  ret->bindingMethod = json::readBindingMethod(obj);
  ret->defaultArguments = obj.contains("defaults") ? obj.value("defaults").toString().split(';', QString::SkipEmptyParts) : QStringList();

  return ret;
}

QString Function::display() const
{
  QString result;
  if (isExplicit)
    result += "explicit ";
  if (isStatic)
    result += "static ";

  result += returnType;
  result += " " + name;
  result += "(";
  {
    QStringList params = parameters;
    for (int i(0); i < defaultArguments.size(); ++i)
      params[params.size() - i - 1] += " = " + defaultArguments.at(i);
    result += params.join(", ");
  }
  result += ")";

  if (isConst)
    result += " const";

  if (isDeleted)
    result += " = delete";

  result += ";";

  if (!version.isNull())
    result += " [" + version.toString() + "]";

  if (!rename.isEmpty())
    result += " [" + rename + "]";

  if (bindingMethod != Function::AutoBinding)
    result += " [" + serialize(bindingMethod) + "]";

  return result;
}

QStringList Function::getSpecifiers() const
{
  QStringList specifiers;
  if (isConst)
    specifiers << "const";
  if (isDeleted)
    specifiers << "delete";
  if (isExplicit)
    specifiers << "explicit";
  if (isStatic)
    specifiers << "static";
  return specifiers;
}

void Function::setSpecifiers(const QStringList & specs)
{
  isConst = specs.contains("const");
  isDeleted = specs.contains("delete");
  isExplicit = specs.contains("explicit");
  isStatic = specs.contains("static");
}

Constructor::Constructor(const QString & n, Qt::CheckState cs)
  : Function(n, cs)
{

}

void Constructor::fillJson(QJsonObject & obj) const
{
  Function::fillJson(obj);
  obj["signature"] = obj.value("signature").toString().chopped(2);
}

QSharedPointer<Node> Constructor::fromJson(const QJsonObject & obj)
{
  auto ret = ConstructorRef::create(obj.value("name").toString(), json::readCheckState(obj));
  ret->version = json::readQtVersion(obj);

  ret->parameters = obj.value("signature").toString().split(';', QString::SkipEmptyParts);
  ret->returnType = QString();

  ret->isExplicit = obj.value("explicit").toBool();
  ret->isStatic = obj.value("static").toBool();
  ret->isConst = obj.value("const").toBool();
  ret->isDeleted = obj.value("deleted").toBool();
  ret->bindingMethod = json::readBindingMethod(obj);
  ret->defaultArguments = obj.contains("defaults") ? obj.value("defaults").toString().split(';', QString::SkipEmptyParts) : QStringList();

  return ret;
}

QString Constructor::display() const
{
  QString result;
  if (isExplicit)
    result += "explicit ";
  if (isStatic)
    result += "static ";

  result += name;
  result += "(";
  for (const auto & p : parameters)
    result += p + ", ";
  if (result.endsWith(", "))
    result.chop(2);
  result += ")";

  if (isDeleted)
    result += " = delete";

  result += ";";
  return result;
}


Destructor::Destructor(const QString & n, Qt::CheckState cs)
  : Function(n, cs)
{

}

void Destructor::fillJson(QJsonObject & obj) const
{
  Function::fillJson(obj);

  obj.remove("returns");
  obj.remove("parameters");
  obj.remove("explicit");
  obj.remove("static");
  obj.remove("const");
  obj.remove("macros");
  obj.remove("signature");
}

QSharedPointer<Node> Destructor::fromJson(const QJsonObject & obj)
{
  auto ret = DestructorRef::create(obj.value("name").toString(), json::readCheckState(obj));
  ret->version = json::readQtVersion(obj);

  ret->isDeleted = obj.value("deleted").toBool();

  return ret;
}

QString Destructor::display() const
{
  QString result;

  result += name;
  result += "()";

  if (isDeleted)
    result += " = delete";

  result += ";";
  return result;
}

namespace json
{

Function::BindingMethod readBindingMethod(const QJsonObject & obj)
{
  if (!obj.contains("binding"))
    return Function::AutoBinding;
  return Function::deserialize<Function::BindingMethod>(obj.value("binding").toString());
}

void writeBindingMethod(QJsonObject &obj, Function::BindingMethod bm)
{
  if (bm == Function::AutoBinding)
    return;

  obj["binding"] = Function::serialize(bm);
}

} // namespace json