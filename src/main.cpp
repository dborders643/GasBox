#include <iostream>
#include <cmath>
#include <vector>
#include "physics.h"

int main() {
    Box box{100, 100};
    int gridCols = 10;
    int gridRows = 10;
    int num_particles = 1000;

    // -------------------------------------------------------------
    // Test 1: Minimum Entropy (All particles in one corner)
    // -------------------------------------------------------------
    std::vector<Particle> orderParticles;
    for (int i = 0; i < num_particles; ++i) {
        orderParticles.push_back({1.0, 1.0, 0.0, 0.0});
    }

    double lowS = calcEntropy(orderParticles, box, gridCols, gridRows);
    std::cout << "Ordered State Entropy (Expected ~0): " << lowS << "\n";
    // -------------------------------------------------------------
    // Test 2: Maximum Entropy (Uniformly spread across n x m grid)
    // -------------------------------------------------------------
    std::vector<Particle> uniParticles;
    for (int r = 0; r < gridRows; ++r) {
        for (int c = 0; c < gridCols; ++c) {
            // place 10 particles near the center of each bin
            for (int k = 0; k < 10; ++k) {
                double x = (r + 0.5) * (box.width / gridCols);
                double y = (c + 0.5) * (box.height / gridRows);
                uniParticles.push_back({x, y, 0.0, 0.0});
            }
        }
    }

    double highS = calcEntropy(uniParticles, box, gridCols, gridRows);
    double expectedMaxS = std::log(gridCols * gridRows);

    std::cout << "Disordered State Entropy: " << highS << "\n";
    std::cout << "Theoretical Max Entropy: " << expectedMaxS << "\n";

    return 0;
}