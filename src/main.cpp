#include <iostream>
#include <array>
#include "consts.h"
#include "gameobject.h"
#include "graphics.h"
#include "time.h"

int main(int argc, char** argv)
{
    Graphics g;
    GameObject go1;
    GameObject go2;
    std::array<GameObject*, MAX_GAME_OBJECTS> gameObjects;
    int goIndex = 0;
    float prevTime, currTime, delta;

    /* Initialize the graphics and create a window */
    if (!g.createWindow(640, 480, "Hello, world!"))
    {
        std::cout << "Error!" << std::endl;
        return -1;
    }

    /* Initialize GameObjects */
    gameObjects.fill(NULL);
    gameObjects[goIndex++] = &go1;
    gameObjects[goIndex++] = &go2;

    /* Game Loop */
    prevTime = getTime();
    while (!g.windowShouldClose())
    {
        /* Update Timers */
        currTime = getTime();
        delta = currTime - prevTime;

        /* Game Logic */
        go1.move(100000, 0, delta);
        go2.move(0, 100000, delta);

        /* Render */
        g.render(gameObjects);

        prevTime = getTime();
    }

    g.cleanup();

    return 0;
}
