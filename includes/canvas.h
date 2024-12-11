#ifndef CANVAS_H
#define CANVAS_H

#include "math.h"
#include <vector>
#include <string>

class canvas {
private:
    int width, height;
    color background = color(0.0f, 0.0f, 0.0f);
    // need pixels vector to be dynamic since we want to be able to change the size of the canvas
    std::vector<std::vector<color>> pixels;

public:
    // The x value is essentially just the row, it doesn't specifically hold anything but a vector
    // the y value is the column, each column holds a color value
    // so every single row has 1 specific vector
    // every single column has 1 color
    canvas(int x, int y) : width(x), height(y), pixels(x, std::vector<color>(y, background)) { // initializer list
        for (int i = 0; i < width; i++) {
            for (int v = 0; v < height; v++) {
                write_pixel(i, v, background);
            }
        }
    };

    void write_pixel(int x, int y, color color);
    void write_all_pixels(color color);
    std::string canvas_to_ppm();
    color pixel_at(int x, int y);
};

#endif