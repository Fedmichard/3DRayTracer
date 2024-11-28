#include <iostream>

#include "math.h"

int main() {

    tuple t1(1.0f, 0.0f, 2.0f, 1.0f);
    tuple t2(1.0f, 0.0f, 2.0f, 0.0f);

    vector v1(1.0f, 2.0f, 3.0f);
    vector v2(2.0f, 3.0f, 4.0f);
    
    point p1(3.0f, 2.0f, 1.0f);
    point p2(5.0f, 6.0f, 7.0f);

    vector new_vec = vector::cross(v1, v2);
    float dot = vector::dot(v1, v2);

    std::string is_vector = new_vec.isVector() == 1 ? "Yes" : "No";
    std::string is_point = new_vec.isPoint() == 1 ? "Yes" : "No";

    std::cout << "Is it a Vector? " << is_vector << std::endl;
    std::cout << "Is it a Point? " << is_point << std::endl;
    std::cout << "New Tuple X: " << new_vec.getX() << std::endl;
    std::cout << "New Tuple Y: " << new_vec.getY() << std::endl;
    std::cout << "New Tuple Z: " << new_vec.getZ() << std::endl;
    std::cout << "New Tuple W: " << new_vec.getW() << std::endl;
    std::cout << "New Tuple Dot: " << dot << std::endl;

    return 0;
}