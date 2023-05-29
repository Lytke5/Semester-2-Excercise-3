#ifndef CANVAS_H
#define CANVAS_H

#include <QFrame>
#include <vector>
#include "Scene.h"

class Canvas : public QFrame
{
    Q_OBJECT

public:
    enum PrimitiveMode {
        NONE, FREE_HAND, CIRCLE, LINE, TRIANGLE, RECTANGLE, POLYGON
    };

    Canvas(QWidget *parent = 0);
    ~Canvas();

    QSize minimumSizeHint() const;
    QSize sizeHint() const;

    void clearCanvas(void);
    void setPrimitiveMode(int mode);
    void setCurrColor(QColor color);
    void setFillMode(bool outline);

protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private:
    bool dragging;
    bool isOutlined = false;
    PrimitiveMode type;
    QColor currColor;
    Scene myScene;

};

#endif // CANVAS_H
