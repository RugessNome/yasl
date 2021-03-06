// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_GUI_WINDOW_H
#define YASL_GUI_WINDOW_H

#include "yasl/common/qobject-values.h"
#include "yasl/common/types.h"

#include <QWindow>

namespace script {
template<> struct make_type_helper<QWindow> { inline static script::Type get() { return script::Type::QWindow; } };
namespace details { template<> struct tag_resolver<QWindow> { typedef qobject_tag tag_type; }; }
template<> struct make_type_helper<QWindow*> { inline static script::Type get() { return script::Type::QWindowStar; } };
template<> struct make_type_helper<QWindow::AncestorMode> { inline static script::Type get() { return script::Type::QWindowAncestorMode; } };
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
template<> struct make_type_helper<QWindow::Visibility> { inline static script::Type get() { return script::Type::QWindowVisibility; } };
#endif
} // namespace script

#endif // YASL_GUI_WINDOW_H
