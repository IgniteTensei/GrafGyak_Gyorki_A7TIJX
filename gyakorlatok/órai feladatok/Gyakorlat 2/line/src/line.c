#include <GL/gl.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

#include <stdbool.h>
#include <math.h>
#include <stdio.h>

#include "line.h"

void set_line(Line *line, float x, float y)
{
    line->x = x;
    line->y = y;
}

void set_color(Color *color, float r, float g, float b, float a)
{  
    color->r = r;
    color->g = g;
    color->b = b;
    color->a = a;
}