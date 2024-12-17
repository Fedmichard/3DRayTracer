#include <iostream>
#include <fstream>

#include "math.h"
#include "canvas.h"
#include "ray.h"
#include "sphere.h"
#include "intersection.h"

const float wall_size = 7.0f;
const float wall_z = 10.0f;
const int canvas_pixels = 100;
const float pixel_size = wall_size / canvas_pixels;
const float half = wall_size / 2;

int main() {
    canvas c(canvas_pixels, canvas_pixels);
    color color1(0.0f, 1.0f, 1.0f); // Color for sphere intersections
    sphere s; // Sphere definition

    point ray_origin(0, 0, -5);

    // Drawing onto canvas
    for (int y = 0; y < canvas_pixels; y++) {
        float world_y = half - pixel_size * y;
        for (int x = 0; x < canvas_pixels; x++) {
            float world_x = -half + pixel_size * x;
            point position(world_x, world_y, wall_z);

            vector normal_vector(position - ray_origin);

            ray r(ray_origin, normal_vector);
            auto xs = s.intersect(r);

            intersection* closest_intersection = hit(xs);

            if (closest_intersection && closest_intersection->get_t() >= 0) {
                c.write_pixel(x, y, color1);
            } else {
                c.write_pixel(x, y, color(0, 0, 0)); // Optionally clear the background to black for empty pixels
            }
        }
    }

    /*
    const int width = 800;
    const int height = 800;
    const int CLOCK_RADIUS = width * 0.375;
    const int CENTER_X = width / 2;
    const int CENTER_Y = height / 2;

    for (int hour = 0; hour < 768; hour++) {
        double angle = hour * M_PI / 384; // Rotation angle (π/6 radians per hour)
        matrix4 rotation = matrix4::rotation_y(angle); // Y-axis rotation matrix
        point hour_position = rotation * twelve; // Rotate twelve o'clock position

        // Scale to canvas and move to center
        int x = (CENTER_X + hour_position.getX() * CLOCK_RADIUS);
        int y = (CENTER_Y - hour_position.getZ() * CLOCK_RADIUS);

        // Draw the pixel at the calculated position
        c.write_pixel(x, y, color1);
    }
    */

    std::ofstream ppm_file("trajectory.ppm");
    ppm_file << c.canvas_to_ppm();
    ppm_file.close();

    return 0;
}