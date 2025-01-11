#ifndef COMPUTATIONS_H
#define COMPUTATIONS_H

#include "math.h"
#include "sphere.h"

// data structure to hold all of our worlds intersections
class computations {
private:
    float _t;
    sphere* _object;
    point _point;
    vector _eyev;
    vector _normalv;

public:
    computations() = default;
    computations(float t, sphere* object, point point, vector eyev, vector normalv) :
    _t(t), _object(object), _point(point), _eyev(eyev), _normalv(normalv) {};

    float get_t() { return _t; }
    sphere* get_object() { return _object; }
    point get_point() { return _point; }
    vector get_eyev() { return _eyev; }
    vector get_normalv() { return _normalv; }

    void set_t(float t) { _t = t; }
    void set_object(sphere* object) { _object = object; }
    void set_point(point point) { _point = point; }
    void set_eyev(vector eyev) { _eyev = eyev; }
    void set_normalv(vector normalv) { _normalv = normalv; }
};

#endif