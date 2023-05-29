#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "graphobj.h"


class Rectangle :public GraphObj
{
private:
    bool outlined;
public:
    Rectangle(QPoint startPoint_, QColor color_, bool outlined_);
    void update(QPoint point) override;
    void paint(QPainter *painter) override;
    bool tooSmall() override;
};

#endif // RECTANGLE_H
