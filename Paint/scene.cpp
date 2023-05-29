#include "scene.h"

Scene::Scene()
{

}

void Scene::addObj(GraphObj* Obj)
{
    allShapes.push_back(Obj);
}

void Scene::display(QPainter *painter)
{
    for(GraphObj *obj : allShapes)
    {
        obj->paint(painter);
    }
}

void Scene::deleteIfTooSmall()
{
    GraphObj* obj = allShapes.back();

    if(obj->tooSmall())
        allShapes.pop_back();

    //delete obj;
}

GraphObj* Scene::getLastObj()
{
    return allShapes.back();
}

void Scene::clear()
{
    allShapes.clear();
}
