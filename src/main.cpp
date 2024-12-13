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
        0, 9, 3, 0,
        9, 8, 0, 8,
        1, 8, 5, 3,
        0, 0, 5, 8
    );
    
    ttt.print_matrix();

    tuple bb(1, 2, 3, 1);

    vector vv(1, 2, 3);
    point pp(1, 2, 3);
    
    matrix4 transpotedTTT = ttt.transpose();

    transpotedTTT.print_matrix();

    
    matrix3 t3(
        0, 9, 3,
        9, 8, 0,
        1, 8, 5
    );

    matrix3 transposedT3 = t3.transpose();

    matrix2 t2(
         1, 5,
        -3, 2
    );

    matrix2 transposedT2 = t2.transpose();

    t3.print_matrix();
    transposedT3.print_matrix();
    t2.print_matrix();
    transposedT2.print_matrix();
    
    ttt.identityMatrix().print_matrix();
    ttt.identityMatrix().transpose().print_matrix();

    std::cout << "Determinant: " << t2.determinant() << std::endl;
    return 0;
}