/* File: Graph.cpp
 * Course: CS216-001
 * Project: Project 3 Part 1
 * Purpose: the implementation of member functions for the Graph class.
 *
 */

#include <iostream>
#include <queue>
#include "Graph.h"

// default constructor
Graph::Graph(){
}
    
// to check if an edge exists between v and w
    bool Graph::hasEdge(char v, char w) const{
	map<char, set<char> >::const_iterator i = adjMap.find(v);
	if(i != adjMap.end()){
		//iterate through the map values of v to see if edge exits
		set<char> temp = i->second;
		for(auto j = temp.begin(); j != temp.end(); j++){
			if(w == *j){
				return true;
			}
		}	
	}
	return false;
    } 
    
// to add an edge beween v and w to the graph
void Graph::addEdge(char v, char w){
	   adjMap[v].insert(w);
	   adjMap[w].insert(v);
}
    
// Apply BFS traversal to find the shortest path from the given source s to destination t
// return the distnace from s to t
// if s or t does not exist, return INVALID_VERTEX (=-2) 
// if there is no path from s to t, return NOPATH (=-1)
// store the shortest path distance from the given source s  to vertex w in distance map<w, distance>
// store which next vertex to go through on the shortest path to the given source s in go_through map<w, v>. 
// Here a pair <w, v> in go_through map represents on the shortest path from w to the given source s, it needs to take the path: w-->v...-->s  
int Graph::BFS(char s, char t, map<char, int>& distance, map<char, char>& go_through) const{
     
     //return -2 if s or t does not exit	
     if(adjMap.find(s) == adjMap.end() || adjMap.find(t) == adjMap.end()){
	     return -2;
     }else{
	//set all distance keys to have a -1 value
	map<char, set<char> >::const_iterator m;
	for(m = adjMap.begin(); m != adjMap.end(); m++){
		distance.insert(pair<char, int>(m->first, -1));	
	}
	
	queue<char> holdQ;
	distance[s] = 0;

	//puts the values of s into queue
	holdQ.push(s);
 	map<char, set<char> >::const_iterator i = adjMap.find(s);
	set<char> initialQ = i->second;
	for(auto k = initialQ.begin(); k != initialQ.end(); k++){
		holdQ.push(*k);
	}

    	char current = s;
	
	while(!holdQ.empty() && current != t){
		current = holdQ.front();
		holdQ.pop();
		//looks at the values of the current key
		map<char, set<char> >::const_iterator n = adjMap.find(current);
		if(n != adjMap.end()){
			set<char> temp = n->second;
			for(auto l = temp.begin(); l != temp.end(); l++){
				//if the value is -1, the distance of the vertex increases, and is put in go_through	
				//the original values' values, are placed in the queue
				if(distance[*l] == -1){
					distance[*l] = distance[current] + 1;
					go_through.insert(pair<char, char>(*l, current));
					holdQ.push(*l);	
				}
				
			}
		}	
	} //keeps count of the shortest distance from s to t
	return distance[t];
    }
}

