// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_WIDGETS_COLORDIALOG_H
#define YASL_WIDGETS_COLORDIALOG_H

#include "yasl/binding/types.h"
#include "yasl/core/qobject-binding.h"

#include <QColorDialog>

namespace binding {
template<> struct make_type_t<QColorDialog> { inline static script::Type get() { return script::Type::QColorDialog; } };
template<> struct tag_resolver<QColorDialog> { typedef qobject_tag tag_type; };
template<> struct make_type_t<QColorDialog::ColorDialogOption> { inline static script::Type get() { return script::Type::QColorDialogColorDialogOption; } };
template<> struct make_type_t<QColorDialog::ColorDialogOptions> { inline static script::Type get() { return script::Type::QColorDialogColorDialogOptions; } };
} // namespace binding

#endif // YASL_WIDGETS_COLORDIALOG_H
