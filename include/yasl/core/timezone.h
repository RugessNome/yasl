// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_TIMEZONE_H
#define YASL_CORE_TIMEZONE_H

#include "yasl/binding/types.h"

#include <script/namespace.h>

#include <QTimeZone>

void register_timezone_class(script::Namespace n);

namespace binding
{
template<> struct make_type_t<QTimeZone> { inline static script::Type get() { return script::Type::QTimeZone; } };
template<> struct make_type_t<QTimeZone::NameType> { inline static script::Type get() { return script::Type::QTimeZoneNameType; } };
template<> struct make_type_t<QTimeZone::TimeType> { inline static script::Type get() { return script::Type::QTimeZoneTimeType; } };
template<> struct make_type_t<decltype(QTimeZone::MinUtcOffsetSecs)> { inline static script::Type get() { return script::Type::QTimeZoneMinUtcOffsetSecs; } };
} // namespace binding

#endif // YASL_CORE_TIMEZONE_H
