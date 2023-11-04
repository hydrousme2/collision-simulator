#ifndef CIRCLE_H
#define CIRCLE_H

#include "vec2d.h"

class Circle {
public:
    Circle(Vec2D pos, Vec2D vel, double radius);
    Vec2D getPos();
    Vec2D getVel();
    void setPos(Vec2D pos);
    void setVel(Vec2D vel);
    double getRadius();
    void update(double dt);

private:
    Vec2D pos;
    Vec2D vel;
    double radius;
};

#endif
