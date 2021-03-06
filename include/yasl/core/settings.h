// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_SETTINGS_H
#define YASL_CORE_SETTINGS_H

#include "yasl/common/qobject-values.h"
#include "yasl/common/types.h"

#include <QSettings>

namespace script {
template<> struct make_type_helper<QSettings> { inline static script::Type get() { return script::Type::QSettings; } };
namespace details { template<> struct tag_resolver<QSettings> { typedef qobject_tag tag_type; }; }
template<> struct make_type_helper<QSettings::Format> { inline static script::Type get() { return script::Type::QSettingsFormat; } };
template<> struct make_type_helper<QSettings::Scope> { inline static script::Type get() { return script::Type::QSettingsScope; } };
template<> struct make_type_helper<QSettings::Status> { inline static script::Type get() { return script::Type::QSettingsStatus; } };
} // namespace script

#endif // YASL_CORE_SETTINGS_H
