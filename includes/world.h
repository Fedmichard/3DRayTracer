#ifndef WORLD_H
#define WORLD_H

#include "math.h"
#include "intersection.h"
#include "light.h"
#include "sphere.h"
#include "computations.h"
#include <vector>
#include <algorithm>

class world {
private:
    point world_point;
    std::vector<sphere> objects;
    light* light_source;

public:
    // default world values
    world() = default;

    // get and set world point
    point get_world_point() { return world_point; }
    void set_world_point(point new_world_point) { world_point = new_world_point; }
    
    // get and set light source
    light* get_light_source() { return light_source; }
    void set_light_source(point new_world_point) { world_point = new_world_point; }
    
    // get and set objects
    std::vector<sphere> get_objects() { return objects; }
    void set_object(const sphere& s) { objects.push_back(s); }

    // all world intersections
    std::vector<intersection> intersect_world(ray& ray);

    // our "hit" for all world intersections
    computations prepare_computations(const intersection& intersection, ray& ray);
};

#endif