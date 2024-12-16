#ifndef INTERSECTION_H
#define INTERSECTION_H

class sphere;

// we'll store each intersection as a class rather than a vector
// this way we can attach the time and object of each intersection
class intersection {
private:
    float t;
    sphere* object;

public:
    intersection(float t, sphere* object);

    float get_t() { return t; }
    sphere* get_object() { return object; }
};

#endif