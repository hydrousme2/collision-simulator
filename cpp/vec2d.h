#ifndef Vec2D_H
#define Vec2D_H

#include <cmath>
using namespace std;

class Vec2D {
public:
    double x;
    double y;

    // constructors
    Vec2D();
    Vec2D(double x, double y);

    // operator overloading
    Vec2D operator+(const Vec2D& other) const;
    Vec2D operator-(const Vec2D& other) const;
    Vec2D operator*(const Vec2D& other) const;
    Vec2D operator/(const Vec2D& other) const;
    Vec2D operator*(double scalar) const;
    Vec2D operator/(double scalar) const;
    bool operator==(const Vec2D& other) const;

    // other methods
    double dot(const Vec2D& other);
    double length();
    void normalize();
};

#endif