// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_POINT_H
#define YASL_CORE_POINT_H

#include "yasl/common/types.h"

#include <QPoint>

namespace script {
template<> struct make_type_helper<QPoint> { inline static script::Type get() { return script::Type::QPoint; } };
template<> struct make_type_helper<QPointF> { inline static script::Type get() { return script::Type::QPointF; } };
} // namespace script

#endif // YASL_CORE_POINT_H
