// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_WIDGETS_LINEEDIT_H
#define YASL_WIDGETS_LINEEDIT_H

#include "yasl/common/qobject-values.h"
#include "yasl/common/types.h"

#include <QLineEdit>

namespace script {
template<> struct make_type_helper<QLineEdit> { inline static script::Type get() { return script::Type::QLineEdit; } };
namespace details { template<> struct tag_resolver<QLineEdit> { typedef qobject_tag tag_type; }; }
#if (QT_VERSION >= QT_VERSION_CHECK(5, 2, 0))
template<> struct make_type_helper<QLineEdit::ActionPosition> { inline static script::Type get() { return script::Type::QLineEditActionPosition; } };
#endif
template<> struct make_type_helper<QLineEdit::EchoMode> { inline static script::Type get() { return script::Type::QLineEditEchoMode; } };
} // namespace script

#endif // YASL_WIDGETS_LINEEDIT_H
