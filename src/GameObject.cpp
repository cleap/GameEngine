#include "gameobject.h"

GameObject::GameObject(void)
{
    xCor = 0.0f;
    yCor = 0.0f;
    width = 50.0f;
    height = 50.0f;
}

GameObject::GameObject(float x, float y, float width, float height)
{
    xCor = x;
    yCor = y;
    this->width = width;
    this->height = height;
}

void GameObject::move(float xVel, float yVel, float delta)
{
    GameObject temp(xCor + xVel*delta, yCor + yVel*delta, width, height);
    xCor += xVel * delta;
    yCor += yVel * delta;
}

/*
static bool GameObject::isCollision(GameObject go1, GameObject go2)
{
    return (go1.getX() >= go2.getX() || (go1.getX() + go1.getWidth()) <= (go2.getX() + go2.getWidth())) &&
           (go1.getY() >= go2.getY() || (go1.getY() + go1.getHeight()) <= (go2.getY() + go2.getHeight()));
}
*/
