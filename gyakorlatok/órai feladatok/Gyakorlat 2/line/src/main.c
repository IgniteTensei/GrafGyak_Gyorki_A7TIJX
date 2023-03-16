#include <GL/gl.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

#include <stdbool.h>
#include <stdio.h>

#include "line.h"

int main(int argc, char* argv[])
{
    Color color;
    Line line;   

    int error_code;
    SDL_Window* window;
    bool need_run;
    SDL_Event event;
    SDL_GLContext gl_context;
    int i;

    error_code = SDL_Init(SDL_INIT_EVERYTHING);
    if (error_code != 0) {
        printf("[ERROR] SDL initialization error: %s\n", SDL_GetError());
        return error_code;
    }

    window = SDL_CreateWindow(
        "Lines",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        800, 600,
        SDL_WINDOW_OPENGL);

    gl_context = SDL_GL_CreateContext(window);
    glBegin(GL_LINES);


    need_run = true;
    while (need_run) {

        glClearColor(0.1f, 0.1f, 0.1f, 1);
        glClear(GL_COLOR_BUFFER_BIT); 
        glColor3f(1, 0, 0);

        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_SCANCODE_Q:
                    need_run = false;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    if (event.button.button == SDL_BUTTON_LEFT) {
                        glColor3f(1, 0, 0);
                        line.x = event.button.x;
                        line.y = event.button.y;
                        glVertex2f(line.x, line.y);
                    }
                    break;
                case SDL_MOUSEBUTTONUP:
                    if (event.button.button == SDL_BUTTON_LEFT) {
                        glColor3f(1, 0, 0);
                        line.x = event.button.x;
                        line.y = event.button.y;
                        glVertex2f(line.x, line.y);
                    }
                    break;
                case SDL_QUIT:
                need_run = false;
                break;
      }
    }
   
        glEnd();

        SDL_GL_SwapWindow(window);
    }

    SDL_GL_DeleteContext(gl_context);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
