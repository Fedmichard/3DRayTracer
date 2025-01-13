#ifndef COMPUTATIONS_H
#define COMPUTATIONS_H

#include "math.h"
#include "sphere.h"

// data structure to hold all of our worlds intersections
class computations {
private:
    float _t = 0.0f; // intersection time (determines which interscetion is closest to camera)
    sphere* _object = nullptr; // the intersected object
    point _point; // 3d coords of intersection point
    vector _eyev; // vector pointing from the intersection point back to the camera (helps with reflections, and specular highlights)
    vector _normalv; // vector perpendicular to the surface of object at intersection point
    bool _inside = false; // is the computation inside the sphere?

public:
    computations() = default;
    computations(float t, sphere* object, point point, vector eyev, vector normalv, bool inside) :
    _t(t), _object(object), _point(point), _eyev(eyev), _normalv(normalv), _inside(inside) {};

    float get_t() { return _t; }
    sphere* get_object() const { return _object; }
    point get_point() const { return _point; }
    vector get_eyev() const { return _eyev; }
    vector get_normalv() const { return _normalv; }
    bool get_inside() const { return _inside; }

    void set_t(float t) { _t = t; }
    void set_object(sphere* object) { _object = object; }
    void set_point(point point) { _point = point; }
    void set_eyev(vector eyev) { _eyev = eyev; }
    void set_normalv(vector normalv) { _normalv = normalv; }
    void set_inside(bool inside) { _inside = inside; } 
};

#endif