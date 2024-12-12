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

    std::cout << "Trajector saved as 'trajectory.ppm'" << std::endl;

    matrix4 mat(4);
    matrix4 mat2(
        1.0f, 2.0f, 3.0f, 4.0f,
        5.5f, 6.5f, 7.5f, 8.5f,
        9.0f, 10.0f, 11.0f, 12.0f,
        13.5f, 14.5f, 15.5f, 16.5f
    );

    mat.print_matrix();
    mat2.print_matrix();
    
    return 0;
}