#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

#define WIDTH 900
#define HEIGHT 600

int main(int argc, char *argv[]) 
{
    (void)argc; (void)argv;
    
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow("Draw Paint", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);

    bool done = false;
    while (!done) 
    {
        SDL_Event event;
        while (SDL_PollEvent(&event)) 
        {
            if (event.type == SDL_QUIT)
                done = true;
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}