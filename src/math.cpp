#include "math.h"

/******************************************************************************************************
 * Tuple functions
 *******************************************************************************************************/
bool tuple::isFloatEqual(float a, float b) {
    const float e = 0.00001;

    if (std::abs(a - b) < e) {
        return true;
    } else {
        return false;
    }
}

bool tuple::operator==(tuple tuple1)  {
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

bool tuple::isVector() {
    return w_value == 0.0f;
}

bool tuple::isPoint() {
    return w_value == 1.0f;
}

/******************************************************************************************************
 * Tuple overload functions
 *******************************************************************************************************/
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

void tuple::printTuple() {
    std::cout << "{ " << getX() << ", " << getY() << ", " << getZ() << ", " << getW() << " }" << std::endl;
}

/******************************************************************************************************
 * Point overload functions
 *******************************************************************************************************/
point point::operator+(vector vector1) {
    return point(getX() + vector1.getX(), getY() + vector1.getY(), getZ() + vector1.getZ());
}

vector point::operator+(point point1) {
    return vector(getX() + point1.getX(), getY() + point1.getY(), getZ() + point1.getZ());
}

point point::operator-(vector vector1) {
    return point(getX() - vector1.getX(), getY() - vector1.getY(), getZ() - vector1.getZ());
}

vector point::operator-(point point1) {
    return vector(getX() - point1.getX(), getY() - point1.getY(), getZ() - point1.getZ());
}

/******************************************************************************************************
 * Vector overload functions
 *******************************************************************************************************/
point vector::operator+(point point1) {
    return point(getX() + point1.getX(), getY() + point1.getY(), getZ() + point1.getZ());
}

vector vector::operator+(vector point1) {
    return vector(getX() + point1.getX(), getY() + point1.getY(), getZ() + point1.getZ());
}

vector vector::operator-(vector vector1) {
    return vector(getX() - vector1.getX(), getY() - vector1.getY(), getZ() - vector1.getZ());
}

/******************************************************************************************************
 * Color overload functions
 *******************************************************************************************************/
color color::operator+(color color1) {
    return color(getX() + color1.getX(), getY() + color1.getY(), getZ() + color1.getZ());
}

color color::operator-(color color1) {
    return color(getX() - color1.getX(), getY() - color1.getY(), getZ() - color1.getZ());
}

color color::operator*(float scalar) {
    return color(getX() * scalar, getY() * scalar, getZ() * scalar);
}

color color::operator*(color color1) {
    return color(getX() * color1.getX(), getY() * color1.getY(), getZ() * color1.getZ());
}

color color::operator/(float scalar) {
    return color(getX() / scalar, getY() / scalar, getZ() / scalar);
}

/******************************************************************************************************
 * Vector functions
 *******************************************************************************************************/
float vector::magnitude() {
    return std::sqrt((getX() * getX()) + (getY() * getY()) + (getZ() * getZ()));
}

tuple vector::normalize() {
    tuple new_tuple((getX() / magnitude()), (getY() / magnitude()), (getZ() / magnitude()), getW());

    return new_tuple;
}

float vector::dot(vector vector1, vector vector2) {
    return (vector1.getX() * vector2.getX())
         + (vector1.getY() * vector2.getY()
         + (vector1.getZ() * vector2.getZ()));
}


vector vector::cross(vector vector1, vector vector2) {
    vector new_tuple(
        (vector1.getY() * vector2.getZ()) - (vector1.getZ() * vector2.getY()),
        (vector1.getZ() * vector2.getX()) - (vector1.getX() * vector2.getZ()),
        (vector1.getX() * vector2.getY()) - (vector1.getY() * vector2.getX())
    );

    return new_tuple;
}

/******************************************************************************************************
 * Matrix 4
 *******************************************************************************************************/
int matrix4::get_rows() {
    return rows;
}

int matrix4::get_cols() {
    return cols;
}

void matrix4::setElement(int row, int col, float value) {
    p_matrix[row][col] = value;
}

bool matrix4::isInvertible() {
    if (determinant() == 0) {
        return false;
    }

    return true;
}

void matrix4::print_matrix() {
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            std::cout << " " << p_matrix[row][col];
        }
        std::cout << "\n";
    }
}

bool matrix4::operator==(matrix4 &matrix) {
    float e = 0.00001;

    if (rows != matrix.get_rows() || cols != matrix.get_cols()) {
        return false;
    }

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            if (p_matrix[row][col] - matrix.p_matrix[row][col] > e) {
                return false;
            }
        }
    }

    return true;
}

