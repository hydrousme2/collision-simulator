#include "../include/collision.h"

bool checkCollision(Particle& a, Particle& b) {
    Vec2d s = a.pos - b.pos; 
    Vec2d v = a.vel - b.vel;
    float r = a.radius + b.radius;

    float c1 = dot(s,s) - r*r;
    if (c1 < 0.0) return true;

    float a1 = dot(v, v);
    if (a1 < 0.00001f) return false;

    float b1 = dot(v, s);
    if (b1 >= 0.0) return false;

    float d1 = b1*b1 - a1*c1;
    if (d1 < 0.0) return false;

    return true;
}

void borderCollision(Particle& particle) {
    if(particle.pos.x < 0) {
        particle.pos.x = 0;
        particle.vel.x *= -1;
    }
    if(particle.pos.x > X_SIZE) {
        particle.pos.x = X_SIZE;
        particle.vel.x *= -1;
    }
    if(particle.pos.y < 0) {
        particle.pos.y = 0;
        particle.vel.y *= -1;
    }
    if(particle.pos.y > Y_SIZE) {
            particle.pos.y = Y_SIZE;
            particle.vel.y *= -1;
        }
}

void resolveCollision(Particle& a, Particle& b) {
    Vec2d x = a.pos - b.pos;
    x.normalize();

    Vec2d v1 = a.vel;
    Vec2d v2 = b.vel;

    float x1 = dot(x, v1);
    float x2 = dot(x, v2);

    float m1 = a.radius;
    float m2 = b.radius;

    float optimizedP = (2.0f * (x1 - x2)) / (m1 + m2);

    a.vel = v1 - x * optimizedP * m2;
    b.vel = v2 + x * optimizedP * m1;
}

void detectCollision(vector<Particle>& particles) {
    int N_C = particles.size();
    for(int i = 0; i < N_C; i++) {
        for(int j = i+1; j < N_C; j++) {
            if(checkCollision(particles[i], particles[j])) {
                resolveCollision(particles[i], particles[j]);
            }
        }
    }
}