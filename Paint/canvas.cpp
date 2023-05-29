#include <QPainter>
#include <QPainterPath>
#include <QMouseEvent>
#include <math.h>
#include "canvas.h"
#include "graphobj.h"
#include "line.h"
#include "Rectangle.h"
#include "Circle.h"
#include "FreeHand.h"


Canvas::Canvas(QWidget *parent)
    : QFrame(parent)
{
    setFrameStyle(QFrame::Box);
    setMouseTracking(true);

    type = NONE;
    dragging = false;
}

Canvas::~Canvas()
{
}

QSize Canvas::minimumSizeHint() const
{
    return QSize(200, 200);
}

QSize Canvas::sizeHint() const
{
    return QSize(640, 480);
}

void Canvas::clearCanvas(void)
{
    myScene.clear();
}

void Canvas::setPrimitiveMode(int mode)
{
    type = (Canvas::PrimitiveMode)mode;
}

void Canvas::setCurrColor(QColor color)
{
    currColor = color;
}

void Canvas::setFillMode(bool outline)
{
    isOutlined = outline;
}

void Canvas::paintEvent(QPaintEvent *event)
{
    QFrame::paintEvent(event);  // parent class draws border

    QPainter painter(this);

    // white background (inside parent's border)
    painter.fillRect(QRect(1, 1, width() - 2, height() - 2), Qt::white);

    myScene.display(&painter);
}

void Canvas::resizeEvent(QResizeEvent *event) 
{
    QFrame::resizeEvent(event);
}

void Canvas::mousePressEvent(QMouseEvent *event)
{
    if(type == NONE)
    {
        return;
    }

    if (event->button() == Qt::LeftButton) {
        dragging = true;

        // Mouse position given as follows
        QPoint currPos = event->pos();

        switch (type) {
        case LINE:
        {
            Line *newObj = new Line(currPos, currColor);
            myScene.addObj(newObj);
            break;
        }
        case RECTANGLE:
        {
            Rectangle *newObj = new Rectangle(currPos, currColor, isOutlined);
            myScene.addObj(newObj);
            break;
        }
        case CIRCLE:
        {
            Circle *newObj = new Circle(currPos, currColor, isOutlined);
            myScene.addObj(newObj);
            break;
        }
        case FREE_HAND:
        {
            FreeHand *newObj = new FreeHand(currPos, currColor);
            myScene.addObj(newObj);
            break;
        }
        default:
            break;
        }

        update();
    }
}

void Canvas::mouseMoveEvent(QMouseEvent *event)
{
    if ((event->buttons() & Qt::LeftButton) && dragging) {
        QPoint currPos = event->pos();
        GraphObj *obj = myScene.getLastObj();

        obj->update(currPos);

        update();
    }
}

void Canvas::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && dragging) {
        dragging = false;

        myScene.deleteIfTooSmall();

        update();
    }
}
