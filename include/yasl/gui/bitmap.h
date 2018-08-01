// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_GUI_BITMAP_H
#define YASL_GUI_BITMAP_H

#include "yasl/binding/types.h"

#include <QBitmap>

namespace binding {
template<> struct make_type_t<QBitmap> { inline static script::Type get() { return script::Type::QBitmap; } };
} // namespace binding

#endif // YASL_GUI_BITMAP_H