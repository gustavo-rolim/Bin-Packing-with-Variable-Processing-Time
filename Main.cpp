// Include C++ libraries

#include <chrono>
#include <iostream>
#include <random>
#include <vector>

// Include auxiliary header files

#include "Arc_flow.h"
#include "Data.h"
#include "Heu.h"
#include "Io.h"
#include "Lns.h"
#include "Lns_reactive.h"
#include "Svc.h"
#include "Vnd.h"

int main(int argc,
	char* argv[]) {

	// ======================
    // 2. INITIALIZATION
    // ======================

	const std::string instance_path = "HBPP_20015009_02720.C.txt"; //HBPP_20015009_02720.C.txt BPP_new_20_50_1.C.txt
	const std::string param_path = "p.txt";
	const std::string method = "lns";
	ProblemInstance inst;

	try {
		// Load parameters

		read_parameter_file(param_path, inst);
		std::cout << "Parameters loaded from: " << param_path << std::endl;

		// Load problem instance

		read_problem_instance(instance_path, inst);
		std::cout << "Instance loaded: " << instance_path
			<< " (" << inst.n << " items, capacity " << inst.lmax << ")\n";
	}
	catch (const std::exception& e) {
		std::cerr << "Error during initialization: " << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	// ======================
	// 3. START RANDOM GENERATOR
	// ======================

	std::random_device rd;
	std::mt19937 gen(rd()); 

	// ======================
	// 4. SOLUTION METHODS
	// ======================

	std::vector<Bin> sol; 
	float of = 0.0f; 
	auto start_time = std::chrono::high_resolution_clock::now(); 

	if (method == "heu") {
		of = main_constructive(sol, inst);
		of = main_vnd(sol, inst, of);
	}
	else if (method == "svc") {
		of = main_svc(sol, inst, gen);
	}
	else if (method == "lns") {
		of = main_constructive(sol, inst);
		std::cout << "Current objective: " << of << std::endl;
		of = main_vnd(sol, inst, of);
		std::cout << "Current objective: " << of << std::endl;
		of = main_lns(sol, inst, of, gen);
		std::cout << "Current objective: " << of << std::endl;
	}
	else if (method == "lns_reactive") {
		of = main_constructive(sol, inst);
		of = main_vnd(sol, inst, of);
		of = main_lns_reactive(sol, inst, of, gen);
	}
	else if (method == "arc_flow") {
		of = main_arc_flow(sol, inst);
		std::cout << "Current objective: " << of << std::endl;
		of = main_vnd(sol, inst, of);
		std::cout << "Current objective: " << of << std::endl;
		of = main_lns(sol, inst, of, gen);
		std::cout << "Current objective: " << of << std::endl;
	}

	auto end_time = std::chrono::high_resolution_clock::now(); 
	double running_time = std::chrono::duration<double>(end_time - start_time).count();
}