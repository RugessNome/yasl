// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_GUI_VECTOR2D_H
#define YASL_GUI_VECTOR2D_H

#include "yasl/common/types.h"

#include <QVector2D>

namespace script {
template<> struct make_type_helper<QVector2D> { inline static script::Type get() { return script::Type::QVector2D; } };
} // namespace script

#endif // YASL_GUI_VECTOR2D_H
