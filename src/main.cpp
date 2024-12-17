#include <iostream>
#include <fstream>

#include "math.h"
#include "canvas.h"
#include "ray.h"
#include "sphere.h"
#include "intersection.h"

const int width = 800;
const int height = 800;
const int CLOCK_RADIUS = width * 0.375;
const int CENTER_X = width / 2;
const int CENTER_Y = height / 2;

int main() {
    canvas c(width, height);
    color color1(0.0f, 1.0f, 1.0f);
    point twelve(0, 0, 1);

    for (int hour = 0; hour < 12; hour++) {
        double angle = hour * M_PI / 6; // Rotation angle (π/6 radians per hour)
        matrix4 rotation = matrix4::rotation_y(angle); // Y-axis rotation matrix
        point hour_position = rotation * twelve; // Rotate twelve o'clock position

        // Scale to canvas and move to center
        int x = (CENTER_X + hour_position.getX() * CLOCK_RADIUS);
        int y = (CENTER_Y - hour_position.getZ() * CLOCK_RADIUS);

        // Draw the pixel at the calculated position
        c.write_pixel(x, y, color1);
    }

    std::ofstream ppm_file("trajectory.ppm");
    ppm_file << c.canvas_to_ppm();
    ppm_file.close();

    ray r(point(0, 0, -5), vector(0, 0, 1));
    sphere s;

    s.set_transform(matrix4::scaling(2, 2, 2));

    auto xs = s.intersect(r);

    std::cout << xs.size() << std::endl;
    std::cout << xs[0].get_t() << std::endl;
    std::cout << xs[1].get_t() << std::endl;

    return 0;
}