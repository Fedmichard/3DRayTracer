#include <iostream>

#include "math.h"


#include <vector>

/**********************************************************************
 * MATH FUNCTIONS
 **********************************************************************/



/*
bool compareEqualTuples(tuple tuple1, tuple tuple2) {
    if (compareEqualFloats(tuple1.x, tuple2.x)) {
        if (compareEqualFloats(tuple1.y, tuple2.y)) {
            if (compareEqualFloats(tuple1.z, tuple2.z)) {
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
*/

int main() {
    tuple tuple1(1.0f, 5.0f, 3.0f, 1.0f);
    tuple tuple2(1.0f, 5.0f, 3.0f, 1.0f);

    std::cout << "Tuple 1 x: " << tuple1.getX() << std::endl;
    std::cout << "Tuple 1 y: " << tuple1.getY() << std::endl;
    std::cout << "Tuple 1 z: " << tuple1.getZ() << std::endl;
    std::cout << "Tuple 1 w: " << tuple1.getW() << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Tuple 2 x: " << tuple2.getX() << std::endl;
    std::cout << "Tuple 2 y: " << tuple2.getY() << std::endl;
    std::cout << "Tuple 2 z: " << tuple2.getZ() << std::endl;
    std::cout << "Tuple 2 w: " << tuple2.getW() << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Is Tuple Vector?: " << tuple1.isVector() << std::endl;
    std::cout << "Is Tuple Point?: " << tuple1.isPoint() << std::endl;
    std::cout << "Is Tuple Vector?: " << tuple2.isVector() << std::endl;
    std::cout << "Is Tuple Point?: " << tuple2.isPoint() << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Are they equal?: " << tuple1.isTupleEqual(tuple2) << std::endl;

    tuple tuple3 = tuple1 + tuple2;

    std::cout << "Tuple 3 x: " << tuple3.getX() << std::endl;
    std::cout << "Tuple 3 y: " << tuple3.getY() << std::endl;
    std::cout << "Tuple 3 z: " << tuple3.getZ() << std::endl;
    std::cout << "Tuple 3 w: " << tuple3.getW() << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Is Tuple Vector?: " << tuple3.isVector() << std::endl;
    std::cout << "Is Tuple Point?: " << tuple3.isPoint() << std::endl;
    
    tuple tuple4 = tuple1 - tuple3;

    std::cout << "Tuple 3 x: " << tuple4.getX() << std::endl;
    std::cout << "Tuple 3 y: " << tuple4.getY() << std::endl;
    std::cout << "Tuple 3 z: " << tuple4.getZ() << std::endl;
    std::cout << "Tuple 3 w: " << tuple4.getW() << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Is Tuple Vector?: " << tuple4.isVector() << std::endl;
    std::cout << "Is Tuple Point?: " << tuple4.isPoint() << std::endl;

    return 0;
}