matrix4 matrix4::operator*(matrix4& matrix) {
    matrix4 m;

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            m.p_matrix[row][col] = p_matrix[row][0] * matrix.p_matrix[0][col] +
                                   p_matrix[row][1] * matrix.p_matrix[1][col] +
                                   p_matrix[row][2] * matrix.p_matrix[2][col] +
                                   p_matrix[row][3] * matrix.p_matrix[3][col];
        }
    }

    return m;
}

tuple matrix4::operator*(tuple& t) {
    float x = p_matrix[0][0] * t.getX() + p_matrix[0][1] * t.getY() +
                p_matrix[0][2] * t.getZ() + p_matrix[0][3] * t.getW();
    float y = p_matrix[1][0] * t.getX() + p_matrix[1][1] * t.getY() +
                p_matrix[1][2] * t.getZ() + p_matrix[1][3] * t.getW();
    float z = p_matrix[2][0] * t.getX() + p_matrix[2][1] * t.getY() +
                p_matrix[2][2] * t.getZ() + p_matrix[2][3] * t.getW();
    float w = p_matrix[3][0] * t.getX() + p_matrix[3][1] * t.getY() +
                p_matrix[3][2] * t.getZ() + p_matrix[3][3] * t.getW();

    return tuple(x, y, z, w);
}

point matrix4::operator*(point& t) {
    float x = p_matrix[0][0] * t.getX() + p_matrix[0][1] * t.getY() +
                p_matrix[0][2] * t.getZ() + p_matrix[0][3] * t.getW();
    float y = p_matrix[1][0] * t.getX() + p_matrix[1][1] * t.getY() +
                p_matrix[1][2] * t.getZ() + p_matrix[1][3] * t.getW();
    float z = p_matrix[2][0] * t.getX() + p_matrix[2][1] * t.getY() +
                p_matrix[2][2] * t.getZ() + p_matrix[2][3] * t.getW();
    return point(x, y, z);
}

vector matrix4::operator*(vector& t) {
    float x = p_matrix[0][0] * t.getX() + p_matrix[0][1] * t.getY() +
                p_matrix[0][2] * t.getZ() + p_matrix[0][3] * t.getW();
    float y = p_matrix[1][0] * t.getX() + p_matrix[1][1] * t.getY() +
                p_matrix[1][2] * t.getZ() + p_matrix[1][3] * t.getW();
    float z = p_matrix[2][0] * t.getX() + p_matrix[2][1] * t.getY() +
                p_matrix[2][2] * t.getZ() + p_matrix[2][3] * t.getW();

    return vector(x, y, z);
}

matrix4 matrix4::identityMatrix() {
    return matrix4(1.0f);
}

matrix4 matrix4::transpose() {
    matrix4 transposed;

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            transposed.p_matrix[col][row] = p_matrix[row][col];
        }
    }

    return transposed;
}

matrix4 matrix4::inverse() {
    matrix4 mat;

    if (!isInvertible()) {
        return mat;
    } else {
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                mat.p_matrix[row][col] = cofactor(row, col) / determinant();
            }
        }

        return mat.transpose();
    }
}

matrix3 matrix4::submatrix(int row, int col) {
    matrix3 mat;

    int r_sub = 0;
    for (int r = 0; r < rows; r++) {
        if (r == row) continue;

        int c_sub = 0;
        for (int c = 0; c < cols; c++) {
            if (c == col) continue;

            mat.setElement(r_sub, c_sub, p_matrix[r][c]);
            c_sub++;
        }
        r_sub++;
    }

    return mat;
}

float matrix4::minor(int row, int col) {
    return submatrix(row, col).determinant();
}

float matrix4::cofactor(int row, int col) {
    if ((row + col) % 2 != 0) {
        return -minor(row, col);
    }

    else return minor(row, col);
}

float matrix4::determinant() {
    return p_matrix[1][0] * cofactor(1, 0) +
           p_matrix[1][1] * cofactor(1, 1) +
           p_matrix[1][2] * cofactor(1, 2) +
           p_matrix[1][3] * cofactor(1, 3);
}

matrix4 matrix4::translation(float x, float y, float z) {
    matrix4 t = identityMatrix();

    t.p_matrix[0][3] = x;
    t.p_matrix[1][3] = y;
    t.p_matrix[2][3] = z;

    return t;
}

