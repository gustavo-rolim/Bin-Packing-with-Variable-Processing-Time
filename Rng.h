#ifndef RNG_H
#define RNG_H

// Include C++ libraries

#include <random>

inline double random_double(const double& a, const double& b, std::mt19937& gen) {
    std::uniform_real_distribution<double> dist(a, b);
    return dist(gen);
}

inline int random_int(const int& a, const int& b, std::mt19937& gen) {
    std::uniform_int_distribution<int> dist(a, b);
    return dist(gen);
}

#endif