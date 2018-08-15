// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_META_HEADERFILE_H
#define YASL_META_HEADERFILE_H

#include <QFileInfo>
#include <QMap>

#include "project/type.h"

class QTextStream;

class Includes
{
public:
  QMap<QString, bool> data;

  void insert(const QString & inc);
  void remove(const QString & inc);
  QStringList get() const;
  inline bool isEmpty() const { return data.isEmpty(); }
};

class HeaderFile
{
public:
  QFileInfo file;

  QString moduleName;
  Includes bindingIncludes;
  Includes generalIncludes;

  QMap<QString, Type> types;

public:
  HeaderFile();

  void write();

  static void writeCopyrightMessage(QTextStream & out);
  static void writeInclude(QTextStream & out, const QString & inc);

protected:
  QStringList generateBindingDefinitions();
};

#endif // YASL_META_HEADERFILE_H
