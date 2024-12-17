#include "intersection.h"
#include "sphere.h"
#include <algorithm>

std::vector<intersection> intersections(std::initializer_list<intersection> intersections_list) {
    return std::vector<intersection>(intersections_list);
}

intersection* hit(const std::vector<intersection>& xs) {
    intersection* hit_result = nullptr;

    for (const intersection& i : xs) {
        if (i.get_t() >= 0 && (!hit_result || i.get_t() < hit_result->get_t())) {
            hit_result = new intersection(i); // Use a new intersection to allocate memory for the pointer
        }
    }

    return hit_result;
}