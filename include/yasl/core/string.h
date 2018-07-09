// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_STRING_H
#define YASL_CORE_STRING_H

#include "yasl/binding/types.h"
#include "yasl/utils/ptr.h"

#include <QStringList>

namespace binding
{

template<> struct make_type_t<Ptr<QString>> { inline static script::Type get() { return script::Type::PtrQString; } };
template<> struct make_type_t<QList<QString>> { inline static script::Type get() { return script::Type::QListQString; } };
template<> struct make_type_t<QStringList> { inline static script::Type get() { return script::Type::QStringList; } };

} // namespace binding

#endif // YASL_CORE_STRING_H
