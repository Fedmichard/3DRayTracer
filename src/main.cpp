#include <iostream>
#include <fstream>

#include "math.h"
#include "world.h"
#include "canvas.h"
#include "ray.h"
#include "sphere.h"
#include "intersection.h"
#include "light.h"
#include "lighting.h"
#include "material.h"

const float wall_size = 7.0f;
const float wall_z = 10.0f;
const int canvas_pixels = 100;
const float pixel_size = wall_size / canvas_pixels;
const float half = wall_size / 2;

int main() {
    canvas c(canvas_pixels, canvas_pixels);
    world w;
    color color1(0.5, 1, 0.5); // Color for sphere intersections
    color white(255.0f, 255.0f, 255.0f); // Color for sphere intersections
    color black(0.0f, 0.0f, 0.0f); // Color for sphere intersections
    sphere s; // Sphere definition
    s.set_material(material());
    s.get_material().setColor(color1);

    point light_position = point(-10.0f, 10.0f, -10.0f);
    color light_color = color(1.0f, 1.0f, 1.0f);
    light point_light(light_position, light_color);

    point ray_origin(0, 0, -10);

    // Drawing onto canvas
    for (int y = 0; y < canvas_pixels; y++) {
        float world_y = half - pixel_size * y;
        for (int x = 0; x < canvas_pixels; x++) {
            float world_x = -half + pixel_size * x;
            point position(world_x, world_y, wall_z);

            vector normal_vector = (position - ray_origin).normalize();

            ray r(ray_origin, normal_vector);
            auto xs = s.intersect(r);

            intersection* closest_intersection = hit(xs);

            if (closest_intersection) {
                point intersection_point = r.position(closest_intersection->get_t());
                vector normal = s.normal_at(intersection_point);
                vector eye = -r.get_direction();
                color pixel_color = lighting(s.get_material(), point_light, intersection_point, eye, normal);
                c.write_pixel(x, y, pixel_color);
            } else {
                c.write_pixel(x, y, black); // Optionally clear the background to black for empty pixels
            }
        }
    }

    std::ofstream ppm_file("trajectory.ppm");
    ppm_file << c.canvas_to_ppm();
    ppm_file.close();

    return 0;
}