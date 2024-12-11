#ifndef MATH_H
#define MATH_H

#include <cmath>
#include <ostream>
#include <algorithm>

class tuple;
class point;
class vector;
class color;

class tuple {
private:
    float x_value, y_value, z_value, w_value; // 1.0f = Point, 0.0f = Vector

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
};

class point : public tuple {
public:
    point(float x, float y, float z) : tuple(x, y, z, 1.0f) {}

    // operator overloading functions
    point operator+(vector vector);
    vector operator+(point point);
    point operator-(vector vector);
    vector operator-(point point);
};

class vector : public tuple {
public:
    vector(float x, float y, float z) : tuple(x, y, z, 0.0f) {}

    // Operator overloading
    vector operator+(vector vector);
    point operator+(point point);
    vector operator-(vector vector);
   
    // Math functions
    float magnitude(); // get the magnitude of a vector
    tuple normalize(); // normalize a vector

    // Made into a static so it can be called without an instance of tuple
    static float dot(vector vector1, vector vector2); // dot product
    static vector cross(vector vector1, vector vector2);
};

class color : public tuple {
public:
    color(float r, float g, float b) : tuple(r, g, b, 1.0f) {}

    // operator overloading functions
    color operator+(color color);
    color operator-(color color);
    color operator*(float scalar); // scalar multiplication
    color operator*(color color1);
    color operator/(float scalar); // scalar division

    // handle output
    friend std::ostream& operator<<(std::ostream& os, color& c) {
        os << static_cast<int>(std::round(std::clamp(c.getX(), 0.0f, 1.0f) * 255)) << " "
           << static_cast<int>(std::round(std::clamp(c.getY(), 0.0f, 1.0f) * 255)) << " "
           << static_cast<int>(std::round(std::clamp(c.getZ(), 0.0f, 1.0f) * 255));

        return os;
    };
};

#endif