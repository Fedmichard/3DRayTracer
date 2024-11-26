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
    point point1(-4.0f, 20.0f, 15.0f);
    vector vector1(-4.0f, 20.0f, 15.0f);

    std::string isEqual = vector1.isEqual(point1) == 1 ? "true\n" : "false\n";

    std::cout << isEqual << std::endl;
    std::cout << point1.y() << std::endl;
    std::cout << vector1.z() << std::endl;
    std::cout << tuple1.x() << std::endl;

    tuple tuple_new = vector1.add(point1);
    
    std::cout << tuple_new.x() << std::endl;
    std::cout << tuple_new.y() << std::endl;
    std::cout << tuple_new.z() << std::endl;

    return 0;
}