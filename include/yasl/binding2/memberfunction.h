// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_BINDING2_MEMBERFUNCTION_H
#define YASL_BINDING2_MEMBERFUNCTION_H

#include "yasl/binding2/values.h"

#include "yasl/binding2/member_wrapper.h"

#include <script/class.h>
#include <script/functionbuilder.h>

namespace script
{

namespace bind
{

/* Non-void non-static non-const member functions */

template<typename T, typename R, R(T::*F)()>
script::FunctionBuilder member_function(Class & cla, std::string && name)
{
  return cla.newMethod(std::move(name), member_wrapper_t<decltype(F), F>::wrap)
    .returns(make_return_type<R>());
}

template<typename T, typename R, typename A1, R(T::*F)(A1)>
script::FunctionBuilder member_function(Class & cla, std::string && name)
{
  return cla.newMethod(std::move(name), member_wrapper_t<decltype(F), F>::wrap)
    .returns(make_return_type<R>())
    .params(make_type<A1>());
}

template<typename T, typename R, typename A1, typename A2, R(T::*F)(A1, A2)>
script::FunctionBuilder member_function(Class & cla, std::string && name)
{
  return cla.newMethod(std::move(name), member_wrapper_t<decltype(F), F>::wrap)
    .returns(make_return_type<R>())
    .params(make_type<A1>(), make_type<A2>());
}

template<typename T, typename R, typename A1, typename A2, typename A3, R(T::*F)(A1, A2, A3)>
script::FunctionBuilder member_function(Class & cla, std::string && name)
{
  return cla.newMethod(std::move(name), member_wrapper_t<decltype(F), F>::wrap)
    .returns(make_return_type<R>())
    .params(make_type<A1>(), make_type<A2>(), make_type<A3>());
}

template<typename T, typename R, typename A1, typename A2, typename A3, typename A4, R(T::*F)(A1, A2, A3, A4)>
script::FunctionBuilder member_function(Class & cla, std::string && name)
{
  return cla.newMethod(std::move(name), member_wrapper_t<decltype(F), F>::wrap)
    .returns(make_return_type<R>())
    .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>());
}

template<typename T, typename R, typename A1, typename A2, typename A3, typename A4, typename A5, R(T::*F)(A1, A2, A3, A4, A5)>
script::FunctionBuilder member_function(Class & cla, std::string && name)
{
  return cla.newMethod(std::move(name), member_wrapper_t<decltype(F), F>::wrap)
    .returns(make_return_type<R>())
    .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>(), make_type<A5>());
}

/* Non-void non-static const member functions */

template<typename T, typename R, R(T::*F)()const>
script::FunctionBuilder member_function(Class & cla, std::string && name)
{
  return cla.newMethod(std::move(name), member_wrapper_t<decltype(F), F>::wrap)
    .setConst()
    .returns(make_return_type<R>());
}

template<typename T, typename R, typename A1, R(T::*F)(A1)const>
script::FunctionBuilder member_function(Class & cla, std::string && name)
{
  return cla.newMethod(std::move(name), member_wrapper_t<decltype(F), F>::wrap)
    .setConst()
    .returns(make_return_type<R>())
    .params(make_type<A1>());
}

template<typename T, typename R, typename A1, typename A2, R(T::*F)(A1, A2)const>
script::FunctionBuilder member_function(Class & cla, std::string && name)
{
  return cla.newMethod(std::move(name), member_wrapper_t<decltype(F), F>::wrap)
    .setConst()
    .returns(make_return_type<R>())
    .params(make_type<A1>(), make_type<A2>());
}

template<typename T, typename R, typename A1, typename A2, typename A3, R(T::*F)(A1, A2, A3)const>
script::FunctionBuilder member_function(Class & cla, std::string && name)
{
  return cla.newMethod(std::move(name), member_wrapper_t<decltype(F), F>::wrap)
    .setConst()
    .returns(make_return_type<R>())
    .params(make_type<A1>(), make_type<A2>(), make_type<A3>());
}

template<typename T, typename R, typename A1, typename A2, typename A3, typename A4, R(T::*F)(A1, A2, A3, A4)const>
script::FunctionBuilder member_function(Class & cla, std::string && name)
{
  return cla.newMethod(std::move(name), member_wrapper_t<decltype(F), F>::wrap)
    .setConst()
    .returns(make_return_type<R>())
    .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>());
}

