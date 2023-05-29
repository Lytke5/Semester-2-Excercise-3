#ifndef LINE_H
#define LINE_H
#include "graphobj.h"


class Line : public GraphObj
{
public:
    Line(QPoint startPoint_, QColor color_);
    void update(QPoint point) override;
    void paint(QPainter *painter) override;
    bool tooSmall() override;
};

#endif // LINE_H
