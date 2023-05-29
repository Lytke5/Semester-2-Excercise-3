#ifndef SCENE_H
#define SCENE_H
#include <QPainter>
#include "GraphObj.h"


class Scene
{
private:
    std::vector <GraphObj*> allShapes;
public:
    Scene();
    void addObj(GraphObj* Obj);
    void display(QPainter *painter);
    void deleteIfTooSmall();
    GraphObj* getLastObj();
    void clear();
};

#endif // SCENE_H
