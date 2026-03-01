#include <stdio.h>
#include "paint.h"

int main(int argc, char *argv[]) {
    (void)argc; (void)argv;
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow("Draw Paint", SDL_WINDOWPOS_CENTERED, 
                                          SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
    SDL_Surface *surface = SDL_GetWindowSurface(window);

    Uint32 current_color = START_COLOR;
    Uint32 palette[8] = {0x000000, 0xFFFFFF, 0xFF0000, 0x00FF00, 0x0000FF, 0xFFFF00, 0x00FFFF, 0xFF00FF};
    
    bool done = false;
    bool draw = false;
    int x, y, brush_size = START_RADIUS;
    float delay = (1.0f / TARGET_FPS) * 1000;

    while (!done) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) done = true;
            if (event.type == SDL_MOUSEMOTION) { x = event.motion.x; y = event.motion.y; }
            if (event.type == SDL_MOUSEBUTTONDOWN) {
                if (inside_palette(event.button.x, event.button.y))
                    change_color(event.button.x, event.button.y, &current_color, palette);
                else draw = true;
            }
            if (event.type == SDL_MOUSEBUTTONUP) draw = false;
            if (event.type == SDL_MOUSEWHEEL) {
                brush_size += event.wheel.y;
                if (brush_size < 1) brush_size = 1;
            }
        }

        if (draw) {
            draw_circle(surface, x, y, brush_size, current_color);
            SDL_UpdateWindowSurface(window);
        }
        draw_palette(surface, palette, 8);
        SDL_Delay(delay);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}