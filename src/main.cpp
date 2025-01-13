#include <iostream>
#include <fstream>

#include "canvas.h"
#include "computations.h"
#include "intersection.h"
#include "light.h"
#include "lighting.h"
#include "material.h"
#include "math.h"
#include "ray.h"
#include "sphere.h"
#include "world.h"

const float wall_size = 7.0f;
const float wall_z = 10.0f;
const int canvas_pixels = 100;
const float pixel_size = wall_size / canvas_pixels;
const float half = wall_size / 2;

int main() {
    // World and Canvas
    canvas c(canvas_pixels, canvas_pixels);
    world w; // default world

    // Color values [ will move later ]
    color color1(0.5, 1, 0.5); // Color for sphere intersections
    color color2(0.8, 1.0, 0.6); // Color for sphere intersections
    color white(255.0f, 255.0f, 255.0f); // Color for sphere intersections
    color black(0.0f, 0.0f, 0.0f); // Color for sphere intersections

    // ray that serves as "camera" of some sort
    point ray_origin(0, 0, -10);
    
    // sphere 1
    sphere s1; // Sphere definition
    s1.get_material().setColor(color2);
    s1.get_material().setDiffuse(0.7f);
    s1.get_material().setSpecular(0.2f);
    s1.get_material().setAmbient(1.0f);

    // sphere 2
    sphere s2;
    s2.set_transform(matrix4::scaling(0.5, 0.5, 0.5));
    s2.get_material().setAmbient(1.0f);

    // light values
    point light_position = point(-10.0f, 10.0f, -10.0f);
    color light_color = color(1.0f, 1.0f, 1.0f);
    light point_light(light_position, light_color);

    // define our world
    w.set_light_source(&point_light);
    w.set_object(s1);
    w.set_object(s2);

    // all objects
    std::vector<sphere> all_spheres = w.get_objects();

    // unit test
    ray rrrr(point(0, 0, 0.75), vector(0, 0, -1));
    color ccccc = w.color_at(rrrr);
    ccccc.print();
    s2.get_material().getColor().print();

    // Drawing onto canvas
    for (int y = 0; y < canvas_pixels; y++) {
        float world_y = half - pixel_size * y;
        for (int x = 0; x < canvas_pixels; x++) {
            float world_x = -half + pixel_size * x;
            point position(world_x, world_y, wall_z);

            vector normal_vector = (position - ray_origin).normalize();

            ray r(ray_origin, normal_vector);
            auto xs = s1.intersect(r);

            intersection* closest_intersection = hit(xs);

            if (closest_intersection) {
                point intersection_point = r.position(closest_intersection->get_t());
                vector normal = s1.normal_at(intersection_point);
                vector eye = -r.get_direction();
                color pixel_color = lighting(s1.get_material(), point_light, intersection_point, eye, normal);
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