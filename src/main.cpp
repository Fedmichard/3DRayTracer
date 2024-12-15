#include <iostream>
#include <fstream>

#include "math.h"
#include "canvas.h"

const int width = 900;
const int height = 550;

struct projectile {
    point position;
    vector velocity;
};

struct environment {
    vector gravity;
    vector wind;
};

projectile tick(environment env, projectile proj) {
    point position(0.0f, 0.0f, 0.0f);
    vector velocity(0.0f, 0.0f, 0.0f);

    position = proj.position + proj.velocity;
    velocity = proj.velocity + env.gravity + env.wind;

    return projectile{.position = position, .velocity = velocity};
}

int main() {
    canvas c(width, height);
    color color1(0.0f, 1.0f, 1.0f);

    // environment
    environment e = {
        .gravity = {0.0f, -0.1f, 0.0f},
        .wind = {-0.01f, 0.0f, 0.0f}
    };

    // Projectile 
    vector velocity(1.0f, 1.8f, 0.0f);
    velocity.normalize() * 11.25f;

    projectile p = {
        .position = {0.0f, 1.0f, 0.0f},
        .velocity = velocity
    };

    while (true) {
        projectile new_p = tick(e, p);

        p = new_p;
        
        c.write_pixel(p.position.getX() * 24, height - p.position.getY() * 21, color1);

        if (new_p.position.getY() <= 0.0f) {
            break; // break if y hits 0
        }
    }

    std::ofstream ppm_file("trajectory.ppm");
    ppm_file << c.canvas_to_ppm();
    ppm_file.close();

    std::cout << "Trajectory saved as 'trajectory.ppm'" << std::endl;
    
    // matrix 4 test
    matrix4 mat(6);
    matrix4 mat4(
        1.0f, 2.0f, 3.0f, 4.0f,
        5.5f, 6.5f, 7.5f, 8.5f,
        9.0f, 10.0f, 11.0f, 12.0f,
        13.5f, 14.5f, 15.5f, 16.5f
    );
    matrix4 mat42(
        1.0f, 2.0f, 3.0f, 4.0f,
        5.5f, 6.5f, 7.5f, 8.5f,
        9.0f, 10.0f, 11.0f, 12.0f,
        13.5f, 14.5f, 15.5f, 16.5f
    );
    
    mat.print_matrix();
    mat4.print_matrix();

    // matrix 3 test
    matrix3 mat3(55);
    matrix3 mat32(
        -3.0f, 5.0f, 0.0f,
        1.0f, -2.0f, -7.0f,
        0.0f, 1.0f, 1.0f
    );
    matrix3 mat323(
        -3.0f, 5.0f, 0.0f,
        1.0f, -2.0f, -7.0f,
        0.0f, 1.0f, 1.0f
    );
    mat3.print_matrix();
    mat32.print_matrix();
    
    // matrix 2 test
    matrix2 mat2(55);
    matrix2 mat22(
        -3.0f, 5.0f,
        1.0f, -2.0f
    );
    matrix2 mat222(
        -3.0f, 5.0f,
        1.0f, -2.0f
    );
    mat2.print_matrix();
    mat22.print_matrix();

    if (mat32 == mat323) {
        std::cout << "Equal" << std::endl;
    } else {
        std::cout << "Not Equal" << std::endl;
    }

    tuple tuple1(1.0f, 2.0f, 3.0f, 0.0f);
    vector vector1(1.0f, 2.0f, 3.0f);
    point point1(0.0f, 2.0f, -3.0f);

    if (tuple1 == point1) {
        std::cout << "Equal" << std::endl;
    } else {
        std::cout << "Not Equal" << std::endl;
    }

    matrix2 A(
        1, 2, 
        5, 6
    );

    matrix2 B(
        -2, 1,
         3, 2
    );

    matrix2 C = A * B;
    C.print_matrix();

    matrix4 ttt(
        -6, 1, 1, 6,
        -8, 5, 8, 6,
        -1, 0, 8, 2,
        -7, 1, -1, 1
    );
    
    ttt.print_matrix();

    tuple bb(1, 2, 3, 1);

    vector vv(1, 2, 3);
    point pp(1, 2, 3);
    
    matrix4 transpotedTTT = ttt.transpose();

    transpotedTTT.print_matrix();

    matrix2 t2(
         1, 5,
        -3, 2
    ); 
    
    matrix3 t3(
         1, 2, 6,
        -5, 8, -4,
         2, 6, 4
    );

    std::cout << "XXXXXXXXXXXXXXXXXXX" << std::endl;
    std::cout << "cofactor(0,0): " << t3.cofactor(0, 0) << std::endl;
    std::cout << "cofactor(0,1): " << t3.cofactor(0, 1) << std::endl;
    std::cout << "cofactor(0,2): " << t3.cofactor(0, 2) << std::endl;
    std::cout << "Determinant: " << t3.determinant() << std::endl;
    std::cout << "XXXXXXXXXXXXXXXXXXX" << std::endl;

    matrix4 t4(
        -2, -8, 3, 5,
        -3, 1, 7, 3,
         1, 2, -9, 6,
        -6, 7, 7, -9
    );

    std::cout << "XXXXXXXXXXXXXXXXXXX" << std::endl;
    std::cout << "cofactor(0,0): " << t4.cofactor(0, 0) << std::endl;
    std::cout << "cofactor(0,1): " << t4.cofactor(0, 1) << std::endl;
    std::cout << "cofactor(0,2): " << t4.cofactor(0, 2) << std::endl;
    std::cout << "cofactor(0,3): " << t4.cofactor(0, 3) << std::endl;
    std::cout << "Determinant: " << t4.determinant() << std::endl;
    std::cout << "XXXXXXXXXXXXXXXXXXX" << std::endl;

    matrix4 AA(
        3, -9, 7, 3,
        3, -8, 2, -9,
        -4, 4, 4, 1,
        -6, 5, -1, 1
    );

    AA.print_matrix();
    matrix4 inverted = AA.inverse();
    inverted.print_matrix();

    matrix4 neww = AA * inverted;
    neww.print_matrix();

    matrix4 translation = matrix4::translation(5, -3, 2);
    matrix4 inverse = translation.inverse();
    vector vvv(-3, 4, 5);

    translation.print_matrix();
    vvv.printTuple();

    vector addition = translation * vvv;
    
    addition.printTuple();

    return 0;
}