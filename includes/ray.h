#ifndef RAY_H
#define RAY_H

#include "math.h"
#include "canvas.h"

class ray {
private:
    point o;
    vector d;

public:
    ray(point origin, vector direction) : o(origin), d(direction) {};

};

#endif