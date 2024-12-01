#include <vector>
#include <string>
#include <utility>

#ifndef GRAPHS_H
#define	GRAPHS_H

using namespace std;

class vertex {
public:
	vertex();
	vertex(string name);
	void setColor(int color);
	void setDistance(int distance);
	void setPie(vertex* pie);
	void setAdj(vertex* node, int weight);
	int getColor() const;
	int getDistance() const;
	vertex* getPie() const;
	string getName() const;
	vector<pair<vertex*, int>> getAdj() const;

private:
	int color; // white - 0  gray - 1  black - 2
	int d;
	vertex* pie;
	string name;
	vector<pair<vertex*, int>> adj;
};


class minHeap {
public:
	minHeap();
	int getSize() const;
	vector<pair<vertex*, int>> getHeap() const;
	void minHeapify(int i);
	vertex* extractMin();
	void decreaseKey(int i, int key);
	void insertKey(vertex* node, int key);

private:
	vector<pair<vertex*, int>> heap;
};

void printPath(vertex* s, vertex* v);
void bfs(vertex s);
void dijkstras(vertex s);
void relax(vertex* u, vertex* v, int w, minHeap* x);
void prims(vertex r);

#endif