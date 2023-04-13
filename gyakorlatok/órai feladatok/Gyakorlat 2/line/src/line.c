#include <GL/gl.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

#include <stdbool.h>
#include <stdio.h>

#include "line.h"

void initFirstPoint(Line* line, float x, float y)
{
    line->firstX = x;
    line->firstY = y;
}

void initLastPoint(Line* line, float x, float y)
{
    line->lastX = x;
    line->lastY = y;
}

void lineDrawing(Line* line)
{
    glBegin(GL_LINES);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(line->firstX, line->firstY);
        glVertex2f(line->lastX, line->lastY);
        glEnd();
        
}