// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_GUI_NEW_WIDGET_H
#define YASL_GUI_NEW_WIDGET_H

#include "yasl/widgets/widget.h"

#include <script/function.h>

class Widget : public QWidget
{
  Q_OBJECT
public:
  Widget();

public:
  bool QWidgetEvent(QEvent *e);
  void QWidgetCloseEvent(QCloseEvent *e);
  void QWidgetEnterEvent(QEvent *e);
  void QWidgetHideEvent(QHideEvent *e);
  void QWidgetKeyPressEvent(QKeyEvent *e);
  void QWidgetKeyReleaseEvent(QKeyEvent *e);
  void QWidgetLeaveEvent(QEvent *e);
  void QWidgetMouseDoubleClickEvent(QMouseEvent *e);
  void QWidgetMouseMoveEvent(QMouseEvent *e);
  void QWidgetMousePressEvent(QMouseEvent *e);
  void QWidgetMouseReleaseEvent(QMouseEvent *e);
  void QWidgetMoveEvent(QMoveEvent *e);
  void QWidgetPaintEvent(QPaintEvent *e);
  void QWidgetResizeEvent(QResizeEvent *e);
  void QWidgetShowEvent(QShowEvent *e);
  void QWidgetWheelEvent(QWheelEvent *e);

private:
  script::Value self() const;

private:
  bool event(QEvent *e) override;
  void closeEvent(QCloseEvent *e) override;
  void enterEvent(QEvent *e) override;
  void hideEvent(QHideEvent *e) override;
  void keyPressEvent(QKeyEvent *e) override;
  void keyReleaseEvent(QKeyEvent *e) override;
  void leaveEvent(QEvent *e) override;
  void mouseDoubleClickEvent(QMouseEvent *e) override;
  void mouseMoveEvent(QMouseEvent *e) override;
  void mousePressEvent(QMouseEvent *e) override;
  void mouseReleaseEvent(QMouseEvent *e) override;
  void moveEvent(QMoveEvent *e) override;
  void paintEvent(QPaintEvent *e) override;
  void resizeEvent(QResizeEvent *e) override;
  void showEvent(QShowEvent *e) override;
  void wheelEvent(QWheelEvent *e) override;

public:
  struct Callbacks
  {
    script::Function close;
    script::Function enter;
    script::Function event;
    script::Function hide;
    script::Function keyPress;
    script::Function keyRelease;
    script::Function leave;
    script::Function mouseDoubleClick;
    script::Function mouseMove;
    script::Function mousePress;
    script::Function mouseRelease;
    script::Function move;
    script::Function paint;
    script::Function resize;
    script::Function show;
    script::Function wheel;
  };
  Callbacks mCallbacks;
};


namespace script
{
template<> struct make_type_helper<Widget*> { inline static script::Type get() { return script::Type::QWidgetStar; } };
template<> inline Widget* value_cast<Widget*>(const script::Value & val)
{
  return qobject_cast<Widget*>(val.toQObject());
}
} // namespace script

#endif // YASL_GUI_NEW_WIDGET_H
