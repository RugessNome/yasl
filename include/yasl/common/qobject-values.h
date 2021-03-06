// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_COMMONS_QOBJECT_VALUES_H
#define YASL_COMMONS_QOBJECT_VALUES_H

#include "yasl/common/values.h"
#include "yasl/common/ref.h"

#include <QObject>

namespace script
{

struct qobject_tag {};

template<typename T>
struct make_value_t<T, qobject_tag>
{
  static script::Value make(T *input, script::Engine *e)
  {
    return make_ref(e, make_type<T*>(), input);
  }
};

template<typename T>
struct qobject_storage : pointer_storage<T> { };

template<typename T>
struct storage_type_default_impl<T, qobject_tag> : qobject_storage<T> { };

template<typename T>
struct get_helper<T, qobject_tag>
{
  typedef T* type;

  static T* get(const script::Value & val)
  {
    return qobject_cast<T*>(val.toQObject());
  }
};

} // namespace script

#endif // YASL_COMMONS_QOBJECT_VALUES_H
