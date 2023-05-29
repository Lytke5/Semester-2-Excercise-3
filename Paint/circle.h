#ifndef CIRCLE_H
#define CIRCLE_H
#include "graphobj.h"


class Circle : public GraphObj
{
private:
    bool outlined;
public:
    Circle(QPoint startPoint_, QColor color_, bool outlined_);
    void update(QPoint point) override;
    void paint(QPainter *painter) override;
    bool tooSmall() override;
};

#endif // CIRCLE_H
