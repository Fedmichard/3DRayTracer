#include "math.h"

bool tuple::isVector() {
    return w_value == 0.0f;
}

bool tuple::isPoint() {
    return w_value == 1.0f;
}

tuple tuple::operator+(tuple tuple1) {
    if ((w_value == 1.0f) && (tuple1.getW() == 1.0f)) {
        return tuple(x_value + tuple1.getX(), y_value + tuple1.getY(), z_value + tuple1.getZ(), 0.0f);
    }
    
    if ((w_value == 1.0f) && (tuple1.getW() == 0.0f)) {
        return tuple(x_value + tuple1.getX(), y_value + tuple1.getY(), z_value + tuple1.getZ(), 1.0f);
    }
    
    if ((w_value == 0.0f) && (tuple1.getW() == 1.0f)) {
        return tuple(x_value + tuple1.getX(), y_value + tuple1.getY(), z_value + tuple1.getZ(), 1.0f);
    }

    return tuple(x_value + tuple1.getX(), y_value + tuple1.getY(), z_value + tuple1.getZ(), w_value);
}

tuple tuple::operator-(tuple tuple1) {
    if ((w_value == 1.0f) && (tuple1.getW() == 1.0f)) {
        return tuple(x_value - tuple1.getX(), y_value - tuple1.getY(), z_value - tuple1.getZ(), 0.0f);
    }
    
    if ((w_value == 1.0f) && (tuple1.getW() == 0.0f)) {
        return tuple(x_value - tuple1.getX(), y_value - tuple1.getY(), z_value - tuple1.getZ(), 1.0f);
    }
    
    if ((w_value == 0.0f) && (tuple1.getW() == 1.0f)) {
        return tuple(x_value - tuple1.getX(), y_value - tuple1.getY(), z_value - tuple1.getZ(), 0.0f);
    }

    return tuple(x_value - tuple1.getX(), y_value - tuple1.getY(), z_value - tuple1.getZ(), w_value);
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

float vector::magnitude() {
    return std::sqrt((getX() * getX()) + (getY() * getY()) + (getZ() * getZ()));
}

tuple vector::normalize() {
    tuple new_tuple((getX() / magnitude()), (getY() / magnitude()), (getZ() / magnitude()), getW());

    return new_tuple;
}

float vector::dot(vector vector1, vector vector2) {
    return (vector1.getX() * vector2.getX()) + (vector1.getY() * vector2.getY() + (vector1.getZ() * vector2.getZ()));
}


vector vector::cross(vector vector1, vector vector2) {
    vector new_tuple(
        (vector1.getY() * vector2.getZ()) - (vector1.getZ() * vector2.getY()),
        (vector1.getZ() * vector2.getX()) - (vector1.getX() * vector2.getZ()),
        (vector1.getX() * vector2.getY()) - (vector1.getY() * vector2.getX())
    );

    return new_tuple;
}