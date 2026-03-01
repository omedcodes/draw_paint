#include <stdio.h>
#include "paint.h"

int main(int argc, char *argv[]) {
    (void)argc; (void)argv;

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("Draw Paint", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_MAXIMIZED | SDL_WINDOW_RESIZABLE);

    SDL_Surface *surface = SDL_GetWindowSurface(window);
    SDL_FillRect(surface, NULL, 0xFFFFFFFF);
    
    bool done = false;
    bool draw = false;
    int x = 0, y = 0;
    int brush_size = START_RADIUS;
    float delay = (1.0f / TARGET_FPS) * 1000;

    draw_palette(surface, palette, palette_size);
    SDL_UpdateWindowSurface(window);
    while (!done) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    done = true;
                    break;

                case SDL_MOUSEMOTION:
                    x = event.motion.x;
                    y = event.motion.y;
                    break;

                case SDL_MOUSEBUTTONDOWN:
                    if (inside_palette(event.button.x, event.button.y)) {
                        change_color(event.button.x, event.button.y, &current_color, palette);
                    } else {
                        draw = true;
                        draw_circle(surface, event.button.x, event.button.y, brush_size, current_color);
                        SDL_UpdateWindowSurface(window);
                    }
                    break;

                case SDL_MOUSEBUTTONUP:
                    draw = false;
                    break;

                case SDL_MOUSEWHEEL:
                    brush_size += event.wheel.y;
                    if (brush_size < 1) brush_size = 1;
                    break;

                case SDL_KEYDOWN:
                    if (event.key.keysym.sym == SDLK_s) {
                        SDL_SaveBMP(surface, "painting.bmp");
                    }
                    if (event.key.keysym.sym == SDLK_c) {
                        SDL_FillRect(surface, NULL, 0xFFFFFFFF);
                        draw_palette(surface, palette, palette_size);
                        SDL_UpdateWindowSurface(window);
                    }
                    break;
                
                case SDL_WINDOWEVENT:
                    if (event.window.event == SDL_WINDOWEVENT_RESIZED) {
                        surface = SDL_GetWindowSurface(window);
                    }
                    break;
            }
        }

        if (draw) {
            draw_circle(surface, x, y, brush_size, current_color);
            SDL_UpdateWindowSurface(window);
        }

        draw_palette(surface, palette, palette_size);
        SDL_Delay(delay);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}