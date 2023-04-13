#include <GL/gl.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

#include <stdbool.h>
#include <stdio.h>

#include "line.h"
#include "draw.h"

int main(int argc, char* argv[])
{
    Draw draw;
    init_window(&draw, 800, 600);

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(0.2f, 0.4f);
    glVertex2f(0.8f, 0.8f);
    glEnd();

    handle_event(&draw);
 

    destroy_window(&draw);

    return 0;
}
