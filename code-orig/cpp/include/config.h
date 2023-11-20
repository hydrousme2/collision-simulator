#ifndef CONFIG_H
#define CONFIG_H

#define X_SIZE 100  // boundary
#define Y_SIZE 100  // boundary

#define V_MAX 10    // maximum velocity
#define V_MIN 0     // minimum velocity

#define R_MAX 10    // maximum radius
#define R_MIN 1     // minimum radius

#define N 3        // number of particles
#define N_G 5       // number of subgrids
#define N_T N_G*N_G // number of threads

#define Tf 10       // final time
#define dt 0.1      // time step

#endif