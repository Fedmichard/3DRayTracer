#ifndef MATH_H
#define MATH_H

#include <cmath>

class tuple {
private:
    //                               1.0f = Point, 0.0f = Vector
    float x_value, y_value, z_value, w_value;

public:
    tuple(float x, float y, float z, float w) : x_value(x), y_value(y), z_value(z), w_value(w) {};

    // Getter functions for x, y, z, w values
    float getX() { return x_value; }
    float getY() { return y_value; }
    float getZ() { return z_value; }
    float getW() { return w_value; }

    // Functions to check tuple equality
    bool isFloatEqual(float a, float b);
    bool isTupleEqual(tuple tuple);

    // Functions to check whether a tuple is a vector or point
    bool isVector();
    bool isPoint();
    
    // Operator overload functions for tuples
    tuple operator+(tuple tuple); // add 2 tuples
    tuple operator-(tuple tuple); // subtract 2 tuples
    tuple operator-(); // negative a tuple
    tuple operator*(float scalar); // scalar multiplication
    tuple operator/(float scalar); // scalar division

    // math functions
    float magnitude(); // get the magnitude of a tuple
    tuple normalize(); // normalize a vector
    // Made into a static so it can be called without an instance of tuple
    static float dot(tuple tuple1, tuple tuple2); // dot product
    static tuple cross(tuple tuple1, tuple tuple2);
};

#endif