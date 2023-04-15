#include "lazytools.h"

#include <QTimerEvent>

void LazyTools::delay(qint32 ms, QJSValue callback)
{
    _delayCalls[startTimer(ms)] = callback;
}

DebounceFunction* LazyTools::debounce(QObject* parent, QJSValue callback, qint32 msWait, QJSValue options)
{
    DebounceFunction::InitParams params;
    params.parent = parent;
    params.msWait = msWait;
    params.callback = callback;

    auto maxWait = options.property("maxWait");
    auto leading = options.property("leading");
    auto trailing = options.property("trailing");

    if(maxWait.isNumber()) params.msMaxWait = maxWait.toUInt();
    if(leading.isBool()) params.isLeading = leading.toBool();
    if(trailing.isBool()) params.isTrailing = trailing.toBool();

    auto obj = new DebounceFunction(params);
    return obj;
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
    qDebug() << "LazyTools::timerEvent " << timerId;
    if(_delayCalls.contains(timerId)) {
        auto callback = _delayCalls.take(timerId);
        if(callback.isCallable()) {
            callback.call();
        }
        killTimer(timerId);
    }
}
