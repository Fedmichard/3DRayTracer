#ifndef MATH_H
#define MATH_H

#include <cmath>
#include <vector>
#include <ostream>
#include <algorithm>
#include <iostream>

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
    // friend gives access to private variables?
    // operator overload for output
    friend std::ostream& operator<<(std::ostream& os, color& c) {
        os << static_cast<int>(std::round(std::clamp(c.getX(), 0.0f, 1.0f) * 255)) << " "
           << static_cast<int>(std::round(std::clamp(c.getY(), 0.0f, 1.0f) * 255)) << " "
           << static_cast<int>(std::round(std::clamp(c.getZ(), 0.0f, 1.0f) * 255));

        return os;
    };
};

class matrix4 {
private:
    int rows, cols;
    std::vector<std::vector<float>> p_matrix;

public:
    matrix4(int size) : rows(size), cols(size), p_matrix(size, std::vector<float>(size)) {
        p_matrix[0][0] = size;
        p_matrix[1][1] = size;
        p_matrix[2][2] = size;
        p_matrix[3][3] = size;
    };

    matrix4( float x1, float y1, float z1, float w1,
             float x2, float y2, float z2, float w2,
             float x3, float y3, float z3, float w3,
             float x4, float y4, float z4, float w4 ) : rows(4), cols(4), p_matrix(4, std::vector<float>(4)) {

            float nums[] = {
                x1, y1, z1, w1,
                x2, y2, z2, w2,
                x3, y3, z3, w3,
                x4, y4, z4, w4
            };

            int i = 0;

            for (int row = 0; row < rows; row++) {
                for (int col = 0; col < cols; col++) {
                    p_matrix[row][col] = nums[i];
                    i++;
                }
            }
             };

    int get_rows();
    int get_cols();

    void print_matrix();

};

class matrix3 : public matrix4 {
private:
    int rows, cols;
    std::vector<std::vector<float>> p_matrix;

public:
    matrix3();
    matrix3();

};

class matrix2 : public matrix4 {
private:
    int rows, cols;
    std::vector<std::vector<float>> p_matrix;

public:
    matrix2();
    matrix2();

};

#endif