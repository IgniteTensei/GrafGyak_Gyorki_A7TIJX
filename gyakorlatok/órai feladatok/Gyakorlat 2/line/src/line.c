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
    printf("Line -> firstX=%f, firstY=%f, lastX=%f, lastY=%f\n", line->firstX, line->firstY, line->lastX, line->lastY);

    glBegin(GL_LINES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(line->firstX, line->firstY);
    glVertex2f(line->lastX, line->lastY);
    glEnd();
        
}

/*void lineArrayDrawing(Line* line[], int size)
{
    glBegin(GL_LINES);
    glColor3f(1.0, 0.0, 0.0);
    
    for (int i = 0; i < size; i++)
    {
        printf("Line[%d] -> firstX=%f, firstY=%f, lastX=%f, lastY=%f\n", (i+1), line[i]->firstX, line[i]->firstY, line[i]->lastX, line[i]->lastY);

        glVertex2f(line[i]->firstX, line[i]->firstY);
        glVertex2f(line[i]->lastX, line[i]->lastY);
    }

    glEnd();
}*/