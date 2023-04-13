#ifndef LINE_H
#define LINE_H

#include <SDL2/SDL.h>

typedef struct Line
{
	float beginX;
	float beginY;
	float endX;
	float endY;

} Line;

void set_line_begin(Line* line, float beginX, float beginY);

void set_line_end(Line* line, float endX, float endY);

void draw_line(Line* line);

#endif

