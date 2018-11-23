// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_JSONOBJECT_H
#define YASL_CORE_JSONOBJECT_H

#include "yasl/binding/types.h"

#include <QJsonObject>

namespace script { namespace bind {
template<> struct make_type_t<QJsonObject> { inline static script::Type get() { return script::Type::QJsonObject; } };
} /* namespace bind */ } /* namespace script */

#endif // YASL_CORE_JSONOBJECT_H
