#include "SAT.h"


cnfFormulas::cnfFormulas()
{
	vector<vector<int>> temp;
	srand(time(0));

	numLiterals = 0;
	NumClauses = 0;
	clauses = temp;
}

int cnfFormulas::getNumLit() const
{
	return numLiterals;
}

int cnfFormulas::getNumClause() const
{
	return NumClauses;
}

const vector<vector<int>>& cnfFormulas::getClauses() const
{
	return clauses;
}

void cnfFormulas::removeClause(int i)
{
	clauses.erase(clauses.begin() + i);
}

void cnfFormulas::removeElement(int i, int j)
{
	auto it = find(clauses[i].begin(), clauses[i].end(), j);
	clauses[i].erase(it);
}

void cnfFormulas::addClause(vector<int> i)
{
	clauses.push_back(i);
}

void cnfFormulas::unitProp() {
	for (int i = 0; i < clauses.size(); i++) {
		if (clauses[i].size() == 1) { //check for unit clauses in CNF
			int unitLit = clauses[i][0];
			int notUnitLit = -unitLit;

			for (int j = 0; j < clauses.size(); j++) { //find unit Literals in clauses
				if (j != i) {
					if (find(clauses[j].begin(), clauses[j].end(), unitLit) != clauses[j].end()) {
						this->removeClause(j); //removes repetetions of the unit clause
						j--;
					}
					else if (find(clauses[j].begin(), clauses[j].end(), notUnitLit) != clauses[j].end()) {
						this->removeElement(j, notUnitLit); // removes the negated literal if it appears in a clause
					}
				}
			}
		}
	}
}

vector<int> cnfFormulas::pureLits() {
	unordered_map<int, int> literalCount; //tracks literal to how many times they appear
	for (int i = 0; i < clauses.size(); i++) {
		for (int j = 0; j < clauses[i].size(); j++) {
			int lit = clauses[i][j];
			literalCount[lit]++; //sets all literals to 1
		}
	}

	vector<int> pureLit;
	for (auto it = literalCount.begin(); it != literalCount.end(); it++) { //checks if the negation of the literal exists
		int lit = it->first;
		int notLit = -lit;
		if (literalCount.find(notLit) == literalCount.end()) { //if it doesnt, its added to the list of pure literals
			pureLit.push_back(lit);
		}
	}

	return pureLit;
}



void cnfFormulas::pureElimination()
{
	vector<int> pureLits = this->pureLits();

	for (int i = 0; i < pureLits.size(); i++) {
		for (int j = 0; j < clauses.size(); j++) {
			if (find(clauses[j].begin(), clauses[j].end(), pureLits[i]) != clauses[j].end()) {
				this->removeClause(j); //removes clauses that contain the pure literal
				j--;
			}
		}
		vector<int> tmp{i};
		this->addClause(tmp);
	}
}

void cnfFormulas::assignLit(int lit)
{
	int notLit = -lit; //negated lit
	for (int i = 0; i < clauses.size(); i++) {//search through all clauses
		if (find(clauses[i].begin(), clauses[i].end(), lit) != clauses[i].end()) { 
			this->removeClause(i); //if positive lit is found in clause, remove clause
			i--;
		}else if (find(clauses[i].begin(), clauses[i].end(), notLit) != clauses[i].end()) {
			this->removeElement(i, notLit); // removes the negated literal if it appears in a clause
		}
	}
}

bool cnfFormulas::dPLL(){
	auto start = std::chrono::high_resolution_clock::now(); // start timer

	this->unitProp();
	this->pureElimination();
	
	if (clauses.size() == 0) {
		return true; // SAT
	}

	for (int i = 0; i < clauses.size(); i++) {
		if (clauses[i].size() == 0) {
			return false;
		}
	}

	bool unitClauses = true;
	for(int i = 0; i < clauses.size(); i++){
		if (clauses[i].size() != 1) {
			unitClauses = false;
			break;
		}
	}
	if (unitClauses) {
		return true; //SAT
	}

	int rand = std::rand() % clauses.size();
	int rand2 = std::rand() % clauses[rand].size();
	int x = clauses[rand][rand2]; //choses a random literal

	cnfFormulas litGuess = *this;
	litGuess.assignLit(x);
	if (litGuess.dPLL()) {
		return true;
	}

	cnfFormulas litGuess2 = *this;
	litGuess2.assignLit(-x);
	return litGuess2.dPLL();
}

