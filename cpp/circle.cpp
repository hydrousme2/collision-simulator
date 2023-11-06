#include "circle.h"

// constructor
Circle::Circle(Vec2D pos, Vec2D vel, double radius) : pos(pos), vel(vel), radius(radius) { }

// getters
Vec2D Circle::getPos() {
    return pos;
}

Vec2D Circle::getVel() {
    return vel;
}

// setters
void Circle::setPos(Vec2D pos) {
    this->pos = pos;
}

void Circle::setVel(Vec2D vel) {
    this->vel = vel;
}

// other methods
double Circle::getRadius() {
    return radius;
}

void Circle::update(double dt) {
    pos = pos + vel * dt;
}