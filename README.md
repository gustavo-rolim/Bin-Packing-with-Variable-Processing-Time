# Source Code for: An empirical study of heuristics for an integrated bin packing and scheduling problem

This repository contains the source code for the heuristics for the 1BP-VPT.

## 1. Repository Content

The solver is written in C++ and implements the following algorithms: a **Constructive Procedure**, **Variable Neighborhood Descent (VND)**, **Large Neighborhood Search (LNS)**, and **Sequential Value Correction (SVC)**.

| File | Description |
| :--- | :--- |
| `Main.cpp` | **Main execution file** required to compile the solver. |
| `Io.h` | Functions for managing input/output of problem instances. |
| `Data.h` | Declaration of problem-specific data structures. |
| `Objective.h` | Calculation of the bi-objective function. |
| `Rng.h` | Random number generator functions. |
| `Heu.h` | Implementation of the **Constructive Heuristic** procedure. |
| `Vnd.h` | Implementation of the **Variable Neighborhood Descent (VND)** metaheuristic. |
| `Lns.h` | Implementation of the **Large Neighborhood Search (LNS)** metaheuristic. |
| `Svc.h` | Implementation of the **Sequential Value Correction (SVC)** heuristic. |

**Accompanying Files:**

* `p.txt`: **Input parameters file** required for defining instance configuration.
* `Summary_02_08.xlsx`: Tabulated computational results over the benchmark instances.
---

## 2. Usage

### Dependencies
* The code is written in **C++** and requires a **C++20 compiler**

### Running the solver
* To run the solver on Windows: 
```bash
Solver.exe <instance_file> <parameter_file> <method>
```
Where: 
* `<instance_file>`: Path to a problem instance.
* `<parameter_file>`: Path to the `p.txt` file.
* `<method>`: {heu, lns, svc, svc_vnd}.
