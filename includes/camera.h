#ifndef CAMERA_H
#define CAMERA_H

#include "math.h"

class camera {
private:


public:
    camera() = default;

    matrix4 view_transform(const point& from, const point& to, vector& up);
};

#endif