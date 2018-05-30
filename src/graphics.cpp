#include "graphics.h"
#include <GLFW/glfw3.h>

/* Initialize the graphics
 * returns false if something failed */
bool Graphics::init(void)
{
    /* Initialize the GLFW library */
    return glfwInit();
}

/* Create a window
 * returns false if something failed */
bool Graphics::createWindow(int width, int height, const char* title)
{
    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return false;
    }

    glfwMakeContextCurrent(window);
}

/* Determine whether something's trying to close the window */
bool Graphics::windowShouldClose(void)
{
    return glfwWindowShouldClose(window);
}

/* Render objects */
void Graphics::render(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    /* Render code here */
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f( 0.0f,  0.5f);
    glVertex2f( 0.5f, -0.5f);
    glEnd();

    glfwSwapBuffers(window);
    glfwPollEvents();
}

/* Cleanup any resources used by the graphics */
void Graphics::cleanup(void)
{
    glfwTerminate();
}

/* Testing code taken from GLFW documentation */
int Graphics::test(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit()) return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_TRIANGLES);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f( 0.0f,  0.5f);
        glVertex2f( 0.5f, -0.5f);
        glEnd();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
