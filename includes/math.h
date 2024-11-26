#ifndef MATH_H
#define MATH_H

#include <cmath>

class tuple {
private:
    float x_value, y_value, z_value, w;

public:
    tuple(float x, float y, float z, float w) : x_value(x), y_value(y), z_value(z), w(w) {};

    float x();
    float y();
    float z();

    bool isEqualFloats(float a, float b);
    bool isEqual(tuple tuple);
};

class vector : public tuple {
public:
    vector(float x, float y, float z) : tuple(x, y, z, 0.0f) {};
    vector add(tuple tuple);
};

class point : public tuple {
public:
    point(float x, float y, float z) : tuple(x, y, z, 1.0f) {};
    point add(tuple tuple);
};


#endif