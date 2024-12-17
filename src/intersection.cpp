#include "intersection.h"
#include "sphere.h"
#include <algorithm>

intersection::intersection(float t, sphere* object) {
    this->t = t;
    this->object = object;
};

std::vector<intersection> intersections(std::initializer_list<intersection> inters) {
    return std::vector<intersection>(inters);
}

intersection hit(std::vector<intersection> intersections) {
    intersection choice;  // Pointer to track the best intersection
    float shortest_distance = std::numeric_limits<float>::max();  // Start with a very large value

    for (int i = 0; i < intersections.size(); i++) {
        if (intersections[i].get_t() > 0 && intersections[i].get_t() < shortest_distance) {
            shortest_distance = intersections[i].get_t();
            choice = intersections[i];
        }
    }

    return choice;  // Dereference the best choice
}