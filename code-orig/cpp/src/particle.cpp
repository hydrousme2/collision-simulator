#include "../include/particle.h"

Particle::Particle(Vec2d pos, Vec2d vel, double radius, int idx) : pos(pos), vel(vel), radius(radius), idx(idx) {}

void Particle::setvel(Vec2d vel) {
    this->vel = vel;
}
void Particle::setpos(Vec2d pos) {
    this->pos = pos;
}

bool Particle::operator==(const Particle& other) const {
    return idx == other.idx;
}

void Particle::update() {
    pos = pos + vel * dt;
    
    if(pos.x < 0) {
        pos.x = 0;
        vel.x *= -1;
    }
    if(pos.x > X_SIZE) {
        pos.x = X_SIZE;
        vel.x *= -1;
    }
    if(pos.y < 0) {
        pos.y = 0;
        vel.y *= -1;
    }
    if(pos.y > Y_SIZE) {
            pos.y = Y_SIZE;
            vel.y *= -1;
    }
    }

double distance(const Particle& lhs, const Particle& rhs) {
    return (lhs.pos - rhs.pos).magnitude();
}