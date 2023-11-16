#include "particle.h"

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
    }

double distance(const Particle& lhs, const Particle& rhs) {
    return (lhs.pos - rhs.pos).magnitude();
}