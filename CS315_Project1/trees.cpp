#include "trees.h"

using namespace std;

void convertIn(string s, int* array)
{
		ifstream infile;
		infile.open(s);

		int size = 0;

		if (infile.is_open()) {
			string line;
			while (getline(infile, line)) {
				stringstream temp(line);
				string hold;
				while (getline(temp, hold, ',')) {
					getline(temp, hold, ',');
					array[size] = stoi(hold);
					size++;
				}
			}

			infile.close();

		}
		else {
			cout << "Error: File not found!?!?!" << endl;
		}

}
nodes::nodes()
{
	parent = NULL;
	leftChild = NULL;
	rightChild = NULL;
	keyValue = -1;
	color = 1;
}

nodes::nodes(int key)
{
	parent = NULL;
	leftChild = NULL;
	rightChild = NULL;
	keyValue = key;
	color = 1;
}

int nodes::getKey() const
{
	return keyValue;
}

int nodes::getColor() const
{
	return color;
}

nodes* nodes::getLeft() const
{
	return leftChild;
}

nodes* nodes::getRight() const
{
	return rightChild;
}

nodes* nodes::getParent() const
{
	return parent;
}

void nodes::setcolor(int color)
{
	this->color = color;
}

void nodes::setParent(nodes* x)
{
	parent = x;
}

void nodes::setLeft(nodes* x)
{
	leftChild = x;
}

void nodes::setRight(nodes* x)
{
	rightChild = x;
}

trees::trees()
{
	treeRoot = NULL;
}

trees::trees(nodes* x)
{
	treeRoot = x;
}

nodes* trees::getRoot() const
{
	return treeRoot;
}

void trees::treeInsert(nodes* x)
{
	nodes* y = NULL;
	nodes* temp = getRoot();
	while (temp != NULL) {
		y = temp;
		if ((*x).getKey()< (*temp).getKey()) {
			temp = (*temp).getLeft();
		}
		else {
			temp = (*temp).getRight();
		}
	}
	(*x).setParent(y);
	if (y == NULL) {
		setRoot(x);
	}
	else if ((*x).getKey() < (*y).getKey()) {
		(*y).setLeft(x);
	}
	else {
		(*y).setRight(x);
	}
}

void trees::treeDelete(nodes* x)
{
	if (x == NULL) {
		return;
	}

	if (x == getRoot()) {
		setRoot(NULL);
	}
	
	if ((*x).getLeft() == NULL) {
		transplant(x, (*x).getRight());
	}
	else if ((*x).getRight() == NULL) {
		transplant(x, (*x).getLeft());
	}
	
	else {
		nodes* y = findMin((*x).getRight());
		if ((*y).getParent() != x) {
			transplant(y, (*y).getRight());
			(*y).setRight((*x).getRight());
			(*(*y).getRight()).setParent(y);
		}
		transplant(x, y);
		(*y).setLeft((*x).getLeft());
		(*(*y).getLeft()).setParent(y);
	}
	
}

void trees::transplant(nodes* x, nodes* y)
{
	if ((*x).getParent() == NULL) {
		setRoot(y);
	}else {
		nodes* parent = (*x).getParent();
		if ((*parent).getLeft() == x) {
			(*parent).setLeft(y);
		}else {
			(*parent).setRight(y);
		}
	}

	if (y != NULL){
		(*y).setParent((*x).getParent());
	}
}

void trees::setRoot(nodes* x)
{
	treeRoot = x;
}

redBlack::redBlack()
{
	treeRoot = NULL;
}

redBlack::redBlack(nodes* x)
{
	treeRoot = x;
}

nodes* redBlack::getRoot() const
{
	return treeRoot;
}

void redBlack::rbInsert(nodes* x)
{
	nodes* y = NULL;
	nodes* temp = getRoot();
	while (temp != NULL) {
		y = temp;
		if ((*x).getKey() < (*temp).getKey()) {
			temp = (*temp).getLeft();
		}
		else {
			temp = (*temp).getRight();
		}
	}
	(*x).setParent(y);
	if (y == NULL) {
		setRoot(x);
	}
	else if ((*x).getKey() < (*y).getKey()) {
		(*y).setLeft(x);
	}
	else {
		(*y).setRight(x);
	}

	(*x).setLeft(NULL);
	(*x).setRight(NULL);
	(*x).setcolor(1);
	rbInsertFix(x);
}

