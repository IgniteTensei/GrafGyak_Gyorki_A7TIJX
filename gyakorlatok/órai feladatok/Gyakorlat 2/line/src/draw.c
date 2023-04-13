#include "draw.h"
#include "line.h"

#include <GL/gl.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

#include <stdbool.h>
#include <stdio.h>


void init_window(Draw* draw, int width, int height)
{
    draw->width = width;
    draw->height = height;

    draw->is_running = false;

    init_sdl(draw);
    init_opengl(draw);
}

void init_sdl(Draw* draw)
{
    draw->is_running = false;

    draw->window = SDL_CreateWindow(
        "Lines",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        draw->width, draw->height,
        SDL_WINDOW_OPENGL);

    draw->gl_context = SDL_GL_CreateContext(draw->window);

    draw->is_running = true;
}

void render_window(Draw* draw);

void init_opengl(Draw* draw)
{
    glOrtho(0, draw->width, draw->height, 0, -200, 200);
    glViewport(0, 0, draw->width, draw->height);
}

void destroy_window(Draw* draw)
{
    SDL_GL_DeleteContext(draw->gl_context);
    SDL_DestroyWindow(draw->window);
    SDL_Quit();
}

void handle_event(Draw* draw)
{
        SDL_Event event;
        Line line;

       while (draw->is_running) {

        glClearColor(0.1f, 0.1f, 0.1f, 1);
        glClear(GL_COLOR_BUFFER_BIT); 
        glColor3f(1, 0, 0);

        bool secondClick = false;
        int x;
        int y;

        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_SCANCODE_Q:
                    draw->is_running = false;
                    break;
                case SDL_MOUSEBUTTONDOWN:

                    SDL_GetMouseState(&x, &y);
                    printf("x: %f\n", (float)x/draw->width);
                    printf("y: %f\n", (float)y/draw->height);
                    
                    if(event.button.button == SDL_BUTTON_LEFT)
                        printf("LEFT\n");        

                    if(event.button.button == SDL_BUTTON_RIGHT)
                        printf("RIGHT\n");



                    if (secondClick == false)
                    {
                        glBegin(GL_LINES);
                        set_line_begin(&line, (float)(x/draw->width), (float)(y/draw->height));
                        
                        secondClick = true;
                    }
                    else if (secondClick == true)
                    {
                        set_line_end(&line, (float)(x/draw->width), (float)(y/draw->height));

                        secondClick = false;

                        draw_line(&line);
                    }
                    

                    break;
                case SDL_QUIT:
                draw->is_running = false;
                break;
      }
    }
        
        SDL_GL_SwapWindow(draw->window);
    }
}

