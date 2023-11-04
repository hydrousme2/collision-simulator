#include "collision.h"
#include "circle.h"
#include <iostream>

#define X 1000
#define Y 1000

static const int fps = 10;
static const double dt = 1.0 / fps;
static const double T = 10;

int main() {
    vector<Circle> circles;

    for(int i = 0; i < 100; ++i)
        circles.push_back(Circle(Vec2D(rand() % X, rand() % Y), Vec2D(rand() % 5, rand() % 5), rand() % 10));

    double t = 0.0;
    while(t < T) {
        cout << "t = " << t << endl;

        unordered_map<int, vector<Circle>> circles_mapped;

        // zoning
        for(Circle& circle: circles) {
            int x = circle.getPos().x / (X / n);
            int y = circle.getPos().y / (Y / n);
            int zone = x * n + y;

            circles_mapped[zone].push_back(circle);
        }

        // collision logic
        checkCollision(circles_mapped);

        // update circles
        for(Circle& circle: circles)
            circle.update(dt);
        
        // update time
        t += dt;
    }
}