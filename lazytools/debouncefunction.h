#ifndef DEBOUNCEFUNCTION_H
#define DEBOUNCEFUNCTION_H

#include <QObject>
#include <QQmlEngine>

class DebounceFunction : public QObject
{
    Q_OBJECT

public:
    struct InitParams {
        QObject* parent = nullptr;
        QJSValue callback;
        quint32 msWait = 0;
        quint32 msMaxWait = 0;
        bool isLeading = false;
        bool isTrailing = true;
    };

    Q_INVOKABLE void call();

public:
    explicit DebounceFunction(const InitParams& params);
    ~DebounceFunction();

protected:
    void timerEvent(QTimerEvent* event);

private:
    void invokeCallback();

private:
    InitParams _params;
    qint32 _timeId = 0;
    qint64 _lastTimeCall = 0;

};

#endif // DEBOUNCEFUNCTION_H
