#ifndef CAMERA_H
#define CAMERA_H

#include "math.h"

class camera {
private:
    float _hsize;
    float _vsize;
    float _fov;
    matrix4 _transform = matrix4(1);

public:
    camera() = default;
    camera(float hsize, float vsize, float fov) : _hsize(hsize), _vsize(vsize), _fov(fov) {};

    matrix4 get_transform() { return _transform; }
    matrix4 view_transform(const point& from, const point& to, vector& up);

    void set_hsize(float hsize) { _hsize = hsize;}
    float get_hsize() { return _hsize; }

    void set_vsize(float vsize) { _vsize = vsize; }
    float get_vsize() { return _vsize; }

    void set_fov(float fov) { _fov = fov; }
    float get_fov() { return _fov; }

    float pixel_size();

};

#endif