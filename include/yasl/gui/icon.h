// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_GUI_ICON_H
#define YASL_GUI_ICON_H

#include "yasl/common/types.h"

#include <QIcon>

namespace script {
template<> struct make_type_helper<QIcon> { inline static script::Type get() { return script::Type::QIcon; } };
template<> struct make_type_helper<QIcon::Mode> { inline static script::Type get() { return script::Type::QIconMode; } };
template<> struct make_type_helper<QIcon::State> { inline static script::Type get() { return script::Type::QIconState; } };
} // namespace script

#endif // YASL_GUI_ICON_H
