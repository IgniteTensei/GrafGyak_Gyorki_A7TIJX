#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>

typedef struct Line
{
    float firstX, firstY, lastX, lastY;

} Line;

void initFirstPoint(Line* line, float x, float y);

void initLastPoint(Line* line, float x, float y);

void lineDrawing(Line* line);

#endif