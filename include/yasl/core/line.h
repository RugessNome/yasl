// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_LINE_H
#define YASL_CORE_LINE_H

#include "yasl/common/types.h"

#include <QLine>

namespace script {
template<> struct make_type_helper<QLine> { inline static script::Type get() { return script::Type::QLine; } };
template<> struct make_type_helper<QLineF> { inline static script::Type get() { return script::Type::QLineF; } };
template<> struct make_type_helper<QLineF::IntersectType> { inline static script::Type get() { return script::Type::QLineFIntersectType; } };
} // namespace script

#endif // YASL_CORE_LINE_H
