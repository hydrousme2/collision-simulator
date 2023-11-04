#ifndef Vec2D_H
#define Vec2D_H

#include <cmath>
using namespace std;

class Vec2D {
public:
    double x;
    double y;

    Vec2D() : x(0.0), y(0.0) {}
    Vec2D(double x, double y) : x(x), y(y) {}

    Vec2D operator+(const Vec2D& other) const {
        return Vec2D(x + other.x, y + other.y);
    }

    Vec2D operator-(const Vec2D& other) const {
        return Vec2D(x - other.x, y - other.y);
    }

    Vec2D operator*(double scalar) const {
        return Vec2D(x * scalar, y * scalar);
    }

    Vec2D operator/(double scalar) const {
        if (scalar != 0.0f) {
            return Vec2D(x / scalar, y / scalar);
        }
        return Vec2D();
    }

    double dot(const Vec2D& other) {
        return (x * other.x + y * other.y);
    }

    double length() {
        return sqrt(x * x + y * y);
    }

    void normalize() {
        double len = length();
        if (len != 0.0f) {
            x /= len;
            y /= len;
        }
    }
};

#endif