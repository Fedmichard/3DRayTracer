#include <iostream>
#include <fstream>

#include "math.h"
#include "canvas.h"

const int width = 950;
const int height = 500;

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

    point origin(0, 0, 0);

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

    point pp(1, 0, 1);
    matrix4 A = matrix4::rotation_x(M_PI / 2);
    matrix4 B = matrix4::scaling(5, 5, 5);
    matrix4 C = matrix4::translation(10, 5, 7);

    point p2 = A * pp;
    point p3 = B * p2;
    point p4 = C * p3;

    p2.printTuple();
    p3.printTuple();
    p4.printTuple();

    point p5 = B * C * A * pp;

    p5.printTuple();

    return 0;
}