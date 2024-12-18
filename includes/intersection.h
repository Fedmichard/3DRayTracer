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
    
    // The reason we use a pointer is the object may potentially not exist, we will return
    // a reference to the object instead of an absolute value
    sphere* get_object() const { return object; }
};

std::vector<intersection> intersections(std::initializer_list<intersection> inters);

// The reason we use a pointer is the object may potentially not exist, we will return
// a reference to the object instead of an absolute value
intersection* hit(const std::vector<intersection>& xs);

#endif