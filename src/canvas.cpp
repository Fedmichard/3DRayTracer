#include "canvas.h"
#include <sstream>

/******************************************************************************************************
 * Canvas
 *******************************************************************************************************/
// Write at a specific pixel
void canvas::write_pixel(int x, int y, color c) {
    pixels[x][y] = c;
}

// return color at specific pixel
color canvas::pixel_at(int x, int y) {
    return pixels[x][y];
}

// Make all pixels the same color
void canvas::write_all_pixels(color color) {
    for (int row = 0; row < width; row++) {
        for (int col = 0; col < height; col++) {
            write_pixel(row, col, color);
        }
    }
}

/******************************************************************************************************
 * PPM
 *******************************************************************************************************/
std::string canvas::canvas_to_ppm() {
    std::ostringstream ppm; // our PPM

    // PPM Header
    ppm << "P3\n";
    ppm << width << " " << height << "\n";
    ppm << "255\n";

    // PPM Data
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            ppm << pixels[col][row]; // write to ppm

            // if column is less than te width
            if (col < width - 1) {
                ppm << " ";
            }

        }
        
        ppm << "\n"; // new line after the end of every row
    }
    ppm << "\n"; // PPM terminated by a newline character

    return ppm.str();
}