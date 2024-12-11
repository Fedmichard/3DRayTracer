#include <iostream>
#include <fstream>

#include "math.h"
#include "canvas.h"

const int width = 400;
const int height = 300;

int main() {
    canvas c(width, height);
    c.write_pixel(2, 3, color(1.0f, 0.0f, 0.0f));

    std::cout << c.canvas_to_ppm();

    return 0;
}