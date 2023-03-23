#include <GL/gl.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

#include <stdbool.h>
#include <stdio.h>

#include "line.h"

int main(int argc, char* argv[])
{
    Line line;   

    SDL_Window* window;
    bool need_run;
    SDL_Event event;
    SDL_GLContext gl_context;

    window = SDL_CreateWindow(
        "Lines",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        800, 600,
        SDL_WINDOW_OPENGL);

    gl_context = SDL_GL_CreateContext(window);

    need_run = true;
    while (need_run) {

        glClearColor(0.1f, 0.1f, 0.1f, 1);
        glClear(GL_COLOR_BUFFER_BIT); 
        glColor3f(1, 0, 0);

        bool lineDrawing;
        int x;
        int y;

        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_SCANCODE_Q:
                    need_run = false;
                    break;
                case SDL_MOUSEBUTTONDOWN:

                    glBegin(GL_LINES);
                    glVertex2f(0, 0);
                    
                    SDL_GetMouseState(&x, &y);
                    printf("x: %f\n", (float)x/100);
                    printf("y: %f\n", (float)y/100);

                    glVertex2f((float)x/100, (float)y/100);
                    
                    if(event.button.button == SDL_BUTTON_LEFT)
                        printf("LEFT\n");
                        

                    if(event.button.button == SDL_BUTTON_RIGHT)
                        printf("RIGHT\n");
                        
                    glEnd();

                    break;
                case SDL_QUIT:
                need_run = false;
                break;
      }
    }
        
        SDL_GL_SwapWindow(window);
    }

    SDL_GL_DeleteContext(gl_context);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
