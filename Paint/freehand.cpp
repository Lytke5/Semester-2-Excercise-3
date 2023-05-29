#include <cmath>
#include "freehand.h"

FreeHand::FreeHand(QPoint startPoint_, QColor color_)
{
    points[0] = startPoint_;
    color = color_;
}

void FreeHand::update(QPoint point)
{
    if(index <= LIMIT)
        points[++index] = point;
}

void FreeHand::paint(QPainter *painter)
{
    painter->setPen(QPen(color, 2));
    painter->drawPolyline(points, index);
}

bool FreeHand::tooSmall()
{
    int distance = 0;
    for(int i  = 1; i <= index; i++)
    {
        float c2 = pow(points[i].toPointF().x()-points[i-1].toPointF().x(),2) +
                   pow(points[i].toPointF().y()-points[i-1].toPointF().y(),2);

        distance += sqrt(c2);

        if(distance > 2)
            return false;
    }

    return true;
}
