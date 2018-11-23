// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/radiobutton.h"

#include "yasl/binding/default_arguments.h"
#include "yasl/binding/namespace.h"
#include "yasl/binding/newfunction.h"
#include "yasl/binding/qclass.h"

#include "yasl/widgets/widget.h"

#include <script/classbuilder.h>

static void register_radio_button_class(script::Namespace ns)
{
  using namespace script;

  Class radio_button = ns.newClass("RadioButton").setId(script::Type::QRadioButton)
    .setBase(script::Type::QAbstractButton).get();


  // QRadioButton(QWidget *);
  bind::constructor<QRadioButton, QWidget *>(radio_button)
    .apply(bind::default_arguments((QWidget*)nullptr)).create();
  // QRadioButton(const QString &, QWidget *);
  bind::constructor<QRadioButton, const QString &, QWidget *>(radio_button)
    .apply(bind::default_arguments((QWidget*)nullptr)).create();
  // ~QRadioButton();
  bind::destructor<QRadioButton>(radio_button).create();

  bind::link(radio_button, &QRadioButton::staticMetaObject);
}


void register_radiobutton_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_radio_button_class(ns);

  // QRadioButton& newRadioButton(QWidget*);
  bind::new_function<QRadioButton, QWidget*>(ns, "newRadioButton");
  // QRadioButton& newRadioButton(const QString&, QWidget*);
  bind::new_function<QRadioButton, const QString&, QWidget*>(ns, "newRadioButton");
}

