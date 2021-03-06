// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_GUI_SCREEN_H
#define YASL_GUI_SCREEN_H

#include "yasl/common/qobject-values.h"
#include "yasl/common/types.h"

#include <QScreen>

namespace script {
template<> struct make_type_helper<QScreen> { inline static script::Type get() { return script::Type::QScreen; } };
namespace details { template<> struct tag_resolver<QScreen> { typedef qobject_tag tag_type; }; }
} // namespace script

#endif // YASL_GUI_SCREEN_H
