#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std::chrono;

#include "../include/collision.h"

vector<mutex> mtx(N);
void gridify(vector<Particle>& particles, Vec2d& threshold, vector<vector<Particle>>& subgrids) {
    for(int i = 0; i < N; i++) {
        int x = particles[i].pos.x / threshold.x;
        int y = particles[i].pos.y / threshold.y;
        
        if(x < 0) x = 0;
        if(y < 0) y = 0;

        if(x >= N_G) x = N_G - 1;
        if(y >= N_G) y = N_G - 1;

        int idx = x * N_G + y;

        subgrids[idx].push_back(particles[i]);
    }
}

int main() {
    vector<Particle> particles;

    for(int i = 0; i < N; i++) {
        int idx = i;

        double radius = fRand(R_MIN, R_MAX);
    
        Vec2d pos = Vec2d(
            fRand(radius, X_SIZE - radius), 
            fRand(radius, Y_SIZE - radius)
        );

        Vec2d vel = Vec2d(
            fRand(V_MIN, V_MAX), 
            fRand(V_MIN, V_MAX)
        );

        Particle particle = Particle(pos, vel, radius, idx);
        particles.push_back(particle);
    }

    cout << "T = 0" << endl;
    for(int i = 0; i < N; i++) {
        cout << "[" << i << "] ";
        cout << "(" << particles[i].pos.x << ", " << particles[i].pos.y << ")";
        cout << " ";
        cout << "(" << particles[i].vel.x << ", " << particles[i].vel.y << ")";
        cout << " ";
        cout << particles[i].radius;
        cout << endl;
    }

    Vec2d threshold = Vec2d(X_SIZE / N_G, Y_SIZE / N_G);

    double T = 0;

    auto start = high_resolution_clock::now();

    while(T < Tf) {
        for(int i = 0; i < N; i++) {
            particles[i].update();
        }

        vector<vector<Particle>> subgrids(N_T);
        gridify(particles, threshold, subgrids);

        vector<thread> threads;
        for (int i = 0; i < N_T; i++) {
            threads.push_back(thread(detectCollision, ref(subgrids[i])));
        }

        for(int i = 0; i < N_T; i++) {
            threads[i].join();
        }

        T += dt;
    }

    cout << "T = " << Tf << endl;
    for(int i = 0; i < N; i++) {
        cout << "[" << i << "] ";
        cout << "(" << particles[i].pos.x << ", " << particles[i].pos.y << ")";
        cout << " ";
        cout << "(" << particles[i].vel.x << ", " << particles[i].vel.y << ")";
        cout << " ";
        cout << particles[i].radius;
        cout << endl;
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    
    return 0;
}