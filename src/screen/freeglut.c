#include "screen/freeglut.h"

void ScreenInit(int w, int h, const char *title, bool fullscreen)
{
    // glutInitContextVersion(2, 1);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(w, h);
    glutCreateWindow(title);
    if (fullscreen)
    {
        glutFullScreen();
    }
    GLenum error;

    glViewport(0.f, 0.f, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, w, h, 0.0, 1.0, -1.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClearColor(0.f, 0.f, 0.f, 1.f);

    glEnable(GL_TEXTURE_2D);

    error = glGetError();
    if (error != GL_NO_ERROR)
    {
        //Error initializing OpenGL!
        return false;
    }
}

void ScreenDestroy(void)
{
    // SDL_DestroyWindow(Screen.window);
    // LogWrite("Window destroyed", 0, MT_INFO, NULL);
}

void ScreenCursorShow(void)
{
    // SDL_ShowCursor(1);
}

void ScreenCursorHide()
{
    // SDL_ShowCursor(0);
}

