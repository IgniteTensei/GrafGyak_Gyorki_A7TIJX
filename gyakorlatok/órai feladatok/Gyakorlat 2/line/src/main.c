#include <GL/gl.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

#include <stdbool.h>
#include <stdio.h>

#include "line.h"

int main(int argc, char* argv[])
{
    // Initialize
    SDL_Window* window;
    SDL_GLContext gl_context;
    int width = 800, height = 600;

    int error_code;

    error_code = SDL_Init(SDL_INIT_EVERYTHING);
    if (error_code != 0) {
        printf("[ERROR] SDL initialization error: %s\n", SDL_GetError());
        return false;
    }

    window = SDL_CreateWindow("Line Drawing", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);

    if (window == NULL) 
    {
        printf("[ERROR] Unable to create the application window!\n");
        return false;
    }

    gl_context = SDL_GL_CreateContext(window);

    if (gl_context == NULL)
    {
        printf("[ERROR] Unable to create the OpenGL context!\n");
        return false;
    }

    glShadeModel(GL_SMOOTH);
    glLoadIdentity();
    glMatrixMode(GL_PROJECTION);
    glOrtho(0, width, height, 0, -1, 1);
    glViewport(0, 0, width, height);

    glClearColor((float)25/255, (float)25/255, (float)112/255, 1.0);

    //Event handler

    SDL_Event event;
    bool is_running;
    is_running = true;

    int x;
    int y;
    int clickcounter = 0;
    Line line;


    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    while (is_running)
    {
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_KEYUP:
                switch (event.key.keysym.scancode)
                {
                    case SDL_SCANCODE_Q:
                        printf("Quit program\n");
                        is_running = false;
                        break;
            
                    default:
                        break;
                }
                break;

            case SDL_MOUSEBUTTONUP:

                clickcounter += 1;

                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    printf("LEFT\n");
                }
                if (event.button.button == SDL_BUTTON_RIGHT)
                {
                    printf("RIGHT\n");
                }

                SDL_GetMouseState(&x, &y);
                printf("x: %d\n", x);
                printf("y: %d\n", y);

                if (clickcounter == 1)
                {
                    initFirstPoint(&line, (float)x, (float)y);
                }
                else if (clickcounter == 2)
                {
                    initLastPoint(&line, (float)x, (float)y);
                    lineDrawing(&line);
                    clickcounter = 0;
                }

                break;
            
            default:
                break;
            }
            
        }

        //Render
        if (clickcounter == 2)
        {
            lineDrawing(&line);
            clickcounter = 0;
        }
        SDL_GL_SwapWindow(window);

    }

    //Shutting down the application
    
    SDL_GL_DeleteContext(gl_context);
    SDL_DestroyWindow(window);
    SDL_Quit();
    

}