void redBlack::rbInsertFix(nodes* x)
{
	while (x != NULL && (*x).getParent() != NULL && (*(*x).getParent()).getColor() == 1) {
		nodes* parent = (*x).getParent();
		nodes* gPa = (*parent).getParent();

		if (parent == (*gPa).getLeft()) {
			nodes* y = (*gPa).getRight();
			if (y != NULL && (*y).getColor() == 1) {
				(*parent).setcolor(0);
				(*y).setcolor(0);
				(*gPa).setcolor(1);
				x = gPa;
			}
			else {
				if (x == (*parent).getRight()) {
					x = parent;
					leftRotate(x);
					parent = (*x).getParent();
				}
				(*parent).setcolor(0);
				(*gPa).setcolor(1);
				rightRotate(gPa);
				x = parent;
			}
		}
		else {
			nodes* y = (*gPa).getLeft();
			if (y != NULL && (*y).getColor() == 1) {
				(*parent).setcolor(0);
				(*y).setcolor(0);
				(*gPa).setcolor(1);
				x = gPa;
			}
			else {
				if (x == (*parent).getLeft()) {
					x = parent;
					rightRotate(x);
					parent = (*x).getParent();
				}
				(*parent).setcolor(0);
				(*gPa).setcolor(1);
				leftRotate(gPa);
				x = parent;
			}
		}
	}
	this->treeRoot->setcolor(0);
}

void redBlack::leftRotate(nodes* x)
{
	nodes* y = (*x).getRight();
	(*x).setRight((*y).getLeft());
	if ((*y).getLeft() != NULL) {
		(*(*y).getLeft()).setParent(x);
	}

	(*y).setParent((*x).getParent());
	if ((*x).getParent() == NULL) {
		this->treeRoot = y;
	}
	else if (x == (*(*x).getParent()).getLeft()){
		(*(*x).getParent()).setLeft(y);
	}
	else {
		(*(*x).getParent()).setRight(y);
	}
	(*y).setLeft(x);
	(*x).setParent(y);
}

void redBlack::rightRotate(nodes* x)
{
	nodes* y = (*x).getLeft();
	(*x).setLeft((*y).getRight());
	if ((*y).getRight() != NULL) {
		(*(*y).getRight()).setParent(x);
	}

	(*y).setParent((*x).getParent());
	if ((*x).getParent() == NULL) {
		this->treeRoot = y;
	}
	else if (x == (*(*x).getParent()).getLeft()) {
		(*(*x).getParent()).setLeft(y);
	}
	else {
		(*(*x).getParent()).setRight(y);
	}
	(*y).setRight(x);
	(*x).setParent(y);
	//BRENT HARRISoN IF YOU SEE THIS OMG YOU OWE ME FIVE DOLLARS THIS PRJECT WAS SO ASS IT TOOK ME SO LONG 
}

void redBlack::rbDelete(nodes* x)
{
	nodes* y = x;
	nodes* z = NULL;
	int yOrigColor = (*y).getColor();

	if ((*x).getLeft() == NULL) {
		z = (*x).getRight();
		rbTransplant(x, (*x).getRight());
	}
	else if ((*x).getRight() == NULL) {
		z = (*x).getLeft();
		rbTransplant(x, (*x).getLeft());
	} else {
		y = findMin((*x).getRight());
		yOrigColor = (*y).getColor();
		z = (*y).getRight();
		if ((*y).getParent() == x) {
			if (z != NULL) {
				(*z).setParent(y);
			}
		}else {
			rbTransplant(y, (*y).getRight());
			(*y).setRight((*x).getRight());
			(*(*y).getRight()).setParent(y);
		}
		rbTransplant(x, y);
		(*y).setLeft((*x).getLeft());
		(*(*y).getLeft()).setParent(y);
		(*y).setcolor((*x).getColor());
	}

	if (yOrigColor == 0) {
		if (z == NULL) {
			rbDeleteFix((*y).getParent());
		}else {
			rbDeleteFix(z);
		}
	}
}

