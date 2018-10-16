// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/cursor.h"

#include "yasl/binding/class.h"
#include "yasl/binding/namespace.h"

#include "yasl/core/datastream.h"
#include "yasl/core/enums.h"
#include "yasl/core/point.h"
#include "yasl/gui/bitmap.h"
#include "yasl/gui/cursor.h"
#include "yasl/gui/pixmap.h"

#include <script/classbuilder.h>

static void register_cursor_class(script::Namespace ns)
{
  using namespace script;

  Class cursor = ns.Class("Cursor").setId(script::Type::QCursor).get();

  binding::Class<QCursor> binder{ cursor };

  // QCursor();
  binder.ctors().add_default();
  // QCursor(Qt::CursorShape);
  binder.ctors().ctor<Qt::CursorShape>().create();
  // QCursor(const QBitmap &, const QBitmap &, int, int);
  binder.ctors().ctor<const QBitmap &, const QBitmap &, int, int>().create();
  // QCursor(const QPixmap &, int, int);
  binder.ctors().ctor<const QPixmap &, int, int>().create();
  // QCursor(const QCursor &);
  binder.ctors().ctor<const QCursor &>().create();
  // ~QCursor();
  binder.add_dtor();
  // QCursor & operator=(const QCursor &);
  binder.operators().assign<const QCursor &>();
  // QCursor(QCursor &&);
  binder.ctors().ctor<QCursor &&>().create();
  // QCursor & operator=(QCursor &&);
  binder.operators().assign<QCursor &&>();
  // void swap(QCursor &);
  binder.void_fun<QCursor &, &QCursor::swap>("swap").create();
  // Qt::CursorShape shape() const;
  binder.fun<Qt::CursorShape, &QCursor::shape>("shape").create();
  // void setShape(Qt::CursorShape);
  binder.void_fun<Qt::CursorShape, &QCursor::setShape>("setShape").create();
  // const QBitmap * bitmap() const;
  /// TODO: const QBitmap * bitmap() const;
  // const QBitmap * mask() const;
  /// TODO: const QBitmap * mask() const;
  // QPixmap pixmap() const;
  binder.fun<QPixmap, &QCursor::pixmap>("pixmap").create();
  // QPoint hotSpot() const;
  binder.fun<QPoint, &QCursor::hotSpot>("hotSpot").create();
  // static QPoint pos();
  binder.static_fun<QPoint, &QCursor::pos>("pos").create();
  // static QPoint pos(const QScreen *);
  /// TODO: static QPoint pos(const QScreen *);
  // static void setPos(int, int);
  binder.static_void_fun<int, int, &QCursor::setPos>("setPos").create();
  // static void setPos(QScreen *, int, int);
  /// TODO: static void setPos(QScreen *, int, int);
  // static void setPos(const QPoint &);
  binder.static_void_fun<const QPoint &, &QCursor::setPos>("setPos").create();
  // static void setPos(QScreen *, const QPoint &);
  /// TODO: static void setPos(QScreen *, const QPoint &);
}


void register_cursor_file(script::Namespace gui)
{
  using namespace script;

  Namespace ns = gui;

  register_cursor_class(ns);
  binding::Namespace binder{ ns };

  // void swap(QCursor &, QCursor &);
  binder.void_fun<QCursor &, QCursor &, &swap>("swap").create();
  // bool operator==(const QCursor &, const QCursor &);
  binder.operators().eq<const QCursor &, const QCursor &>();
  // bool operator!=(const QCursor &, const QCursor &);
  binder.operators().neq<const QCursor &, const QCursor &>();
  // QDataStream & operator<<(QDataStream &, const QCursor &);
  binder.operators().put_to<QDataStream &, const QCursor &>();
  // QDataStream & operator>>(QDataStream &, QCursor &);
  binder.operators().read_from<QDataStream &, QCursor &>();
  // QDebug operator<<(QDebug, const QCursor &);
  /// TODO: QDebug operator<<(QDebug, const QCursor &);
}

