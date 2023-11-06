#include <algorithm>
#include <unordered_map>
#include "collision.h"

// remove later
#include <iostream>

struct array_hash {
    inline std::size_t operator()(const array<int,2>& v) const {
        return v[0] ^ v[1];
    }
};
bool circleComparison_x(pair<Circle*, int>& p1, pair<Circle*, int>& p2) {
    return (
        (p1.first)->getPos().x - (p1.first)->getRadius() 
                <
        (p2.first)->getPos().x - (p2.first)->getRadius()
    );
}
bool circleComparison_y(pair<Circle*, int>& p1, pair<Circle*, int>& p2) {
    return (
        (p1.first)->getPos().y - (p1.first)->getRadius() 
            < 
        (p2.first)->getPos().y - (p2.first)->getRadius()
    );
}

Collision::Collision(vector<pair<Circle*, int>>& circles_) {
    circles = circles_;
}

bool Collision::isColliding(Circle* circle1, Circle* circle2) {
    Vec2D pos1 = circle1->getPos();
    Vec2D pos2 = circle2->getPos();

    double dx2 = (pos2.x - pos1.x)*(pos2.x - pos1.x);
    double dy2 = (pos2.y - pos1.y)*(pos2.y - pos1.y);
    double distance = dx2 + dy2;

    double sumOfRadii = circle1->getRadius() + circle2->getRadius();
    return distance <= sumOfRadii * sumOfRadii;
}

void Collision::handleBorderCollisions(int X, int Y) {
    for(pair<Circle*, int>& ci: circles) {
        Circle* c = ci.first;

        double x = c->getPos().x;
        double y = c->getPos().y;

        double vx = c->getVel().x;
        double vy = c->getVel().y;

        double r = c->getRadius();

        if(x - r <= 0) {
            c->setVel(Vec2D(-vx, vy));
            c->setPos(Vec2D(r, y));
        } else if(x + r >= X) {
            c->setVel(Vec2D(-vx, vy));
            c->setPos(Vec2D(X-r, y));
        } else if(y - r <= 0) {
            c->setVel(Vec2D(vx, -vy));
            c->setPos(Vec2D(x, r));
        } else if(y + r >= Y) {
            c->setVel(Vec2D(vx, -vy));
            c->setPos(Vec2D(x, Y-r));
        } else {
            continue;
        }
    }
}

// add intersecting logic
bool collisionTimeCalculate(Vec2D s, Vec2D v, double r, double& t) {
    double c = s.dot(s) - r*r; // if negative, they overlap
    if (c < 0.0) // if true, they already overlap
    {
        t = .0;
        return true;
    }

    float a = v.dot(v);

    float b = v.dot(s);
    if (b >= 0.0)
        return false; // does not move towards each other

    float d = b*b - a*c;
    if (d < 0.0)
        return false; // no real roots ... no collision

    t = (-b - sqrt(d)) / a;

    return true;
}
void Collision::handleCollisions(Circle* circle1, Circle* circle2) {
    /*
    float m1, m2, x1, x2;
    Vec2D v1temp, v1, v2, v1x, v2x, v1y, v2y, x(circle1->getPos() - circle2->getPos());

    x.normalize();
    v1 = circle1->getVel();
    x1 = x.dot(v1);
    v1x = x * x1;
    v1y = v1 - v1x;
    m1 = circle1->getRadius();

    x = x * -1;
    v2 = circle2->getVel();
    x2 = x.dot(v2);
    v2x = x * x2;
    v2y = v2 - v2x;
    m2 = circle2->getRadius();

    circle1->setVel(v1x * (m1 - m2) / (m1 + m2) + v2x * (2 * m2) / (m1 + m2) + v1y);
    circle2->setVel(v1x * (2 * m1) / (m1 + m2) + v2x * (m2 - m1) / (m1 + m2) + v2y);
    */

    Vec2D s = circle1->getPos() - circle2->getPos(); // vector between the centers of each sphere
    Vec2D v = circle1->getVel() - circle2->getVel(); // relative velocity between spheres
    double r = circle1->getRadius() - circle2->getRadius();

    double t;

    if(collisionTimeCalculate(s, v, r, t)) {
        Vec2D offset = v * t * 0.5;

        circle1->setPos(circle1->getPos() - offset);
        circle2->setPos(circle2->getPos() + offset);


    }
}

void Collision::populateCirclesColliding() {
    circles_colliding.clear();

    // ci^cj : {ci, cj, k}
    unordered_map<int, array<int, 3>> mp;

    // {circle, index}
    vector<pair<Circle*, int>> circles_;
    for(int i = 0; i < (int)circles.size(); i++) 
        circles_.push_back({circles[i].first, i});

    for(int b_ = 1; b_ <= 2; b_++) {
        if(b_ == 1) sort(circles_.begin(), circles_.end(), circleComparison_x);
        else        sort(circles_.begin(), circles_.end(), circleComparison_y);


        for(int i = 0; i < circles_.size(); i++) {
            for(int j = i+1; j < circles_.size(); j++) {
                Circle* c1 = circles_[i].first;
                Circle* c2 = circles_[j].first;

                if(c1->getPos().x + c1->getRadius() < c2->getPos().x - c2->getRadius())
                    break;

                if(isColliding(c1, c2)) {
                    int hash_idx = circles_[i].second ^ circles_[j].second;

                    if(mp.find(hash_idx) == mp.end()) {
                        mp[hash_idx] = {circles_[i].second, circles_[j].second, b_};
                    } else {
                        if(mp[hash_idx][2] != b_) mp[hash_idx][2] ^= b_;
                    }
                }
            }
        }

    }

    for(auto& [k, v]: mp)
        if(v[2] != 3) 
            continue;
        else 
            circles_colliding.push_back({v[0], v[1]});

}

void Collision::detectAndHandleCollisions(vector<mutex>& mtx) {
    populateCirclesColliding();

    for(auto& [i, j]: circles_colliding) {
        int i_ = circles[i].second;
        int j_ = circles[j].second;

        mtx[i_].lock();
        mtx[j_].lock();

        handleCollisions(circles[i].first, circles[j].first);

        mtx[i_].unlock();
        mtx[j_].unlock();
    }
}