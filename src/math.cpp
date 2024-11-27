#include "math.h"

float tuple::getX() {
    return x_value; 
}

float tuple::getY() {
    return y_value; 
}

float tuple::getZ() {
    return z_value; 
}


float tuple::getW() {
    return w_value;
}

bool tuple::isVector() {
    return w_value == 0.0f;
}

bool tuple::isPoint() {
    return w_value == 1.0f;
}

bool tuple::isFloatEqual(float a, float b) {
    const float e = 0.00001;

    if (std::abs(a - b) < e) {
        return true;
    } else {
        return false;
    }
}

bool tuple::isTupleEqual(tuple tuple1)  {
    if (isFloatEqual(x_value, tuple1.x_value)) {
        if (isFloatEqual(y_value, tuple1.y_value)) {
            if (isFloatEqual(z_value, tuple1.z_value)) {
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

tuple tuple::operator+(tuple tuple1) {
    tuple new_tuple(x_value + tuple1.getX(), y_value + tuple1.getY(), z_value + tuple1.getZ(), w_value);

    return new_tuple;
}

tuple tuple::operator-(tuple tuple1) {
    tuple new_tuple(x_value - tuple1.getX(), y_value - tuple1.getY(), z_value - tuple1.getZ(), w_value);

    return new_tuple;
}