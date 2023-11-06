#ifndef MULTITHREADS_H
#define MULTITHREADS_H

#include "collision.h"
#include "config.h"


extern void zoneCircles(vector<pair<Circle*, int>>& circles, Vec2D threshold);
extern void checkCollisions(int zone);
extern void threadify(vector<pair<Circle*, int>>& circles);

#endif
