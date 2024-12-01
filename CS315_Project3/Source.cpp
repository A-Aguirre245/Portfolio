#include "graphs.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {

	ifstream vertexfile("MiddleEarthVertices.txt");
	string temp;
	vector<vertex> hold;

	while (getline(vertexfile, temp)) {
		vertex newNode(temp);
		hold.push_back(newNode);
	}
	vertexfile.close();

	ifstream edgefile("MiddleEarthEdges.txt");
	while (getline(edgefile, temp)) {
		string vertex1, vertex2, weightString;
		int weight;
		stringstream txtLine(temp);
		getline(txtLine, vertex1, ',');
		getline(txtLine, vertex2, ',');
		txtLine >> weight;

		for (int i = 0; i < hold.size(); i++) {
			if (vertex1 == hold[i].getName()) {
				for (int j = 0; j < hold.size(); j++) {
					if (vertex2 == hold[j].getName()) {
						hold[i].setAdj(&hold[j], weight);
						hold[j].setAdj(&hold[i], weight);
					}
				}
			}
		}
	}

	edgefile.close();

	cout << "Graph of Middle Earth: " << endl;

	for (int i = 0; i < hold.size(); i++) {
		cout << hold[i].getName() << ": ";
		vector<pair<vertex*, int>> temp = hold[i].getAdj();
		for (int j = 0; j < temp.size(); j++) {
			cout << (temp[j].first)->getName();
				if (j != temp.size() - 1) {
					cout << ", ";
			}
		}
		cout << endl;
	}
	cout << endl;
	
	bfs(hold[0]);
	cout << "Shortest path from Hobbiton to Mt. Doom using BFS: " << endl << "Hobbiton-->";
	printPath(&hold[0], &hold[hold.size() - 1]);
	cout << "MtDoom" << endl << endl;

	for (int i = 0; i < hold.size(); i++) {
		hold[i].setDistance(INT_MAX);
		hold[i].setPie(NULL);
	}

	dijkstras(hold[0]);
	cout << "Shortest path from Hobbiton to Mt. Doom using Dijksta's: " << endl << "Hobbiton-->";
	printPath(&hold[0], &hold[hold.size() - 1]);
	cout << "MtDoom" << endl << endl;

	for (int i = 0; i < hold.size(); i++) {
		hold[i].setDistance(INT_MAX);
		hold[i].setPie(NULL);
		hold[i].setColor(0);
	}

	cout << "Predecessor hash table for Prim's: " << endl;
	prims(hold[0]); 
}