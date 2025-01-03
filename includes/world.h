#ifndef WORLD_H
#define WORLD_H

#include "math.h"
#include "light.h"
#include "sphere.h"
#include <vector>

class world {
private:
    point world_point;
    std::vector<sphere> objects;
    light* light_source;

public:
    world() = default;

    point get_world_point() { return world_point; }
    void set_world_point(point new_world_point) { world_point = new_world_point; }
    
    point get_light_source() { return world_point; }
    void set_light_source(point new_world_point) { world_point = new_world_point; }
    
    point get_objects() { return world_point; }
    void set_objects(point new_world_point) { world_point = new_world_point; }
};

#endif