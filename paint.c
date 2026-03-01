#include "paint.h"

bool inside_palette(int x, int y) {
    return x <= 8 * COLOR_RECT_SIZE && y <= COLOR_RECT_SIZE;
}

void change_color(int x, int y, Uint32 *current_color, Uint32 *palette) {
    if (inside_palette(x, y)) {
        int i = x / COLOR_RECT_SIZE;
        *current_color = palette[i];
    }
}

void draw_palette(SDL_Surface* surface, Uint32 *colors, int size) {
    for (int i = 0; i < size; i++) {
        SDL_Rect color_rect = {i * COLOR_RECT_SIZE, 0, COLOR_RECT_SIZE, COLOR_RECT_SIZE};
        SDL_FillRect(surface, &color_rect, colors[i]);
    }
}

void draw_circle(SDL_Surface *surface, int x_center, int y_center, int radius, Uint32 color) {
    SDL_Rect pixel = {0, 0, 1, 1};
    int r_squared = radius * radius;

    for (int x = x_center - radius; x < x_center + radius; x++) {
        for (int y = y_center - radius; y < y_center + radius; y++) {
            int dx = x - x_center;
            int dy = y - y_center;
            
            if ((dx * dx) + (dy * dy) < r_squared) {
                pixel.x = x;
                pixel.y = y;
                SDL_FillRect(surface, &pixel, color);
            }
        }
    }
}