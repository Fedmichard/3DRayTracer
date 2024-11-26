#include "math.h"

float tuple::x() {
    return x_value; 
}

float tuple::y() {
    return y_value; 
}

float tuple::z() {
    return z_value; 
}

bool tuple::isEqual(tuple tuple1)  {
    if (isEqualFloats(x_value, tuple1.x_value)) {
        if (isEqualFloats(y_value, tuple1.y_value)) {
            if (isEqualFloats(z_value, tuple1.z_value)) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    } else {
        return false;
    }
}

bool tuple::isEqualFloats(float a, float b) {
    const float e = 0.00001;

    if (std::abs(a - b) < e) {
        return true;
    } else {
        return false;
    }
}


vector vector::add(tuple tuple1) { 
    vector new_tuple(x_value + tuple1.x(), y_value + tuple1.y(), z_value + tuple1.z());

    return new_tuple;
}