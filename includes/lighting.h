#ifndef LIGHTING_H
#define LIGHTING_H

#include "math.h"
#include "material.h"
#include "light.h"
#include "ray.h"

color lighting(const material& material, const light& light, const point& position, const vector& eyev, const vector& normalv);

#endif