#include <stdio.h>
#include "gameobject.h"
#include "graphics.h"

int main(int argc, char** argv)
{
    Graphics g;
    GameObject go;

    /* Initialize the graphics and create a window*/
    if (!g.createWindow(640, 480, "Hello, world!")) return -1;

    /* Game Loop */
    while (!g.windowShouldClose())
    {
        g.render(go);
    }

    g.cleanup();

    return 0;
}
