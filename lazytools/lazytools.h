#ifndef LAZYTOOLS_H
#define LAZYTOOLS_H

#include <QObject>
#include <QQmlEngine>

#include "debouncefunction.h"

class LazyTools : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON

public:
    Q_INVOKABLE void delay(qint32 ms, QJSValue callback);
    Q_INVOKABLE DebounceFunction* debounce(QObject* parent, QJSValue callback, qint32 msWait, QJSValue options);

public:
    explicit LazyTools(QObject *parent = nullptr);
    ~LazyTools() override;


protected:
    void timerEvent(QTimerEvent * event) override;

private:
    QHash<qint32, QJSValue> _delayCalls;
};

#endif // LAZYTOOLS_H
