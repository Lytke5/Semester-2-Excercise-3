#include "circle.h"

Circle::Circle(QPoint startPoint_, QColor color_, bool outlined_)
{
    startPoint = startPoint_;
    endPoint = startPoint_;
    color = color_;
    outlined = outlined_;
}

void Circle::update(QPoint point)
{
    endPoint = point;
}

void Circle::paint(QPainter *painter)
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

    QPoint radius = QPoint(endPoint.x()-startPoint.x(),endPoint.y()-startPoint.y());
    painter->drawEllipse(startPoint, radius.x(), radius.y());
}

bool Circle::tooSmall()
{
    float volume = 4/3 * 3.1415 * endPoint.x()-startPoint.x() * endPoint.y()-startPoint.y();
    if(volume < 0)
        volume *= -1;

    if(volume < 2)
        return true;

    return false;
}
