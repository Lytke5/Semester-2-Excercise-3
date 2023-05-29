#ifndef GRAPHOBJ_H
#define GRAPHOBJ_H
#include <QPainter>


class GraphObj
{
protected:
    QPoint startPoint;
    QPoint endPoint;
    QColor color;
public:
    GraphObj();
    void virtual update(QPoint point);
    void virtual paint(QPainter *painter);
    bool virtual tooSmall();
};

#endif // GRAPHOBJ_H
