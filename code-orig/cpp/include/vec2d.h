#ifndef VEC2D_H
#define VEC2D_H

#include <math.h>
using namespace std;

#include "config.h"

class Vec2d {
public:
    double x, y;

    Vec2d();
    Vec2d(double x, double y);

    Vec2d operator+(const Vec2d& rhs) const;
    Vec2d operator-(const Vec2d& rhs) const;
    Vec2d operator*(double rhs) const;
    Vec2d operator/(double rhs) const;

    double magnitude() const;
    void normalize();
};

extern double dot(const Vec2d& lhs, const Vec2d& rhs);
extern double dist(const Vec2d& lhs, const Vec2d& rhs);
extern double fRand(double fMin, double fMax);

#endif