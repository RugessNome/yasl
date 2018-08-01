// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_GUI_PIXMAP_H
#define YASL_GUI_PIXMAP_H

#include "yasl/binding/types.h"

#include <QPixmap>

namespace binding {
template<> struct make_type_t<QPixmap> { inline static script::Type get() { return script::Type::QPixmap; } };
} // namespace binding

#endif // YASL_GUI_PIXMAP_H