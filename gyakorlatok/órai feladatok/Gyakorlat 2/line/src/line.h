#ifndef LINE_H
#define LINE_H

typedef struct Color
{
    float r, g, b, a;
} Color;


typedef struct Line
{
	float x, y;
} Line;

void set_line(Line *line, float x, float y);

void set_color(Color *color, float r, float g, float b, float a);


#endif

