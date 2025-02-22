#include "ray.h"

point ray::position(float t) {
    return origin + direction * t;
}

ray ray::transform(matrix4& matrix) {
    return ray(matrix * get_origin(), matrix * get_direction());
}

vector ray::reflect(const vector& in, const vector& normal) {
    return in - normal * 2 * vector::dot(in, normal);
}