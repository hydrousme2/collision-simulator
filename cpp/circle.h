#ifndef CIRCLE_H
#define CIRCLE_H

#include "vec2d.h"

class Circle {
public:
    // constructor
    Circle(Vec2D pos, Vec2D vel, double radius);

    // getters
    Vec2D getPos();
    Vec2D getVel();

    // setters
    void setPos(Vec2D pos);
    void setVel(Vec2D vel);

    // other methods
    double getRadius();
    void update(double dt);

private:
    Vec2D pos;
    Vec2D vel;
    double radius;
};

#endif
