#include "physics.h"
#include <vector>
#include <cmath>

double calcEntropy(const std::vector<Particle>& particles, const Box& box, int gridCols, int gridRows) {
    // don't compute if there are no particles in local region
    if (particles.empty()) return 0.0;

    int totalBins = gridCols * gridRows;

    // compress 2D grid to 1D for memory encoding and initialize to zero
    std::vector<int> binCounts(totalBins, 0);

    // 1. Binning
    for (const auto& p : particles) {
        // clamp coordinates inside box boundaries to prevent out of bounds access
        double clampedX = std::max(0.0, std::min(p.x, box.width - 0.001));
        double clampedY = std::max(0.0, std::min(p.y, box.height - 0.001));

        // transform continous x,y space to discrete 2D grid coordinates (x, y)
        int col = static_cast<int>((clampedX/box.width) * gridCols);
        int row = static_cast<int>((clampedY/box.height) * gridRows);

        // map 2D grid coordinates (row, col) to 1D vector index
        int binIdx = row * gridCols + col;

        binCounts[binIdx]++;    // increment through each bin each cycle
    }

    // 2. Entropy Accumulation
    double entropy{0.0};
    double N = static_cast<double>(particles.size());   // must be a double to avoid truncation

    for (int Ni : binCounts) {
        if (Ni > 0) {
            double pi = Ni / N;
            entropy -= pi * std::log(pi);
        }
    }    

    return entropy;
}