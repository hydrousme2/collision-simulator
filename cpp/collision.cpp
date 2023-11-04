#include <thread>
#include <mutex>
#include <iostream>
#include <algorithm>
#include "collision.h"

vector<pair<int, int>> dels{ {0, 0}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1} };
mutex mtx;

bool circleComparison(Circle& a, Circle& b) {
    return (a.getPos().x - a.getRadius() < b.getPos().x - b.getRadius());
}

bool isColliding(Circle& circle1, Circle& circle2) {
    Vec2D pos1 = circle1.getPos();
    Vec2D pos2 = circle2.getPos();
    double distance = (pos2.x - pos1.x)*(pos2.x - pos1.x) + (pos2.y - pos1.y)*(pos2.y - pos1.y);
    double sumOfRadii = circle1.getRadius() + circle2.getRadius();
    return distance <= sumOfRadii * sumOfRadii;
}

void handleCollisions(Circle& circle1, Circle& circle2) {
    float m1, m2, x1, x2;
    Vec2D v1temp, v1, v2, v1x, v2x, v1y, v2y, x(circle1.getPos() - circle2.getPos());

    x.normalize();
    v1 = circle1.getVel();
    x1 = x.dot(v1);
    v1x = x * x1;
    v1y = v1 - v1x;
    m1 = circle1.getRadius();

    x = x * -1;
    v2 = circle2.getVel();
    x2 = x.dot(v2);
    v2x = x * x2;
    v2y = v2 - v2x;
    m2 = circle2.getRadius();

    circle1.setVel(v1x * (m1 - m2) / (m1 + m2) + v2x * (2 * m2) / (m1 + m2) + v1y);
    circle2.setVel(v1x * (2 * m1) / (m1 + m2) + v2x * (m2 - m1) / (m1 + m2) + v2y);
}

void detectAndHandleCollisions(vector<Circle>& circles) {
    // implement using sweep and prune
    sort(circles.begin(), circles.end(), circleComparison);

    vector<pair<int, int>> potentialCollisions;

    for (size_t i = 0; i < circles.size(); ++i) {
        for (size_t j = i + 1; j < circles.size(); ++j) {
            if(circleComparison(circles[i], circles[j])) break;

            if (isColliding(circles[i], circles[j]))
                potentialCollisions.push_back({i, j});
        }
    }

    for(auto& [i, j]: potentialCollisions) {
        if (isColliding(circles[i], circles[j])) {
            mtx.lock();
            handleCollisions(circles[i], circles[j]);
            mtx.unlock();
        }
    }
}

void checkCollisionZone(unordered_map<int, vector<Circle>>& circles_mapped, int zone) {
    int x = (zone / n);
    int y = (zone % n);

    vector<Circle> circles;
    for(pair<int, int>& del: dels) {
        int x1 = x + del.first;
        int y1 = y + del.second;
        int zone1 = x1 * n + y1;
        
        // continue if invalid zone
        if (x1 < 0 && x1 >= n && y1 < 0 && y1 >= n)
            continue;

        mtx.lock();
        circles.insert(circles.end(), circles_mapped[zone1].begin(), circles_mapped[zone1].end());
        mtx.unlock();
    }

    detectAndHandleCollisions(circles);
}

void checkCollision(unordered_map<int, vector<Circle>>& circles_mapped) {
    vector<thread> threads;
    for (int i = 0; i < n*n; ++i)
        threads.emplace_back(checkCollisionZone, ref(circles_mapped), i);

    for (int i = 0; i < n*n; ++i)
        threads[i].join();
}

