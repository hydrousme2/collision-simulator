#include <thread>
#include <iostream>
#include "multithreads.h"

// utils
double getRand(double min, double max) {
    return min + (max-min)*((double)rand() / RAND_MAX);
}

int main() {
    vector<pair<Circle*, int>> circles;

    for(int i = 0; i < B; ++i) {
        Vec2D pos(
            getRand(MAX_RADIUS, X - MAX_RADIUS),
            getRand(MAX_RADIUS, X - MAX_RADIUS)
        );

        Vec2D vel(
            getRand(MIN_VEL, MAX_VEL),
            getRand(MIN_VEL, MAX_VEL)
        );

        double radius = getRand(MIN_RADIUS, MAX_RADIUS);

        Circle* c = new Circle(pos, vel, radius);
        circles.push_back({c, i});
    }

    Vec2D threshold(X/N, Y/N);

    double t = 0.0;
    while(t < T) {
        cout << "t = " << t << endl;

        zoneCircles(circles, threshold);
        threadify(circles);
        
        // update time
        t += dt;
    }
}