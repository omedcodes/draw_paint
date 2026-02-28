#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

#define WIDTH 900
#define HEIGHT 600

#define TARGET_FPS 60

int main(int argc, char *argv[]) 
{
    (void)argc; (void)argv;
    
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow("Draw Paint", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);

    SDL_Surface *surface = SDL_GetWindowSurface(window);

    bool done = false;
    bool draw = false;

    float delay_milliseconds = (1.0f / TARGET_FPS) * 1000;
    int x, y;
    while (!done) 
    {
        SDL_Event event;
        while (SDL_PollEvent(&event)) 
        {
            switch (event.type) 
            {
                case SDL_QUIT:
                    done = true;
                    break;
                case SDL_MOUSEMOTION:
                    draw = true;
                    x = event.motion.x;
                    y = event.motion.y;
                    break;
            }
        }
        if (draw) {
            SDL_Rect rect = {x, y, 100, 100};
            SDL_FillRect(surface, &rect, 0x00FF0000);
            SDL_UpdateWindowSurface(window);
            SDL_Delay(delay_milliseconds);
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}