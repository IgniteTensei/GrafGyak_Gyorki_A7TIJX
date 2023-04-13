#ifndef DRAW_H
#define DRAW_H

#include <SDL2/SDL.h>
#include <stdbool.h>

typedef struct Draw
{
    SDL_Window* window;
    SDL_GLContext gl_context;
    bool is_running;
    int width;
    int height;

} Draw;

void init_window(Draw* draw, int width, int height);

void init_sdl(Draw* draw);

void render_window(Draw* draw);

void init_opengl(Draw* draw);

void destroy_window(Draw* draw);

void handle_event(Draw* draw);

#endif
