#ifndef COLLISION_H
#define COLLISION_H

#include "particle.h"
#include <vector>

extern bool checkCollision(Particle& a, Particle& b);
extern void borderCollision(Particle& particle);
extern void resolveCollision(Particle& a, Particle& b);
extern void detectCollision(vector<Particle>& particles);

#endif