int cnfFormulas::evaulateFitness(vector<bool> randInd)
{
	int satisfied = 0; //keeps track of satisfies clauses
	for (int i = 0; i < clauses.size(); i++) {
		bool sat = false;
		for (int j = 0; j < clauses[i].size(); j++){ //iterate through each literal in current clause for each clause of the formula
			int tempClause = clauses[i][j];

			int absClause = abs(tempClause) - 1; // Get the index (1-based literal to 0-based index)
			if ((tempClause > 0 && randInd[absClause]) || (tempClause < 0 && !randInd[absClause])) {
				sat = true;
				break;
			}
		}
		if (sat) {
			satisfied++;
		}
	}
	return satisfied;
}

vector<bool> cnfFormulas::selectParent(vector<pair<vector<bool>, int>> pairs, int totalfit)
{
	double randVal = (double)rand() / RAND_MAX; // Generate a random value between 0 and 1
	double cumuProb = 0;
	for (auto it = pairs.begin(); it != pairs.end(); it++) {
		double probability = (double)it->second / totalfit; // Calculate probability for current individual
		cumuProb += probability;

		if (randVal <= cumuProb) { // Check if this individual is selected
			return it->first; // Exit loop once a parent is selected
		}
	}
	return {};
}

void cnfFormulas::mutate(vector<bool> &child, double mutationR)
{
	for (int i = 0; i < child.size(); i++) {
		double randVal = (double)rand() / RAND_MAX;
		if (randVal < mutationR) {
			child[i] = !child[i]; // Flip the bit with probability mutationR
		}
	}
}

vector<vector<bool>> cnfFormulas::cross(int pop, vector<pair<vector<bool>,int>> pairs, int totalfit, double mutationR)
{
	vector<vector<bool>> newPop;

	while (newPop.size() < pop) {
		vector<bool> par1 = this->selectParent(pairs, totalfit);
		vector<bool> par2 = this->selectParent(pairs, totalfit);

		while (par1 == par2) { //ensures that parents are different
			par2 = this->selectParent(pairs, totalfit);
		}

		if (par1.size() != numLiterals || par2.size() != numLiterals) {
			continue; // Skip this iteration if the parents don't have the right size
		}

		int crossoverPoint = rand() % numLiterals;
		vector<bool> child1(numLiterals), child2(numLiterals);

		for (int i = 0; i < crossoverPoint; i++) {
			child1[i] = par1[i];
			child2[i] = par2[i];
		}
		for (int i = crossoverPoint; i < numLiterals; i++) {
			child1[i] = par2[i];
			child2[i] = par1[i];
		}

		newPop.push_back(child1);
		newPop.push_back(child2);
	}

	for (int i = 0; i < newPop.size(); i++) {
		this->mutate(newPop[i], mutationR);
	}

	return newPop;
}



bool cnfFormulas::genetic(int pop, int generations, double mutationR)
{
	//create a random population of bit strings. 0 represnts a negative lit, 1 represents a positive lit. The index correlates to the lit
	vector<vector<bool>> population(pop, vector<bool>(numLiterals));

	for (int i = 0; i < pop; i++) { //for 100 vectors
		for (int j = 0; j < numLiterals; j++) {
			population[i][j] = rand() % 2; // fills them with 0 or 1, for each lit in the formula
		}
	}

	int maxSatisfied = 0;  // Track the max number of satisfied clauses

	auto start = std::chrono::high_resolution_clock::now(); // Start timer

	for (int g = 0; g < generations; g++) {
		int totalfit = 0;
		vector<pair<vector<bool>, int>> pairs;
		pairs.reserve(pop);

		for (int i = 0; i < pop; i++) {
			int temp = this->evaulateFitness(population[i]);
			maxSatisfied = max(maxSatisfied, temp);
			if (temp == clauses.size()) {
				auto end = std::chrono::high_resolution_clock::now(); // End timer
				std::chrono::duration<double> duration = end - start;
				cout << "Genetic algorithm time: " << duration.count() << " seconds" << endl;
				cout << "Max satisfied clauses: " << maxSatisfied << endl << endl;
				return true;
			}
			pairs.emplace_back(population[i], temp);
			totalfit += temp;
		}

		sort(pairs.begin(), pairs.end(), [](const auto& a, const auto& b) {
			return a.second > b.second;
			});

		vector<vector<bool>> newPop;

		for (int i = 0; i < pop * .25 && i < pairs.size(); i++) {
			newPop.push_back(pairs[i].first);
		}

		vector<vector<bool>> offspring = this->cross(pop - pop * .25, pairs, totalfit, mutationR);
		newPop.insert(newPop.end(), offspring.begin(), offspring.end());


		population = newPop;
	}
	
	auto end = std::chrono::high_resolution_clock::now(); // End timer
	std::chrono::duration<double> duration = end - start;
	cout << "Genetic algorithm time: " << duration.count() << " seconds" << endl;
	cout << "Max satisfied clauses: " << maxSatisfied << endl << endl;

	return false;
}

