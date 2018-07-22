// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_URLQUERY_H
#define YASL_CORE_URLQUERY_H

#include "yasl/binding/types.h"

#include <QUrlQuery>

namespace binding {
template<> struct make_type_t<QUrlQuery> { inline static script::Type get() { return script::Type::QUrlQuery; } };
} // namespace binding

#endif // YASL_CORE_URLQUERY_H