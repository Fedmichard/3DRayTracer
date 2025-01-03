#include "lighting.h" 
#include <cmath>

color lighting(const material& material, const light& light, const point& position, const vector& eyev, const vector& normalv) {
    color effective_color = material.getColor() * light.getIntensity();
    vector lightsub = light.getPos() - position;
    vector lightv = lightsub.normalize();

    color ambient = effective_color * material.getAmbient();
    float light_dot_normal = std::max(vector::dot(lightv, normalv), 0.0f);

    color diffuse;
    color specular;

    if (light_dot_normal < 0) {
        diffuse = color(0.0f, 0.0f, 0.0f);
        specular = color(0.0f, 0.0f, 0.0f);
    } else {
        diffuse = effective_color * material.getDiffuse() * light_dot_normal;
        vector reflectv = ray::reflect(-lightv, normalv);
        float reflect_dot_eye = std::max(vector::dot(reflectv, eyev), 0.0f);

        if (reflect_dot_eye <= 0) {
            specular = color(0.0f, 0.0f, 0.0f);
        } else {
            float factor = pow(reflect_dot_eye, material.getShininess());
            specular = light.getIntensity() * material.getSpecular() * factor;
        }
    }

    return ambient + diffuse + specular;
}