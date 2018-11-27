// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_META_NODE_H
#define YASL_META_NODE_H

#include <QJsonObject>
#include <QMap>
#include <QSharedPointer>
#include <QStack>


class QtVersion
{
public:
  QtVersion()
    : major(0), minor(0), patch(0)
  { }

  QtVersion(const QtVersion &) = default;

  QtVersion(int ma, int mi, int pa = 0)
    : major(ma), minor(mi), patch(pa) {}

  char major;
  char minor;
  char patch;

  QString toString() const;
  static QtVersion fromString(const QString & str);

  inline bool isNull() const { return major == 0 && minor == 0 && patch == 0; }
};

namespace json
{
Qt::CheckState readCheckState(const QJsonObject & obj);
void writeCheckState(QJsonObject & obj, Qt::CheckState cs);
QtVersion readQtVersion(const QJsonObject & obj);
void writeQtVersion(QJsonObject & obj, QtVersion v);
} //  namespace json

class Node
{
public:
  Node(const QString & n, Qt::CheckState c = Qt::Checked);
  virtual ~Node() = default;

  template<typename T>
  bool is() const
  {
    return dynamic_cast<const T*>(this) != nullptr;
  }

  template<typename T>
  T & as()
  {
    return *dynamic_cast<T*>(this);
  }

  virtual void fillJson(QJsonObject & obj) const;
  QJsonObject toJson() const;
  static QSharedPointer<Node> fromJson(const QJsonObject & val);

  virtual QString display() const { return name; }
  virtual QString typeCode() const = 0;

  typedef QSharedPointer<Node>(*JsonDeserializer)(const QJsonObject &);
  static QMap<QString, JsonDeserializer> staticFactory;
  static void registerDeserializer(const QString & name, JsonDeserializer func);

  static QString nameQualification(const QStack<QSharedPointer<Node>> & nodes);

  QString name;
  Qt::CheckState checkState;
  QtVersion version;
};
typedef QSharedPointer<Node> NodeRef;

Q_DECLARE_METATYPE(QSharedPointer<Node>);


class NodeValue
{
public:
  NodeRef value;

  NodeValue();
  NodeValue(const NodeRef & val) : value(val) { }
  NodeValue(const NodeValue & ) = default;

  NodeValue & operator=(const NodeValue &) = default;
};

bool eq(const NodeRef & lhs, const NodeRef & rhs);
inline bool neq(const NodeRef & lhs, const NodeRef & rhs)
{
  return !eq(lhs, rhs);
}

#endif // YASL_META_NODE_H
