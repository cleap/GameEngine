#include "gameobject.h"

GameObject::GameObject(void)
{
    xCor = 0.0f;
    yCor = 0.0f;
    width = 200.0f;
    height = 200.0f;
}

GameObject::GameObject(float x, float y, float width, float height)
{
    xCor = x;
    yCor = y;
    this->width = width;
    this->height = height;
}
