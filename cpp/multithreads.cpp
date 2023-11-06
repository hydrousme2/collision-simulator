#include <thread>
#include "multithreads.h"
#include <iostream>

vector<mutex> mtx(B);

vector<vector<pair<Circle*, int>>> circles_zoned(NUM_THREADS);


void zoneCircles(vector<pair<Circle*, int>>& circles, Vec2D threshold) {
    circles_zoned.clear();

    // divide (X, Y) into N*N subgrid and store in circles_zoned
    for(pair<Circle*, int>& c: circles) {
        Vec2D pos = (c.first)->getPos();
        Vec2D z = pos / threshold;

        int zone = (int)z.x + (int)z.y * N;

        circles_zoned[zone].push_back(c);
    }
}

void checkCollisions(int zone) {

    Collision collision(circles_zoned[zone]);

    if(zone < N || zone > N*N-N-1 || zone % N == 0 || zone % N == N-1)
        collision.handleBorderCollisions(X, Y);

    collision.detectAndHandleCollisions(mtx);
}

void threadify(vector<pair<Circle*, int>>& circles) {
    vector<thread> threads;
    threads.reserve(NUM_THREADS);

    for(int i = 0; i < NUM_THREADS; ++i) {
        threads.emplace_back(checkCollisions, i);
    }

    for(int i = 0; i < NUM_THREADS; ++i) {
        threads[i].join();
    }
}