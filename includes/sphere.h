#ifndef SPHERE_H
#define SPHERE_H

#include "ray.h"

class intersection;

class sphere {
private:
    point origin;
    float radius = 1;

public:
    sphere() = default;
    sphere(point origin, float radius) : origin(origin), radius(radius) {};

    // getter functions
    point get_origin() { return origin; }
    float get_radius() { return radius; }

    // setter functions
    void set_origin(point point) { origin = point; }
    void set_radius(float rad) { radius = rad; }

    // sphere intersects based on ray
    // from 1 ray we'll get all the intersections and each object that intersection belongs to
    std::vector<intersection> intersect(ray& ray);
};

#endif