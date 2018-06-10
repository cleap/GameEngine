#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

class GameObject
{
private:
    float xCor, yCor, width, height;
public:
    GameObject(void);
    GameObject(float x, float y, float width, float height);
    void move(float xVel, float yVel, float delta);
    /*static bool isCollision(GameObject go1, GameObject go2);*/
    float getX(void) { return xCor; }
    float getY(void) { return yCor; }
    float getWidth(void) { return width; }
    float getHeight(void) { return height; }
};

#endif
