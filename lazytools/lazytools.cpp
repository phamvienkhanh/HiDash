#include "lazytools.h"

void LazyTools::callback(QJSValue calbcak)
{
    if(calbcak.isCallable()) {
        calbcak.call();
    }
}

LazyTools::LazyTools(QObject *parent)
    : QObject(parent)
{
}

LazyTools::~LazyTools()
{
}

