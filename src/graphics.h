#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "utils.h"
#include "gameobject.h"
#include <GLFW/glfw3.h>

class Graphics
{
private:
    GLFWwindow* window;
    int winWidth, winHeight;

    float getCxtX(float xCor);
    float getCxtY(float yCor);
public:

    /* Create a window
     * returns false if something failed */
    bool createWindow(int width, int height, const char* title);

    /* Determine whether something's trying to close the window */
    bool windowShouldClose(void);

    /* Render objects */
    void render(void);

    /* Renders the given GameObject */
    void render(GameObject go);

    /* Cleanup any resources used by the graphics */
    void cleanup();

    /* Probably don't use this ¯\_(ツ)_/¯*/
    int test(void);
};
#endif
