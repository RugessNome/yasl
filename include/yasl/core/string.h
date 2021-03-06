// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_STRING_H
#define YASL_CORE_STRING_H

#include "yasl/common/types.h"
#include "yasl/common/proxy.h"

#include <QStringList>

namespace script 
{
template<> struct make_type_helper<Proxy<QString>> { inline static script::Type get() { return script::Type::ProxyQString; } };
template<> struct make_type_helper<QList<QString>> { inline static script::Type get() { return script::Type::QListQString; } };
template<> struct make_type_helper<QList<QString>::iterator> { inline static script::Type get() { return script::Type::QListQStringIterator; } };
template<> struct make_type_helper<QList<QString>::const_iterator> { inline static script::Type get() { return script::Type::QListQStringConstIterator; } };
template<> struct make_type_helper<QStringList> { inline static script::Type get() { return script::Type::QStringList; } };
}

#endif // YASL_CORE_STRING_H
