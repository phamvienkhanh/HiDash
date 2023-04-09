#ifndef LAZYTOOLS_H
#define LAZYTOOLS_H

#include <QObject>
#include <QQmlEngine>

class LazyTools : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON

public:
    Q_INVOKABLE void callback(QJSValue calbcak);

public:
    explicit LazyTools(QObject *parent = nullptr);
    ~LazyTools() override;
};

#endif // LAZYTOOLS_H
