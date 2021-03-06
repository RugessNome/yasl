// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_COMMONS_PROXY_H
#define YASL_COMMONS_PROXY_H

#include "yasl/common/types.h"

#include <script/classtemplatenativebackend.h>

namespace script
{

class Namespace;

template<typename T>
struct Proxy
{
  T *value;

  Proxy(T *val) : value(val) { }


  T & get() { return *value; }
  operator T &() { return get(); }
  
  void operator=(const T & val) { *value = val; }
};

template<> struct make_type_helper<Proxy<bool>> { inline static script::Type get() { return script::Type::Proxybool; } };
template<> struct make_type_helper<Proxy<char>> { inline static script::Type get() { return script::Type::Proxychar; } };
template<> struct make_type_helper<Proxy<int>> { inline static script::Type get() { return script::Type::Proxyint; } };
template<> struct make_type_helper<Proxy<float>> { inline static script::Type get() { return script::Type::Proxyfloat; } };
template<> struct make_type_helper<Proxy<double>> { inline static script::Type get() { return script::Type::Proxydouble; } };

void register_proxy_template(script::Namespace ns);

class ProxyTemplate : public ClassTemplateNativeBackend
{
  Class instantiate(ClassTemplateInstanceBuilder& builder) override;
};

} // namespace script

#endif // YASL_COMMONS_PROXY_H
