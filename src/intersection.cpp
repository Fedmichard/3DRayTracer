#include "intersection.h"
#include "sphere.h"

intersection::intersection(float t, sphere* object) {
    this->t = t;
    this->object = object;
};