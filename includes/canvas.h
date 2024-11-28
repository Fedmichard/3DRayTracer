#ifndef CANVAS_H
#define CANVAS_H

#include "math.h"

class canvas {
private:
    int width, height;

public:
    canvas(int x, int y) : width(x), height(y) {};
    color background = color(0.0f, 0.0f, 0.0f);

    void write_pixel(int x, int y, color color);
    void canvas_to_ppm();
    color pixel_at(int x, int y);
};

#endif