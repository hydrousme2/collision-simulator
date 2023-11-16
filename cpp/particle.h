#ifndef PARTICLE_H
#define PARTICLE_H

#include "vec2d.h"


class Particle {
public:
    Vec2d pos, vel;
    double radius;
    int idx;

    Particle(Vec2d pos, Vec2d vel, double radius, int idx);

    void setvel(Vec2d vel);
    void setpos(Vec2d pos);

    bool operator==(const Particle& other) const;
    
    void update();
};

extern double distance(const Particle& lhs, const Particle& rhs);

#endif