#include <stdio.h>
#include "graphics.h"

int main(int argc, char** argv)
{
    Graphics g;

    /* Initialize the graphics and create a window*/
    if (!g.init()) return -1;
    if (!g.createWindow(640, 480, "Hello, world!")) return -1;

    /* Game Loop */
    while (!g.windowShouldClose())
    {
        g.render();
    }

    g.cleanup();

    return 0;
}
