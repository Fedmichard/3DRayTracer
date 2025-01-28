#include "camera.h"

matrix4 camera::view_transform(const point& from, const point& to, vector& up) {
    vector forward = (to - from).normalize();
    vector upn = up.normalize();
    vector left = vector::cross(forward, upn);
    vector true_up = vector::cross(left, forward);

    matrix4 orientation( 
        left.getX(), left.getY(), left.getZ(), 0,
        true_up.getX(), true_up.getY(), true_up.getZ(), 0,
        -forward.getX(), -forward.getY(), -forward.getZ(), 0,
        0, 0, 0, 1
    );

    _transform = orientation * orientation.translation(-from.getX(), -from.getY(), -from.getZ());
    return orientation * orientation.translation(-from.getX(), -from.getY(), -from.getZ());
}

float camera::pixel_size() {

}