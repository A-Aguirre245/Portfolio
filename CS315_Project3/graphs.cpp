#include "graphs.h"

#include <iostream>
#include <queue>
#include <vector>
#include <map>

using namespace std;

vertex::vertex()
{
	color = 0;
	d = INT_MAX;
	pie = nullptr;
	name = "";
}

vertex::vertex(string name)
{
	color = 0;
	d = INT_MAX;
	pie = nullptr;
	this->name = name;
}

void vertex::setColor(int color)
{
	this->color = color;
}

void vertex::setDistance(int distance)
{
	d = distance;
}

void vertex::setPie(vertex* pie)
{
	this->pie = pie;
}

void vertex::setAdj(vertex* node, int weight)
{
	pair <vertex*, int> temp;
	temp.first = node;
	temp.second = weight;
	adj.push_back(temp);
}


int vertex::getColor() const
{
	return color;
}

int vertex::getDistance() const
{
	return d;
}

vertex* vertex::getPie() const
{
	return pie;
}

string vertex::getName() const
{
	return name;
}

vector<pair<vertex*, int>> vertex::getAdj() const
{
	return adj;
}


minHeap::minHeap()
{
	heap = vector<pair<vertex*, int>>();
}

int minHeap::getSize() const
{
	return (int)heap.size();
}

vector<pair<vertex*, int>> minHeap::getHeap() const
{
	return heap;
}

void minHeap::minHeapify(int i)
{
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int largest = i;

	if (l < getSize() && heap[l].second > heap[i].second) {
			largest = l;
	}


	if (r < getSize() && heap[r].second > heap[largest].second) {
			largest = r;
	}
	
	if (largest != i) {
		int temp = heap[i].second;
		heap[i].second = heap[largest].second;
		heap[largest].second = temp;
		minHeapify(largest);
	}

}

vertex* minHeap::extractMin()
{
	if (getSize() < 1) {
		//cout << "ERROR";
		return 0;
	}

	pair<vertex*, int> min = heap[0];
	heap[0] = heap[heap.size() - 1];
	heap.pop_back();
	minHeapify(0);
	return min.first;
}

void minHeap::decreaseKey(int i, int key)
{
	if (key > heap[i].second) {
		//cout << "ERROR: New key greater than current key";
		return;
	}

	heap[i].second = key;
	while (i > 0 && heap[(i - 1) / 2].second > heap[i].second) {
		pair<vertex*, int> temp = heap[i];
		heap[i] = heap[(i - 1) / 2];
		heap[(i - 1) / 2] = temp;
		i = (i - 1) / 2;
	}
}

void minHeap::insertKey(vertex* node, int key)
{
	pair<vertex*, int> temp;
	temp.first = node;
	temp.second = INT_MAX;
	heap.push_back(temp);
	decreaseKey(getSize() - 1, key);
}


void printPath(vertex* s, vertex* v)
{

	if (v == s) {
		cout << s->getName() << endl;
	}
	else if (v->getPie() == NULL) {
		//cout << "no path from: " << s->getName() << " to " << v->getName() << endl;
	}
	else {
		printPath(s, v->getPie());
		cout << v->getName() << "-->";
	}
}

void bfs(vertex s)
{
	s.setColor(1);
	s.setDistance(0);
	s.setPie(NULL);

	queue<vertex*> q;
	q.push(&s);
	while (!q.empty()) {
		vertex* u = q.front();
		q.pop();
		vector<pair<vertex*, int>> temp = (u->getAdj());
		for (int i = 0; i < temp.size(); i++) {
			vertex* v = temp[i].first;
			if (v->getColor() == 0) {
				v->setColor(1);
				v->setDistance(u->getDistance() + 1);
				v->setPie(u);
				q.push(v);
			}
		}
		u->setColor(2);
	}
}

void dijkstras(vertex s)
{
	s.setDistance(0);
	minHeap hold;
	hold.insertKey(&s, 0);
	while (hold.getSize() > 0) {
		vertex* u = hold.extractMin();
		vector<pair<vertex*, int>> temp = u->getAdj();
		for (int i = 0; i < temp.size(); i++) {
			relax(u, temp[i].first, temp[i].second, &hold);
		}
	}
}

void relax(vertex* u, vertex* v, int w, minHeap* x)
{
	if (v->getDistance() > u->getDistance() + w) {
		v->setDistance(u->getDistance() + w);
		v->setPie(u);
		x->insertKey(v, v->getDistance());
	}
}

void prims(vertex r)
{
	//using distance as keys for prims
	r.setDistance(0);
	minHeap hold;
	hold.insertKey(&r, 0);
	map<vertex*, vertex*> inMST;

	while (hold.getSize() > 0) {
		vertex* u = hold.extractMin();
		vector<pair<vertex*, int>> temp = u->getAdj();
		for (int i = 0; i < temp.size(); i++) {
			vertex* v = temp[i].first;
			inMST[u] = u->getPie();
			if (inMST.find(v) == inMST.end() && temp[i].second < v->getDistance()) {
				v->setPie(u);
				v->setDistance(temp[i].second);
				if (v->getName() != "Hobbiton") {
					hold.insertKey(v, temp[i].second);
				}
			}
		}
		
	}

	for (auto it = inMST.begin(); it != inMST.end(); ++it) {
		vertex* u = it->first;
		vertex* v = it->second;
		cout << u->getName() << ": ";
		if (v != nullptr) {
			cout << v->getName() << endl;
		}
		else {
			cout << "NULL" << endl;
		}
	}
}

