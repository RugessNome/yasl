// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_GUI_PAINTERPATH_H
#define YASL_GUI_PAINTERPATH_H

#include "yasl/common/types.h"

#include <QPainterPath>

namespace script {
template<> struct make_type_helper<QPainterPath> { inline static script::Type get() { return script::Type::QPainterPath; } };
template<> struct make_type_helper<QPainterPath::ElementType> { inline static script::Type get() { return script::Type::QPainterPathElementType; } };
template<> struct make_type_helper<QPainterPathStroker> { inline static script::Type get() { return script::Type::QPainterPathStroker; } };
} // namespace script

#endif // YASL_GUI_PAINTERPATH_H
