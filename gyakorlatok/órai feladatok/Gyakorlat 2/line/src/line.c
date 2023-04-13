#include <GL/gl.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

#include <stdbool.h>
#include <math.h>
#include <stdio.h>

#include "line.h"
#include "draw.h"

void set_line_begin(Line* line, float beginX, float beginY)
{
    line->beginX = beginX;
    line->beginY = beginY;
}

void set_line_end(Line* line, float endX, float endY)
{
    line->endX = endX;
    line->endY = endY;
}

void draw_line(Line* line)
{
    glBegin(GL_LINES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(line->beginX, line->beginY);
    glVertex2f(line->endX, line->endY);
    glEnd();

    printf("drawing line");
}
