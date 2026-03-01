#ifndef PAINT_H
#define PAINT_H

#include <SDL2/SDL.h>
#include <stdbool.h>

#define WIDTH 900
#define HEIGHT 600
#define START_RADIUS 20
#define START_COLOR 0x00FF0000
#define TARGET_FPS 60
#define COLOR_RECT_SIZE 20

extern Uint32 current_color;
extern Uint32 palette[8];
extern const int palette_size;

bool inside_palette(int x, int y);
void change_color(int x, int y, Uint32 *current_color, Uint32 *palette);
void draw_palette(SDL_Surface* surface, Uint32 *colors, int size);
void draw_circle(SDL_Surface *surface, int x_center, int y_center, int radius, Uint32 color);

#endif