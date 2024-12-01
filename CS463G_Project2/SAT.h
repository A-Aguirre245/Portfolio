#ifndef SAT_H
#define	SAT_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm> 
#include <utility> 
#include <chrono>

using namespace std;


class cnfFormulas {
	public:
		cnfFormulas();
		int getNumLit() const;
		int getNumClause() const;
		const vector<vector<int>>& getClauses() const;
		
		void removeClause(int i);
		void removeElement(int i, int j);
		void addClause(vector<int> i);
		void unitProp();
		vector<int> pureLits();
		void pureElimination();
		void assignLit(int lit);
		bool dPLL();

		int evaulateFitness(vector<bool> randInd);
		vector<bool> selectParent(vector<pair<vector<bool>, int>> pairs, int totalfit);
		void mutate(vector<bool> &child, double mutationR);
		vector<vector<bool>> cross(int pop, vector<pair<vector<bool>, int>> pairs, int totalfit, double mutationR);
		bool genetic(int pop, int generations, double mutationR);

		vector<bool> createAssignment();
		bool satisfyClause(vector<int> &clause, vector<bool> &assignment);
		bool satisfyFormula(vector<bool> &assignmet);
		bool walkSAT(int max, int change, double p);

		void readFormula(const string& filename);

	private:
		int numLiterals;
		int NumClauses;
		vector<vector<int>> clauses;
};

#endif