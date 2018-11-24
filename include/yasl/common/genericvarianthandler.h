// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_COMMONS_VARIANT_H
#define YASL_COMMONS_VARIANT_H

#include "yasl/common/variant.h"

#include "yasl/common/values.h"

#include <QVariant>

namespace yasl
{

template<QMetaType::Type MT, script::Type ST, typename T>
class GenericVariantHandler : public VariantHandler
{
public:
  GenericVariantHandler() = default;
  ~GenericVariantHandler() = default;

  script::Type script_type() const override { return ST; }
  QVariant::Type qt_type() const override { return MT; }

  QVariant to_qvariant(const script::Value & v) override
  {
    return QVariant::fromValue<T>(script::value_cast<T>(v));
  }

  script::Value from_qvariant(script::Engine *e, const QVariant & v) override
  {
    return script::make_value(v.value<T>(), e);
  }
};

} // namespace yasl

#endif // YASL_COMMONS_VARIANT_H
