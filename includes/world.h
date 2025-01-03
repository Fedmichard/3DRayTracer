#ifndef WORLD_H
#define WORLD_H

#include "math.h"

class world {
private:
    point world_point;

public:
    world() = default;

    point get_world_point() { return world_point; }
    void set_world_point(point new_world_point) { world_point = new_world_point; }
};

#endif