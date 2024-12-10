#ifndef CANVAS_H
#define CANVAS_H

#include "math.h"
#include <vector>

class canvas {
private:
    int width, height;
    std::vector<std::vector<color>> pixels;

public:
    canvas(int x, int y) : width(x), height(y) {
        for (int i = 0; i < x; i++) {
            for (int v = 0; v < y; v++) {
                write_pixel(i, v, color(0, 0, 0));
            }
        }
    };
    
    color background = color(0.0f, 0.0f, 0.0f);

    void write_pixel(int x, int y, color color);
    void canvas_to_ppm();
    color pixel_at(int x, int y);
};

#endif