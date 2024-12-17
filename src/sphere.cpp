#include "sphere.h"
#include "intersection.h"

std::vector<intersection> sphere::intersect(ray& r) {
    matrix4 inverse = trans.inverse();
    ray r2 = r.transform(inverse);

    vector sphere_to_ray = r2.get_origin() - origin;

    float a = vector::dot(r2.get_direction(), r2.get_direction());
    float b = 2 * vector::dot(r2.get_direction(), sphere_to_ray);
    float c = vector::dot(sphere_to_ray, sphere_to_ray) - radius * radius;

    float discriminant = b * b - 4 * a * c;

    std::vector<intersection> intersects;

    if(discriminant < 0)  { return intersects; }

    float sqrt_discriminant = sqrt(discriminant);

    float t1 = (-b - sqrt(discriminant)) / (2 * a);
    float t2 = (-b + sqrt(discriminant)) / (2 * a);

    intersects.push_back(intersection(t1, this));
    intersects.push_back(intersection(t2, this));

    return intersects;
}