matrix4 matrix4::scaling(float x, float y, float z) {
    matrix4 t = identityMatrix();

    t.p_matrix[0][0] = x;
    t.p_matrix[1][1] = y;
    t.p_matrix[2][2] = z;

    return t;
}

/******************************************************************************************************
 * Matrix3
 *******************************************************************************************************/
int matrix3::get_rows() {
    return rows;
}

int matrix3::get_cols() {
    return cols;
}

void matrix3::setElement(int row, int col, float value) {
    p_matrix[row][col] = value;
}

bool matrix3::isInvertible() {
    if (determinant() == 0) {
        return false;
    }

    return true;
}

void matrix3::print_matrix() {
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            std::cout << " " << p_matrix[row][col];
        }
        std::cout << "\n";
    }
}

bool matrix3::operator==(matrix3 &matrix) {
    float e = 0.00001;

    if (rows != matrix.get_rows() || cols != matrix.get_cols()) {
        return false;
    }

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            if (p_matrix[row][col] - matrix.p_matrix[row][col] > e) {
                return false;
            }
        }
    }

    return true;
}

matrix3 matrix3::operator*(matrix3& matrix) {
    matrix3 m;

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            m.p_matrix[row][col] = p_matrix[row][0] * matrix.p_matrix[0][col] +
                                   p_matrix[row][1] * matrix.p_matrix[1][col] +
                                   p_matrix[row][2] * matrix.p_matrix[2][col];
        }
    }

    return m;
}

matrix3 matrix3::transpose() {
    matrix3 transposed;

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            transposed.p_matrix[col][row] = p_matrix[row][col];
        }
    }

    return transposed;
}

matrix3 matrix3::inverse() {
    matrix3 mat;

    if (!isInvertible()) {
        return mat;
    } else {
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                mat.p_matrix[row][col] = cofactor(row, col) / determinant();
            }
        }

        return mat.transpose();
    }
}

matrix2 matrix3::submatrix(int row, int col) {
    matrix2 mat;

    int r_sub = 0;
    for (int r = 0; r < rows; r++) {
        if (r == row) continue;

        int c_sub = 0;
        for (int c = 0; c < cols; c++) {
            if (c == col) continue;

            mat.setElement(r_sub, c_sub, p_matrix[r][c]);
            c_sub++;
        }
        r_sub++;
    }

    return mat;
}

float matrix3::minor(int row, int col) {
    return submatrix(row, col).determinant();
}

float matrix3::cofactor(int row, int col) {
    if ((row + col) % 2 != 0) {
        return -minor(row, col);
    }

    else return minor(row, col);
}

float matrix3::determinant() {
    return p_matrix[1][0] * cofactor(1, 0) +
           p_matrix[1][1] * cofactor(1, 1) +
           p_matrix[1][2] * cofactor(1, 2);
}

/******************************************************************************************************
 * Matrix2
 *******************************************************************************************************/
int matrix2::get_rows() {
    return rows;
}

int matrix2::get_cols() {
    return cols;
}

void matrix2::setElement(int row, int col, float value) {
    p_matrix[row][col] = value;
}

bool matrix2::isInvertible() {
    if (determinant() == 0) {
        return false;
    }

    return true;
}

void matrix2::print_matrix() {
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            std::cout << " " << p_matrix[row][col];
        }
        std::cout << "\n";
    }
}

bool matrix2::operator==(matrix2& matrix) {
    float e = 0.00001;

    if (rows != matrix.get_rows() || cols != matrix.get_cols()) {
        return false;
    }

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            if (p_matrix[row][col] - matrix.p_matrix[row][col] > e) {
                return false;
            }
        }
    }

    return true;
}

matrix2 matrix2::operator*(matrix2& matrix) {
    matrix2 m;

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            m.p_matrix[row][col] = p_matrix[row][0] * matrix.p_matrix[0][col] +
                                   p_matrix[row][1] * matrix.p_matrix[1][col];
        }
    }

    return m;
}

matrix2 matrix2::transpose() {
    matrix2 transposed;

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            transposed.p_matrix[col][row] = p_matrix[row][col];
        }
    }

    return transposed;
}

float matrix2::determinant() {
    return p_matrix[0][0] * p_matrix[1][1] - p_matrix[1][0] * p_matrix[0][1];
}