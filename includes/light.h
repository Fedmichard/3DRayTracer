#ifndef LIGHT_H
#define LIGHT_H

#include "math.h"

class light {
private:
    point pos;
    color intensity;

public:
    light() = default;
    light(point position, color intensity) : pos(position), intensity(intensity) {};
};

#endif