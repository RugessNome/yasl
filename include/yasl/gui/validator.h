// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_GUI_VALIDATOR_H
#define YASL_GUI_VALIDATOR_H

#include "yasl/common/qobject-values.h"
#include "yasl/common/types.h"

#include <QValidator>

namespace script {
template<> struct make_type_helper<QDoubleValidator> { inline static script::Type get() { return script::Type::QDoubleValidator; } };
namespace details { template<> struct tag_resolver<QDoubleValidator> { typedef qobject_tag tag_type; }; }
template<> struct make_type_helper<QDoubleValidator::Notation> { inline static script::Type get() { return script::Type::QDoubleValidatorNotation; } };
template<> struct make_type_helper<QIntValidator> { inline static script::Type get() { return script::Type::QIntValidator; } };
namespace details { template<> struct tag_resolver<QIntValidator> { typedef qobject_tag tag_type; }; }
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
template<> struct make_type_helper<QRegularExpressionValidator> { inline static script::Type get() { return script::Type::QRegularExpressionValidator; } };
namespace details { template<> struct tag_resolver<QRegularExpressionValidator> { typedef qobject_tag tag_type; }; }
#endif
template<> struct make_type_helper<QValidator> { inline static script::Type get() { return script::Type::QValidator; } };
namespace details { template<> struct tag_resolver<QValidator> { typedef qobject_tag tag_type; }; }
template<> struct make_type_helper<QValidator::State> { inline static script::Type get() { return script::Type::QValidatorState; } };
} // namespace script

#endif // YASL_GUI_VALIDATOR_H
