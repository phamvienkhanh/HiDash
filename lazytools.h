#ifndef LAZYTOOLS_H
#define LAZYTOOLS_H

#include <QtQuick/QQuickPaintedItem>

class LazyTools : public QQuickPaintedItem
{
    Q_OBJECT
    QML_ELEMENT
        Q_DISABLE_COPY(LazyTools)
        public:
                 explicit LazyTools(QQuickItem *parent = nullptr);
    void paint(QPainter *painter) override;
    ~LazyTools() override;
};

#endif // LAZYTOOLS_H
