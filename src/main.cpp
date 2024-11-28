#include <iostream>

#include "math.h"

int main() {
    tuple tuple1(1.0f, 2.0f, 3.0f, 0.0f);
    tuple tuple2(2.0f, 3.0f, 4.0f, 0.0f);
    tuple tuple4(1.0f, 2.0f, 3.0f, 0.0f);
    tuple tuple3 = tuple4.normalize();

    std::cout << "Tuple 3 x: " << tuple3.getX() << std::endl;
    std::cout << "Tuple 3 y: " << tuple3.getY() << std::endl;
    std::cout << "Tuple 3 z: " << tuple3.getZ() << std::endl;
    std::cout << "Tuple 3 w: " << tuple3.getW() << std::endl;
    std::cout << "" << std::endl;
    std::string isVector = tuple3.isVector() ? "True" : "False";
    std::string isPoint = tuple3.isPoint() ? "True" : "False";
    std::cout << "Is Tuple3 Vector?: " << isVector << std::endl;
    std::cout << "Is Tuple3 Point?: " << isPoint << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Tuple 3 Magnitude: " << tuple3.magnitude() << std::endl;
    std::cout << "Dot: " << tuple::dot(tuple1, tuple2) << std::endl;
    tuple tuple6 = tuple::cross(tuple2, tuple1);
    std::cout << "Cross of tuple1 and tuple2: " << "X: " << tuple6.getX() << " Y: " << tuple6.getY() << " Z: " << tuple6.getZ() << std::endl;

    return 0;
}