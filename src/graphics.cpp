#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "graphics.h"

float Graphics::getCxtX(float xCor)
{
    return (2 * xCor) / winWidth - 1.0f;
}
float Graphics::getCxtY(float yCor)
{
    return (2 * yCor) / winHeight - 1.0f;
}

/* Create a window
 * returns false if something failed */
bool Graphics::createWindow(int width, int height, const char* title)
{

    winWidth = width;
    winHeight = height;

    /* Initialize the GLFW library */
    if (!glfwInit()) return false;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return false;
    }

    glfwMakeContextCurrent(window);

    /* Initialize glew for modern OpenGL */
    if (glewInit() != GLEW_OK)
    {
        glfwTerminate();
        return false;
    }

    std::cout << "Using OpenGL version " << glGetString(GL_VERSION) <<std::endl;

    return true;
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

/* Renders the given GameObject */
void Graphics::render(GameObject go)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);
    glVertex2f(getCxtX(go.getX()), getCxtY(go.getY()));
    glVertex2f(getCxtX(go.getX()), getCxtY(go.getY()+go.getHeight()));
    glVertex2f(getCxtX(go.getX()+go.getWidth()), getCxtY(go.getY()+go.getHeight()));
    glVertex2f(getCxtX(go.getX()+go.getWidth()), getCxtY(go.getY()));
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
