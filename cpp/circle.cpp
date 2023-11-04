#include "circle.h"

Circle::Circle(Vec2D pos, Vec2D vel, double radius) : pos(pos), vel(vel), radius(radius) { }

Vec2D Circle::getPos() {
    return pos;
}

Vec2D Circle::getVel() {
    return vel;
}

void Circle::setPos(Vec2D pos) {
    this->pos = pos;
}

void Circle::setVel(Vec2D vel) {
    this->vel = vel;
}

double Circle::getRadius() {
    return radius;
}

void Circle::update(double dt) {
    pos = pos + vel * dt;
}