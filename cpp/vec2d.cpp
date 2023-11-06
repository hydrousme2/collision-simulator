#include "vec2d.h"

// Constructors
Vec2D::Vec2D() : x(0.0), y(0.0) {}

Vec2D::Vec2D(double x, double y) : x(x), y(y) {}

// operator overloading
Vec2D Vec2D::operator+(const Vec2D& other) const {
    return Vec2D(x + other.x, y + other.y);
}

Vec2D Vec2D::operator-(const Vec2D& other) const {
    return Vec2D(x - other.x, y - other.y);
}

Vec2D Vec2D::operator*(const Vec2D& other) const {
    return Vec2D(x * other.x, y * other.y);
}

Vec2D Vec2D::operator/(const Vec2D& other) const {
    return Vec2D(x / other.x, y / other.y);
}

Vec2D Vec2D::operator*(double scalar) const {
    return Vec2D(x * scalar, y * scalar);
}

bool Vec2D::operator==(const Vec2D& other) const {
    return (x == other.x) && (y == other.y);
}

Vec2D Vec2D::operator/(double scalar) const {
    return Vec2D(x / scalar, y / scalar);
}

// other methods
double Vec2D::dot(const Vec2D& other) {
    return (x * other.x + y * other.y);
}

double Vec2D::length() {
    return sqrt(x*x + y*y);
}

void Vec2D::normalize() {
    double len = length();
    if (len != 0.0f) {
        x /= len;
        y /= len;
    }
}