/* File: trees.h
 * Course: CS315
 * Project: Project 1 Sorting
 */

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

#ifndef TREES_H
#define	TREES_H

using namespace std;

void convertIn(string s, int* array);

class nodes {
	public:
		nodes();
		nodes(int key);
		int getKey() const;
		int getColor() const;
		nodes* getLeft() const;
		nodes* getRight() const;
		nodes* getParent() const;
		void setcolor(int color);
		void setParent(nodes* x);
		void setLeft(nodes* x);
		void setRight(nodes* x);
	private:
		nodes *parent;
		nodes *leftChild;
		nodes *rightChild;
		int keyValue;
		int color;
};

class trees {
	public:
		trees();
		trees(nodes *x);
		nodes* getRoot() const;
		void treeInsert(nodes *x);
		void treeDelete(nodes *x);
		void transplant(nodes *x, nodes *y);
		void setRoot(nodes* x);
	private:
		nodes *treeRoot;
};

class redBlack {
	public:
		redBlack();
		redBlack(nodes* x);
		nodes* getRoot() const;
		void rbInsert(nodes* x);
		void rbInsertFix(nodes* x);
		void leftRotate(nodes* x);
		void rightRotate(nodes* x);
		void rbDelete(nodes* x);
		void rbDeleteFix(nodes* x);
		void rbTransplant(nodes* x, nodes* y);
		void setRoot(nodes* x);
	private:
		nodes* treeRoot;
};

void treeWalk(nodes* x);
int findDepth(nodes* x);
nodes* findMin(nodes* x);
nodes* findMax(nodes* x);
nodes* treeSearch(nodes* x, int key);

#endif