void redBlack::rbDeleteFix(nodes* x)
{
	if (x != NULL) {
		return;
	}
	while (x != getRoot() && (*x).getColor() == 0) {
		if(x == (*(*x).getParent()).getLeft()) {
			nodes* w = (*(*x).getParent()).getRight();
			if ((*w).getColor() == 1) {
				(*w).setcolor(0);
				(*(*x).getParent()).setcolor(1);
				leftRotate((*x).getParent());
				w = (*(*x).getParent()).getRight();
			}
			if ((*(*w).getLeft()).getColor() == 0 && (*(*w).getRight()).getColor() == 0) {
				(*w).setcolor(1);
				x = (*x).getParent();
			}
			else{
				if ((*(*w).getRight()).getColor() == 0) {
					(*(*w).getLeft()).setcolor(0);
					(*w).setcolor(1);
					rightRotate(w);
					w = (*(*x).getParent()).getRight();
				}
				(*w).setcolor((*(*x).getParent()).getColor());
				(*(*x).getParent()).setcolor(0);
				(*(*w).getRight()).setcolor(0);
				leftRotate((*x).getParent());
				x = getRoot();
			}
		}
		else {
				nodes* w = (*(*x).getParent()).getLeft();
				if ((*w).getColor() == 1) {
					(*w).setcolor(0);
					(*(*x).getParent()).setcolor(1);
					rightRotate((*x).getParent());
					w = (*(*x).getParent()).getLeft();
				}
				if ((*(*w).getRight()).getColor() == 0 && (*(*w).getLeft()).getColor() == 0) {
					(*w).setcolor(1);
					x = (*x).getParent();
				}
				else {
					if ((*(*w).getLeft()).getColor() == 0) {
						(*(*w).getRight()).setcolor(0);
						(*w).setcolor(1);
						leftRotate(w);
						w = (*(*x).getParent()).getLeft();
					}
					(*w).setcolor((*(*x).getParent()).getColor());
					(*(*x).getParent()).setcolor(0);
					(*(*w).getLeft()).setcolor(0);
					rightRotate((*x).getParent());
					x = getRoot();
			}
		}
	}
		(*x).setcolor(0);
}

void redBlack::rbTransplant(nodes* x, nodes* y)
{
	if ((*x).getParent() == NULL) {
		setRoot(y);
	}
	else {
		nodes* parent = (*x).getParent();
		if ((*parent).getLeft() == x) {
			(*parent).setLeft(y);
		}
		else {
			(*parent).setRight(y);
		}
	}
	if (y != NULL) {
		(*y).setParent((*x).getParent());
	}
}

void redBlack::setRoot(nodes* x)
{
	treeRoot = x;
}

void treeWalk(nodes *x)
{
	if (x == NULL) {
		return;
	}else{
		treeWalk((*x).getLeft());
		cout << (*x).getKey() << " ";
		treeWalk((*x).getRight());
	}
}

int findDepth(nodes* x)
{
	if (x != NULL) {
		int leftD = findDepth((*x).getLeft());
		int rightD = findDepth((*x).getRight());

		if (leftD > rightD) {
			return leftD + 1;
		}
		else {
			return rightD + 1;
		}
	}
	else {
		return 0;
	}
}

nodes* findMin(nodes* x) {
	if (x == NULL) {
		return NULL;
	}

	while ((*x).getLeft() != NULL) {
		x = (*x).getLeft();
	}
	return x;
}

nodes* findMax(nodes* x)
{
	while ((*x).getRight() != NULL) {
		x = (*x).getRight();
	}
	return x;
}

nodes* treeSearch(nodes* x, int key)
{
	if ((*x).getLeft() == NULL && (*x).getRight() == NULL || key == (*x).getKey()) {
		return x;
	}
	if (key < (*x).getKey()) {
		return treeSearch((*x).getLeft(), key);
	}
	else {
		return treeSearch((*x).getRight(), key);
	}
}
