#ifndef MATH_H
#define MATH_H

#include <cmath>

class tuple {
private:
    float x_value, y_value, z_value, w_value;

public:
    tuple(float x, float y, float z, float w) : x_value(x), y_value(y), z_value(z), w_value(w) {};

    float getX();
    float getY();
    float getZ();
    float getW();

    bool isFloatEqual(float a, float b);
    bool isTupleEqual(tuple tuple);

    bool isVector();
    bool isPoint();

    tuple operator+(tuple tuple);
    tuple operator-(tuple tuple);

    
};

#endif