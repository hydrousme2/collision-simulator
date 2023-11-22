int X_SIZE = 100;  // boundary
int Y_SIZE = 100;  // boundary

double V_MAX = 10.0;  // maximum velocity
double V_MIN = 0.0;   // minimum velocity

double R_MAX = 10.0;  // maximum radius
double R_MIN = 1.0;   // minimum radius

int N = 3;          // number of particles
int N_G = 5;        // number of subgrids
int N_T = N_G * N_G; // number of threads

double Tf = 10.0;    // final time
double dt = 0.1;     // time step