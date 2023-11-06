#ifndef COLLISION_H
#define COLLISION_H

#include "circle.h"
#include <array>
#include <vector>
#include <mutex>


class Collision {
private:
    vector<array<int, 2>> circles_colliding;
    vector<pair<Circle*, int>> circles;

    bool isColliding(Circle* circle1, Circle* circle2);
    void handleCollisions(Circle* circle1, Circle* circle2);
    void populateCirclesColliding();

public:
    Collision(vector<pair<Circle*, int>>& circles_);
    void handleBorderCollisions(int X, int Y);
    void detectAndHandleCollisions(vector<mutex>& mtx);
};

#endif
