#ifndef FREEHAND_H
#define FREEHAND_H
#include "graphobj.h"

class FreeHand : public GraphObj
{
private:
    const int LIMIT = 5000;
    QPoint points[5000];
    int index = 0;
public:
    FreeHand(QPoint startPoint_, QColor color_);
    void update(QPoint point) override;
    void paint(QPainter *painter) override;
    bool tooSmall() override;
};

#endif // FREEHAND_H
