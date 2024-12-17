#ifndef INTERSECTION_H
#define INTERSECTION_H

#include <initializer_list>
#include "math.h"
#include <vector>

class sphere;

// we'll store each intersection as a class rather than a vector
// this way we can attach the time and object of each intersection
class intersection {
private:
    float t;
    sphere* object; 

public:
    intersection(float t, sphere* object) : t(t), object(object) {};

    float get_t() const { return math::sanitize(t); }
    sphere* get_object() const { return object; }
};

std::vector<intersection> intersections(std::initializer_list<intersection> inters);
intersection* hit(const std::vector<intersection>& xs);

#endif