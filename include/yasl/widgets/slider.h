// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_WIDGETS_SLIDER_H
#define YASL_WIDGETS_SLIDER_H

#include "yasl/binding/types.h"
#include "yasl/core/qobject-binding.h"

#include <QSlider>

namespace binding {
template<> struct make_type_t<QSlider> { inline static script::Type get() { return script::Type::QSlider; } };
template<> struct tag_resolver<QSlider> { typedef qobject_tag tag_type; };
template<> struct make_type_t<QSlider::TickPosition> { inline static script::Type get() { return script::Type::QSliderTickPosition; } };
} // namespace binding

#endif // YASL_WIDGETS_SLIDER_H