vector<bool> cnfFormulas::createAssignment()
{
	vector<bool> litAssign(numLiterals);
	for (int i = 0; i < numLiterals; i++) { //for 100 vectors
		litAssign[i] = rand() % 2; // fills them with 0 or 1, for each lit in the formula
	}
	return litAssign;
}

bool cnfFormulas::satisfyClause(vector<int> &clause, vector<bool> &assignment)
{
	for (int i = 0; i < clause.size(); i++) {
			int tempClause = clause[i];
			int absClause = abs(tempClause) - 1; // Get the index (1-based literal to 0-based index)

			if ((tempClause > 0 && assignment[absClause]) || (tempClause < 0 && !assignment[absClause])) {
				return true;
			}
	}

	return false;
}

bool cnfFormulas::satisfyFormula(vector<bool> &assignment)
{
	for (int i = 0; i < clauses.size(); i++) {
		if (!this->satisfyClause(clauses[i], assignment)) {
			return false;
		}
	}
	return true;
}

bool cnfFormulas::walkSAT(int max, int change, double p)
{
	int maxSatisfied = 0;  // Track the max number of satisfied clauses

	auto start = std::chrono::high_resolution_clock::now(); // Start time

	for (int i = 0; i < max; i++) {
		vector<bool> assignment = this->createAssignment();

		for (int j = 0; j < change; j++) {
			int satisfied = this->evaulateFitness(assignment);
			maxSatisfied = std::max(maxSatisfied, satisfied);
			if (this->satisfyFormula(assignment)) {
				auto end = std::chrono::high_resolution_clock::now(); // End timer
				std::chrono::duration<double> duration = end - start;
				cout << "WalkSAT time: " << duration.count() << " seconds" << endl;
				cout << "Max satisfied clauses: " << maxSatisfied << endl << endl;
				return true;
			}

			vector<vector<int>> unsatClause;
			for (int k = 0; k < clauses.size(); k++) {
				if (!this->satisfyClause(clauses[k], assignment)) {
					unsatClause.push_back(clauses[k]);
				}
			}

			vector<int>& changeClause = unsatClause[rand() % unsatClause.size()];
			if ( (double)rand() / RAND_MAX < p) {
				// Flip a random variable in the clause
				int randomLit = changeClause[rand() % changeClause.size()];
				int absLiteral = abs(randomLit) - 1; // 0-based index
				assignment[absLiteral] = !assignment[absLiteral];
			}else {
				int bestLiteral = changeClause[0];
				int bestSatisfiedCount = 0;

				for (int k = 0; k < changeClause.size(); k++) {
					int absLiteral = abs(changeClause[k]) - 1; // 0-based index
					assignment[absLiteral] = !assignment[absLiteral];

					int satisCount = 0;
					for (int l = 0; l < clauses.size(); l++) {
						if (this->satisfyClause(clauses[l], assignment)) {
							satisCount++;
						}
					}

					assignment[absLiteral] = !assignment[absLiteral];

					if (satisCount > bestSatisfiedCount) {
						bestSatisfiedCount = satisCount;
						bestLiteral = changeClause[k];
					}
				}

				int absBestLit = abs(bestLiteral) - 1;
				assignment[absBestLit] = !assignment[absBestLit];
			}
		}
	}
	auto end = std::chrono::high_resolution_clock::now(); // End timer
	std::chrono::duration<double> duration = end - start;
	cout << "WalkSAT time: " << duration.count() << " seconds" << endl;
	cout << "Max satisfied clauses: " << maxSatisfied << endl << endl;
	return false;
}

void cnfFormulas::readFormula(const string& filename)
{
	ifstream file(filename);
	string line;

	if (!file.is_open()) {
		cout << "Uh oh, thats not good";
		return;
	}
	while (getline(file, line)) {
		if (line[0] == 'c') {
			continue;
		}

		if (line[0] == 'p') {
			stringstream infoLine(line);
			string tmp;
			infoLine >> tmp >> tmp; // Skipping 'p' and 'cnf'
			infoLine >> numLiterals >> NumClauses;
			continue;
		}

		// Parse clauses
		stringstream workLine(line);
		vector<int> clause;
		int literal;

		while (workLine >> literal) {
			if (literal == 0) { // End of clause
				break;
			}
			clause.push_back(literal);
		}

		clauses.push_back(clause);
	}
	clauses.pop_back();
	clauses.pop_back();
	clauses.pop_back();

	file.close();

}
