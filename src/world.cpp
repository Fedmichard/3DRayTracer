#include "world.h"

std::vector<intersection> world::intersect_world(ray& ray) {
    std::vector<intersection> world_intersections;

    // loop through all the objects in the world
    // get the intersections for each object
    // insert each intersection into a list
    for (int i = 0; i < objects.size(); i++) {
        auto xs = objects[i].intersect(ray);
        
        for (int v = 0; v < xs.size(); v++) {
            world_intersections.push_back(xs[v]);
        }
    }
    
    // lambda function used to sort the list of intersections based on their t values
    std::sort(world_intersections.begin(), world_intersections.end(), [](const intersection& a, const intersection& b) {
        return a.get_t() < b.get_t();
    });

    // return list
    return world_intersections;
}

computations world::prepare_computations(const intersection& inter, ray& r) {
    computations comps;

    comps.set_t(inter.get_t());
    comps.set_object(inter.get_object());
    comps.set_point(r.position(comps.get_t()));
    comps.set_eyev(-r.get_direction());
    comps.set_normalv(comps.get_object()->normal_at(comps.get_point()));

    return comps;
}