template<typename T, typename R, typename A1, typename A2, typename A3, typename A4, typename A5, R(T::*F)(A1, A2, A3, A4, A5)const>
script::FunctionBuilder member_function(Class & cla, std::string && name)
{
  return cla.newMethod(std::move(name), member_wrapper_t<decltype(F), F>::wrap)
    .setConst()
    .returns(make_return_type<R>())
    .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>(), make_type<A5>());
}


/* void functions */

template<typename T, void(T::*F)()>
script::FunctionBuilder void_member_function(Class & cla, std::string && name)
{
  return cla.newMethod(std::move(name), void_member_wrapper_t<decltype(F), F>::wrap);
}

template<typename T, typename A1, void(T::*F)(A1)>
script::FunctionBuilder void_member_function(Class & cla, std::string && name)
{
  return cla.newMethod(std::move(name), void_member_wrapper_t<decltype(F), F>::wrap)
    .params(make_type<A1>());
}

template<typename T, typename A1, typename A2, void(T::*F)(A1, A2)>
script::FunctionBuilder void_member_function(Class & cla, std::string && name)
{
  return cla.newMethod(std::move(name), void_member_wrapper_t<decltype(F), F>::wrap)
    .params(make_type<A1>(), make_type<A2>());
}

template<typename T, typename A1, typename A2, typename A3, void(T::*F)(A1, A2, A3)>
script::FunctionBuilder void_member_function(Class & cla, std::string && name)
{
  return cla.newMethod(std::move(name), void_member_wrapper_t<decltype(F), F>::wrap)
    .params(make_type<A1>(), make_type<A2>(), make_type<A3>());
}

template<typename T, typename A1, typename A2, typename A3, typename A4, void(T::*F)(A1, A2, A3, A4)>
script::FunctionBuilder void_member_function(Class & cla, std::string && name)
{
  return cla.newMethod(std::move(name), void_member_wrapper_t<decltype(F), F>::wrap)
    .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>());
}

template<typename T, typename A1, typename A2, typename A3, typename A4, typename A5, void(T::*F)(A1, A2, A3, A4, A5)>
script::FunctionBuilder void_member_function(Class & cla, std::string && name)
{
  return cla.newMethod(std::move(name), void_member_wrapper_t<decltype(F), F>::wrap)
    .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>(), make_type<A5>());
}


/* void const functions */

template<typename T, void(T::*F)()const>
script::FunctionBuilder void_member_function(Class & cla, std::string && name)
{
  return cla.newMethod(std::move(name), const_void_member_wrapper_t<decltype(F), F>::wrap)
    .setConst();
}

template<typename T, typename A1, void(T::*F)(A1)const>
script::FunctionBuilder void_member_function(Class & cla, std::string && name)
{
  return cla.newMethod(std::move(name), const_void_member_wrapper_t<decltype(F), F>::wrap)
    .setConst()
    .params(make_type<A1>());
}

template<typename T, typename A1, typename A2, void(T::*F)(A1, A2)const>
script::FunctionBuilder void_member_function(Class & cla, std::string && name)
{
  return cla.newMethod(std::move(name), const_void_member_wrapper_t<decltype(F), F>::wrap)
    .setConst()
    .params(make_type<A1>(), make_type<A2>());
}

template<typename T, typename A1, typename A2, typename A3, void(T::*F)(A1, A2, A3)const>
script::FunctionBuilder void_member_function(Class & cla, std::string && name)
{
  return cla.newMethod(std::move(name), const_void_member_wrapper_t<decltype(F), F>::wrap)
    .setConst()
    .params(make_type<A1>(), make_type<A2>(), make_type<A3>());
}

template<typename T, typename A1, typename A2, typename A3, typename A4, void(T::*F)(A1, A2, A3, A4)const>
script::FunctionBuilder void_member_function(Class & cla, std::string && name)
{
  return cla.newMethod(std::move(name), const_void_member_wrapper_t<decltype(F), F>::wrap)
    .setConst()
    .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>());
}

template<typename T, typename A1, typename A2, typename A3, typename A4, typename A5, void(T::*F)(A1, A2, A3, A4, A5)const>
script::FunctionBuilder void_member_function(Class & cla, std::string && name)
{
  return cla.newMethod(std::move(name), const_void_member_wrapper_t<decltype(F), F>::wrap)
    .setConst()
    .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>(), make_type<A5>());
}

} // namespace bind

} // namespace script

#endif // YASL_BINDING2_MEMBERFUNCTION_H
