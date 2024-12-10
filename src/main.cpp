#include <iostream>

#include "math.h"
#include "canvas.h"

int main() {
    canvas c(10, 20);
    color red(1, 0, 0);

    // c.write_pixel(2, 3, red);
    color black = c.pixel_at(2, 3);

    return 0;
}