#ifndef SPHERE_H
#define SPHERE_H

#include "ray.h"
#include <optional>
#include <cmath>

class intersection;

class sphere {
private:
    point origin;
    float radius = 1;
    matrix4 trans = matrix4::identityMatrix();

public:
    sphere() = default;
    sphere(point origin, float radius) : origin(origin), radius(radius) {};

    // getter functions
    point get_origin() { return origin; }
    float get_radius() { return radius; }
    matrix4 get_transform() { return trans; }

    // setter functions
    void set_origin(point point) { origin = point; }
    void set_radius(float rad) { radius = rad; }
    void set_transform(const matrix4& translation) { trans = translation; }

    vector normal_at(const point& p);

    // sphere intersects based on ray
    // from 1 ray we'll get all the intersections and each object that intersection belongs to
    std::vector<intersection> intersect(ray& r);
};

#endif