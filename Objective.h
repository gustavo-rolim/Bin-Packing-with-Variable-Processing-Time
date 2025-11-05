#ifndef OBJECTIVE_H
#define OBJECTIVE_H

// CALL AUXILIARY .H FILES

#include "Data.h"

// CALL C++ LIBRARIES 

#include <algorithm>
#include <iostream>
#include <vector>

// AUXILIARY FUNCTION TO PRINT A SOLUTION 

void PrintSolution(const std::vector<Bin>& sol) {
    for (size_t i = 0; i < sol.size(); ++i) {
        std::cout << "[";
        for (size_t j = 0; j < sol[i].items.size(); ++j) {
            std::cout << sol[i].items[j];
            if (j < sol[i].items.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "] size: " << sol[i].size;
        if (i < sol.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
}

// COMPUTE THE OBJECTIVE FUNCTION VALUE

float compute_objective(const std::vector<Bin>& sol, const ProblemInstance& inst) {

    float ct = 0.0f;
    float Tmax = 0.0f;
    int len = sol.size();

    for (int i = 0; i < len; ++i) {
        ct += inst.s;

        for (int j = 0; j < sol[i].items.size(); ++j) {
            ct += inst.t;
            float T = std::max(0.0f, ct - inst.d[sol[i].items[j]]);

            if (T > Tmax) {
                Tmax = T;
            }
        }
    }

    float of = (inst.w1 * len) + (inst.w2 * Tmax);

    return of;
}

#endif