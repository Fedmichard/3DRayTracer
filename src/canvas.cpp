#include "canvas.h"
#include <sstream>

// Canvas
void canvas::write_pixel(int x, int y, color c) {
    pixels[x][y] = c;
}

color canvas::pixel_at(int x, int y) {

    return pixels[x][y];
}

// PPM
std::string canvas::canvas_to_ppm() {
    std::ostringstream ppm;
    ppm << "P3\n";
    ppm << width << " " << height << "\n";
    ppm << "255\n";

    return ppm.str();
}