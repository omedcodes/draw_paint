#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <math.h>

#define WIDTH 900
#define HEIGHT 600
#define START_RADIUS 20

#define TARGET_FPS 60

void draw_circle(SDL_Surface *surface, int x_center, int y_center, int radius, Uint32 color)
{
    SDL_Rect pixel = {0, 0, 1, 1};
    for (int x = x_center - radius; x < x_center + radius; x++) 
    {
        for (int y = y_center - radius; y < y_center + radius; y++) 
        {
            /* is this pixel part of the circle?
               Top left corner is (x-r, y-r) and bottom right corner is (x+r, y+r)
               distance from center and radius border sqrt( pow(x - x_center, 2) + pow(y - y_center, 2))
            */
            double distance_from_center = sqrt(pow(x - x_center, 2) + pow(y - y_center, 2));
            if (distance_from_center < radius) 
            {
                pixel.x = x;
                pixel.y = y;
                SDL_FillRect(surface, &pixel, color);
            }
        }
    }
}

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
    int radius = START_RADIUS;
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
                    x = event.motion.x;
                    y = event.motion.y;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    draw = true;
                    x = event.motion.x;
                    y = event.motion.y;
                    break;
                case SDL_MOUSEBUTTONUP:
                    draw = false;
                    break;
            }
        }
        if (draw) {
            draw_circle(surface, x, y, radius, 0x00FF0000);
            SDL_UpdateWindowSurface(window);
            SDL_Delay(delay_milliseconds);
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}