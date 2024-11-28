#include "math.h"

bool tuple::isVector() {
    return w_value == 0.0f;
}

bool tuple::isPoint() {
    return w_value == 1.0f;
}

tuple tuple::operator+(tuple tuple1) {
    tuple new_tuple(x_value + tuple1.getX(), y_value + tuple1.getY(), z_value + tuple1.getZ(), w_value);

    return new_tuple;
}

tuple tuple::operator-(tuple tuple1) {
    tuple new_tuple(x_value - tuple1.getX(), y_value - tuple1.getY(), z_value - tuple1.getZ(), std::abs(w_value - tuple1.getW()));

    return new_tuple;
}

tuple tuple::operator-() {
    tuple new_tuple(-x_value, -y_value, -z_value, w_value);

    return new_tuple;
}

tuple tuple::operator*(float scalar) {
    tuple new_tuple(x_value * scalar, y_value * scalar, z_value * scalar, w_value);

    return new_tuple;
}

tuple tuple::operator/(float scalar) {
    tuple new_tuple(x_value / scalar, y_value / scalar, z_value / scalar, w_value);

    return new_tuple;
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

float tuple::magnitude() {
    return std::sqrt((x_value * x_value) + (y_value * y_value) + (z_value * z_value));
}

tuple tuple::normalize() {
    tuple new_tuple((x_value / tuple::magnitude()), (y_value / tuple::magnitude()), (z_value / tuple::magnitude()), w_value);

    return new_tuple;
}

float tuple::dot(tuple tuple1, tuple tuple2) {
    return (tuple1.x_value * tuple2.x_value) + (tuple1.y_value * tuple2.y_value) + (tuple1.z_value * tuple2.z_value);
}


tuple tuple::cross(tuple tuple1, tuple tuple2) {
    tuple new_tuple(
        (tuple1.y_value * tuple2.z_value) - (tuple1.z_value * tuple2.y_value),
        (tuple1.z_value * tuple2.x_value) - (tuple1.x_value * tuple2.z_value),
        (tuple1.x_value * tuple2.y_value) - (tuple1.y_value * tuple2.x_value),
        0.0f
    );

    return new_tuple;
}