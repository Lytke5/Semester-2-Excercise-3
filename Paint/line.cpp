#include "line.h"

Line::Line(QPoint startPoint_, QColor color_)
{
    startPoint = startPoint_;
    endPoint = startPoint_;
    color = color_;
}

void Line::update(QPoint point)
{
    endPoint = point;
}

void Line::paint(QPainter *painter)
{
    painter->setPen(QPen(color, 2));
    painter->drawLine(startPoint, endPoint);
}

bool Line::tooSmall()
{
    float c2 = pow(endPoint.toPointF().x()-startPoint.toPointF().x(),2) +
               pow(endPoint.toPointF().y()-startPoint.toPointF().y(),2);

    if(c2 < 2)
        return true;

    return false;
}
