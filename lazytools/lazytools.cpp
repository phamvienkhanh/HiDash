#include "lazytools.h"

#include <QTimerEvent>

void LazyTools::delayCall(qint32 ms, QJSValue callback)
{
    _delayCalls[startTimer(ms)] = callback;
}

LazyTools::LazyTools(QObject* parent)
    : QObject(parent)
{
}

LazyTools::~LazyTools()
{
}

void LazyTools::timerEvent(QTimerEvent* event)
{
    qint32 timerId = event->timerId();
    if(_delayCalls.contains(timerId)) {
        auto callback = _delayCalls.take(timerId);
        if(callback.isCallable()) {
            callback.call();
        }
    }
}
