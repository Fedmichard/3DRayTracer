#ifndef MATH_H
#define MATH_H

#include <cmath>
#include <vector>
#include <ostream>
#include <algorithm>
#include <iostream>

// forward class declarations
class tuple;
class point;
class vector;
class color;
class matrix4;
class matrix3;
class matrix2;

// tuple class
class tuple {
private:
    float x_value, y_value, z_value, w_value; // 1.0f = Point, 0.0f = Vector

public:
    // default tuple constructor with initialization list
    tuple(float x, float y, float z, float w) : x_value(x), y_value(y), z_value(z), w_value(w) {};
    
    // Operator overload functions for tuples
    bool operator==(tuple tuple);
    tuple operator+(tuple tuple); // add 2 tuples
    tuple operator-(tuple tuple); // subtract 2 tuples
    tuple operator-(); // negative a tuple
    tuple operator*(float scalar); // scalar multiplication
    tuple operator/(float scalar); // scalar division

    // Getter functions for x, y, z, w values
    float getX() { return x_value; }
    float getY() { return y_value; }
    float getZ() { return z_value; }
    float getW() { return w_value; }

    // Functions to check tuple equality
    bool isFloatEqual(float a, float b);

    // Functions to check whether a tuple is a vector or point
    bool isVector();
    bool isPoint();

    // print a tuple formatted
    void printTuple();
};

// point class which inherits from tuple
class point : public tuple {
public:
    // default tuple constructor with initialization list
    point(float x, float y, float z) : tuple(x, y, z, 1.0f) {}

    // operator overloading functions
    point operator+(vector vector);
    vector operator+(point point);
    point operator-(vector vector);
    vector operator-(point point);
};

// vector class which inherits from tuple
class vector : public tuple {
public:
    // default tuple constructor with initialization list
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

// color class which inherits from tuple
class color : public tuple {
public:
    // default tuple constructor with initialization list
    color(float r, float g, float b) : tuple(r, g, b, 1.0f) {}

    // operator overloading functions
    color operator+(color color);
    color operator-(color color);
    color operator*(float scalar); // scalar multiplication
    color operator*(color color);
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

// matrix 4 class
class matrix4 {
private:
    // default amount of rows and columns inside of our matrix
    int rows = 4;
    int cols = 4;
    // 2D vector array or matrix
    std::vector<std::vector<float>> p_matrix;

public:
    // default constructor
    matrix4() : p_matrix(4, std::vector<float>(4)) {
        // set every value of matrix to 0
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                p_matrix[row][col] = 0.0f; 
            }
        }
    };

    // defines x, y, z, w diagonally
    matrix4(int num) : p_matrix(4, std::vector<float>(4)) {
        p_matrix[0][0] = num; // 1
        p_matrix[1][1] = num; //    2
        p_matrix[2][2] = num; //        3
        p_matrix[3][3] = num; //            4
    };

    // manually input matrix
    matrix4( float x1, float y1, float z1, float w1,
             float x2, float y2, float z2, float w2,
             float x3, float y3, float z3, float w3,
             float x4, float y4, float z4, float w4 ) : p_matrix(4, std::vector<float>(4)) {

        // number array to store all of the incoming points
        float nums[] = {
            x1, y1, z1, w1,
            x2, y2, z2, w2,
            x3, y3, z3, w3,
            x4, y4, z4, w4
        };

        // value for incrementing through number array
        int i = 0;

        // set values of matrix
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                p_matrix[row][col] = nums[i];
                i++;
            }
        }
    };

    // operator overloading functions
    bool operator==(matrix4& matrix);
    matrix4 operator*(matrix4& matrix);
    tuple operator*(tuple& tuple); // multiplying matrix by a tuple

    // getter functions for rows and cols
    int get_rows();
    int get_cols();

    // setter functions for elements
    void setElement(int row, int col, float value);

    // check if matrix is invertible
    bool isInvertible();

    // function for matrix printing
    void print_matrix();

    // identity matrix
    matrix4 identityMatrix();
    matrix4 transpose();
    matrix4 inverse();
    matrix3 submatrix(int row, int col);
    float minor(int row, int col);
    float cofactor(int row, int col);
    float determinant();
};

class matrix3 {
private:
    // default amount of rows and columns inside of our matrix
    int rows = 3;
    int cols = 3;
    // 2D vector array or matrix
    std::vector<std::vector<float>> p_matrix;

public: 
    // default constructor
    matrix3() : p_matrix(3, std::vector<float>(3)) {
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                // set every value of matrix to 0
                p_matrix[row][col] = 0.0f;
            }
        }
    };

    // defines x, y, z diagonally
    matrix3(int num) : p_matrix(3, std::vector<float>(3)) {
        p_matrix[0][0] = num; // 1
        p_matrix[1][1] = num; //    2
        p_matrix[2][2] = num; //        3
    };

    // manually input matrix
    matrix3( float x1, float y1, float z1,
             float x2, float y2, float z2,
             float x3, float y3, float z3 ) : p_matrix(3, std::vector<float>(3)) {

        // number array to store all of the incoming points
        float nums[] = {
            x1, y1, z1,
            x2, y2, z2,
            x3, y3, z3,
        };

        // value for incrementing through number array
        int i = 0;

        // set values of matrix
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                p_matrix[row][col] = nums[i];
                i++;
            }
        }
    };
    
    // operator overloading functions
    bool operator==(matrix3 &matrix);
    matrix3 operator*(matrix3& matrix);

    // getter functions for rows and cols
    int get_rows();
    int get_cols();

    // setter functions for elements
    void setElement(int row, int col, float value);

    // check if matrix is invertible
    bool isInvertible();

    // function for matrix printing
    void print_matrix();
    
    // identity matrix
    matrix3 identityMatrix();
    matrix3 transpose();
    matrix3 inverse();
    matrix2 submatrix(int row, int col);
    float minor(int row, int col);
    float cofactor(int row, int col);
    float determinant();
};

class matrix2 {
private:
    // default amount of rows and columns inside of our matrix
    int rows = 2;
    int cols = 2;
    // 2D vector array or matrix
    std::vector<std::vector<float>> p_matrix;
public:
    // default constructor
    matrix2() : p_matrix(2, std::vector<float>(2)) {
        // set every value of matrix to 0
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                p_matrix[row][col] = 0.0f;
            }
        }
    };

    // defines x, y diagonally
    matrix2(int num) : p_matrix(2, std::vector<float>(2)) {
        p_matrix[0][0] = num; // 1
        p_matrix[1][1] = num; //    2
    };

    // manually input matrix
    matrix2( float x1, float y1,
             float x2, float y2 ) : p_matrix(2, std::vector<float>(2)) {

        // number array to store all of the incoming points
        float nums[] = {
            x1, y1,
            x2, y2
        };

        // value for incrementing through number array
        int i = 0;

        // set values of matrix
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                p_matrix[row][col] = nums[i];
                i++;
            }
        }
    };

    // operator overloading functions
    bool operator==(matrix2& matrix);
    matrix2 operator*(matrix2& matrix);

    // getter functions for rows and cols
    int get_rows();
    int get_cols();

    // setter functions for elements
    void setElement(int row, int col, float value);

    // check if matrix is invertible
    bool isInvertible();

    // functions
    void print_matrix(); // function for matrix printing
    
    matrix2 identityMatrix(); // identity matrix
    matrix2 transpose();

    float determinant();

};

#endif