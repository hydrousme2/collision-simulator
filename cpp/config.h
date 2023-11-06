#ifndef CONFIG_H
#define CONFIG_H

// box
const int X = 1000;
const int Y = 1000;

// circle
const int B = 100;
const double MAX_RADIUS = 10.0;
const double MIN_RADIUS = 0.5;
const double MAX_VEL = 5.0;
const double MIN_VEL = 0.5;

// threads
const int N = 5;
const int NUM_THREADS = N*N;

// exec
const int fps = 10;
const double dt = 1.0 / fps;
const double T = 10.0;

#endif
