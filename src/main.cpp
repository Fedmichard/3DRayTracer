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
    /*
    canvas c(canvas_pixels, canvas_pixels);
    color color1(0.5, 1, 0.5); // Color for sphere intersections
    color white(255.0f, 255.0f, 255.0f); // Color for sphere intersections
    color black(0.0f, 0.0f, 0.0f); // Color for sphere intersections
    sphere s; // Sphere definition

    point ray_origin(0, 0, -10);

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

            if (closest_intersection) {
                c.write_pixel(x, y, color1);
            } else {
                c.write_pixel(x, y, black); // Optionally clear the background to black for empty pixels
            }
        }
    }

    std::ofstream ppm_file("trajectory.ppm");
    ppm_file << c.canvas_to_ppm();
    ppm_file.close();

    */

    sphere w;
    w.set_transform(matrix4::translation(0, 1, 0));
    vector n = w.normal_at(point(0, 1.70711, -0.70711));
    n.print();

    sphere y;
    matrix4 scaling = matrix4::scaling(1, 0.5, 1) * matrix4::rotation_z(M_PI / 5);
    y.set_transform(scaling);
    vector m = y.normal_at(point(0, sqrt(2) / 2, -sqrt(2) / 2));
    m.print();

    return 0;
}