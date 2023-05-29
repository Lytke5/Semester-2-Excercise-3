#include "rectangle.h"


Rectangle::Rectangle(QPoint startPoint_, QColor color_, bool outlined_)
{
    startPoint = startPoint_;
    endPoint = startPoint_;
    color = color_;
    outlined = outlined_;
}

void Rectangle::update(QPoint point)
{
    endPoint = point;
}

void Rectangle::paint(QPainter *painter)
{
    if (!outlined)
    {
        painter->setPen(Qt::NoPen);
        painter->setBrush(color);
    }
    else
    {
        painter->setPen(QPen(color, 2));
        painter->setBrush(Qt::NoBrush);
    }

    int width = endPoint.x() - startPoint.x();
    int height = endPoint.y() - startPoint.y();

    painter->drawRect(startPoint.x(), startPoint.y(), width, height);
}

bool Rectangle::tooSmall()
{
    float c2 = endPoint.toPointF().x()-startPoint.toPointF().x() *
               endPoint.toPointF().y()-startPoint.toPointF().y();

    if(c2 < 0)
        c2 *= -1;

    if(c2 < 2)
        return true;

    return false;
}
