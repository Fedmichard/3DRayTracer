#include <iostream>

#include "math.h"
#include "canvas.h"

int main() {
    canvas c(10, 20);
    c.write_pixel(2, 3, color(1.0f, 0.0f, 0.0f));

    std::cout << c.pixel_at(2, 3).getX();

    return 0;
}