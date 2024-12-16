#include "ray.h"

point ray::position(float t) {
    return origin + direction * t;
}