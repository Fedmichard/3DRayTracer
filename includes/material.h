#ifndef MATERIAL_H
#define MATERIAL_H

#include "math.h"

class material {
private:
    color col = color(1, 1, 1);
    float amb = 0.1f;
    float diff = 0.9f;
    float spec = 0.9f;
    float shine = 200.0f;

public:
    material() = default;
    material(color color, float ambient, float diffuse, float specular, float shininess) :
             col(color), amb(ambient), diff(diffuse), spec(specular), shine(shininess) {};

    void setColor(color color) { col = color; }
    color getColor() const { return col; }

    void setAmbient(float ambient) { amb = ambient; }
    float getAmbient() const { return amb; }

    void setDiffuse(float diffuse) { diff = diffuse; }
    float getDiffuse() const { return diff; }

    void setSpecular(float specular) { spec = specular; }
    float getSpecular() const { return spec; }

    void setShininess(float shininess) {shine = shininess; }
    float getShininess() const { return shine; }
};

#endif