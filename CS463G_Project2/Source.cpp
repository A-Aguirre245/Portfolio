#include "SAT.h"

#include <filesystem>  // C++17 filesystem support
#include <string>

const int POP_SIZE = 500;
const int GENERATIONS = 200;
const double MUTATION_RATE = 0.079;

const int MAX_TRIES = 200;
const int MAX_CHANGES = 500;
const double PROBABILITY = 0.333;

using namespace std;

int main() {
    string folderPath = "PA3_Benchmarks/CNF Formulas";

    // Iterate over all files in the folder
    for (const auto& entry : filesystem::directory_iterator(folderPath)) {
        // Check if the file has a .cnf extension
        if (entry.path().extension() == ".cnf") {
            cout << "Processing file: " << entry.path() << endl;

            // Create a cnfFormulas object and read the formula from the current file
            cnfFormulas formula;
            formula.readFormula(entry.path().string());  // Convert path to string for readFormula()
         
            auto start = std::chrono::high_resolution_clock::now(); // Start timer
            
            //run walkSAT
            if (formula.walkSAT(MAX_TRIES, MAX_CHANGES, PROBABILITY)) {
                cout << entry.path().filename() << " is SAT" << endl;
            }
            else {
                cout << entry.path().filename() << " is UNSAT" << endl;
            }

            /*
            // Run genetic
            if (formula.genetic(POP_SIZE, GENERATIONS, MUTATION_RATE)) {
                cout << entry.path().filename() << " is SAT" << endl;
            }
            else {
                cout << entry.path().filename() << " is UNSAT" << endl;
            }*/

            /*
            // Run DPLL on the formula
            if (formula.dPLL()) {
                auto end = std::chrono::high_resolution_clock::now(); // End timer
                std::chrono::duration<double> duration = end - start;
                cout << "DPLL algorithm time: " << duration.count() << " seconds" << endl;
                cout << entry.path().filename() << " is SAT" << endl;
            }
            else {
                auto end = std::chrono::high_resolution_clock::now(); // End timer
                std::chrono::duration<double> duration = end - start;
                cout << "DPLL algorithm time: " << duration.count() << " seconds" << endl;
                cout << entry.path().filename() << " is UNSAT" << endl;
            }*/
        }
    }
    return 0;
}