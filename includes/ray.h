#ifndef RAY_H
#define RAY_H

#include "math.h"

class ray {
private:
    point origin;
    vector direction;

public:
    ray(point origin, vector direction) : origin(origin), direction(direction) {};

    point get_origin() { return origin; }
    vector get_direction() { return direction; }

    point position(float t);
    ray transform(matrix4& matrix);
    static vector reflect(vector& in, vector& normal);
};

#endif