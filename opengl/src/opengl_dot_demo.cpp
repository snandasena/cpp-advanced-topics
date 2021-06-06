//
// Created by sajith on 6/6/21.
//

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdio.h>
#include "ogldev_math_3d.h"

static void RenderSceneCB()
{

    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}

int main(int argc, char **argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

    int width = 1200;
    int height = 900;

    glutInitWindowSize(width, height);

    int x = 200;
    int y = 100;

    glutInitWindowPosition(x, y);
    int win = glutCreateWindow("Demo");
    printf("window id: %d\n", win);

    GLclampf Red = 0.0f, Green = 0.0f, Blue = 0.0f, Alpha = 0.0f;
    glClearColor(Red, Green, Blue, Alpha);

    glutDisplayFunc(RenderSceneCB);

    glutMainLoop();
    return 0;
}