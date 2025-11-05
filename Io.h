#ifndef IO_H
#define IO_H

// Include auxiliary header files 

#include "Data.h"

// Include C++ libraries

#include <algorithm>
#include <chrono>
#include <string>
#include <vector>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <iostream>

void read_parameter_file(const std::string& filename,
    ProblemInstance& inst) {

    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error: Could not open parameter file " << filename << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string line;

    while (std::getline(file, line)) {

        std::istringstream iss(line);
        std::string key;

        if (std::getline(iss, key, '=')) {
            if (key == "w1") iss >> inst.w1;
            else if (key == "w2") iss >> inst.w2;
            else if (key == "t") iss >> inst.t;
            else if (key == "s") iss >> inst.s;
        }
    }
}

void read_problem_instance(const std::string& filename,
    ProblemInstance& inst) {
    // INPUT FILE INTO THE PROGRAM

    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error: Could not open instance file " << filename << std::endl;
        exit(EXIT_FAILURE);
    }

    // READ THE FIRST LINE (NUMBER OF ITEMS AND CAPACITY)

    std::string line;
    std::getline(file, line);
    std::replace(line.begin(), line.end(), ',', ' ');
    std::istringstream firstLine(line);
    firstLine >> inst.lmax >> inst.n;

    // RESIZE VECTORS 

    inst.l.resize(inst.n);
    inst.d.resize(inst.n);

    // READ THE REMAINING LINES (LENGTHS AND DUE DATES)

    for (int i = 0; i < inst.n; ++i) {
        std::getline(file, line);
        std::replace(line.begin(), line.end(), ',', ' ');
        std::istringstream itemLine(line);

        int demand; // Auxiliary variable to store the demand 

        itemLine >> inst.l[i];  // Read items' length
        itemLine >> demand;
        itemLine >> inst.d[i];  // Read items' due date
    }

    file.close();
}

#endif