#ifndef COLLISION_H
#define COLLISION_H

#include "circle.h"
#include <vector>
#include<unordered_map>

#define n 5

extern bool isColliding(Circle& circle1, Circle& circle2);
extern void handleCollisions(Circle& circle1, Circle& circle2);
extern void detectAndHandleCollisions(vector<Circle>& circles);

extern void checkCollisionZone(unordered_map<int, vector<Circle>>& circles_mapped, int zone);
extern void checkCollision(unordered_map<int, vector<Circle>>& circles_mapped_);

#endif
