#include "canvas.h"

void canvas::write_pixel(int x, int y, color c) {
    pixels[x][y] = c;
}

color canvas::pixel_at(int x, int y) {

    return pixels[x][y];
}