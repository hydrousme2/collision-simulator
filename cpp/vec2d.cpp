#include "vec2d.h"

Vec2d::Vec2d() : x(0), y(0) {}
Vec2d::Vec2d(double x, double y) : x(x), y(y) {}

Vec2d Vec2d::operator+(const Vec2d& rhs) const {
    return Vec2d(x + rhs.x, y + rhs.y);
}
Vec2d Vec2d::operator-(const Vec2d& rhs) const {
    return Vec2d(x - rhs.x, y - rhs.y);
}
Vec2d Vec2d::operator*(double rhs) const {
    return Vec2d(x * rhs, y * rhs);
}
Vec2d Vec2d::operator/(double rhs) const {
    return Vec2d(x / rhs, y / rhs);
}

double Vec2d::magnitude() const {
    return sqrt(x * x + y * y);
}
void Vec2d::normalize() {
    double m = magnitude();
    x /= m;
    y /= m;
}


double dot(const Vec2d& lhs, const Vec2d& rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y;
}

double dist(const Vec2d& lhs, const Vec2d& rhs) {
    return (lhs - rhs).magnitude();
}

double fRand(double fMin, double fMax) {
    // https://stackoverflow.com/a/2704552
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}