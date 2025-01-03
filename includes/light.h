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

    point getPos() const { return pos; }
    void setPos(point position) { pos = position; }

    color getIntensity() const { return intensity; }
    void setIntensity(color intens) { intensity = intens; }
};

#endif