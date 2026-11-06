#pragma once
#include <vector>

// define the microscopic particle
struct Particle{
    double  x{0.0};
    double  y{0.0};
    double vx{0.0};
    double vy{0.0};
};

// define the box
struct Box{
    int width{100};
    int height{100};
    int wall{width/2};
    int hole{20};
};

// define physics loop function
void updatePhysics(std::vector<Particle>& particles, const Box& box, double dt);

// define entropy calculation
double calcEntropy(const std::vector<Particle>& particles, const Box& box, int gridCols, int gridRows);