#include "trees.h"
#include <iostream>

using namespace std;

int main() {

    int* testRandom = new int[129];
    int* testBad = new int[129];
    int* deleteNodes = new int[15];
    string names[3] = { "testRandom.csv", "deleteNodes.csv", "testBad.csv"};

    convertIn(names[0], testRandom);
    trees tree1;
    
    for (int i = 0; i < 129; i++) {
        nodes* temp = new nodes(testRandom[i]);
        tree1.treeInsert(temp);
    }

    cout << "Inorder traversal after inserting testRandom.csv into BST : " << endl;

    treeWalk(tree1.getRoot());
    cout << endl << endl;
  
    cout << "Max depth of BST after inserting testRandom.csv:" << findDepth(tree1.getRoot()) << endl << endl;

    convertIn(names[1], deleteNodes);
    for (int i = 0; i < 15; i++) {
        nodes* temp = treeSearch(tree1.getRoot(), deleteNodes[i]);
        tree1.treeDelete(temp);
    }
    
    cout << "Inorder traversal after deleting deleteNodes.csv:" << endl;
    treeWalk(tree1.getRoot());
    cout << endl << endl;

    cout << "Max depth of BST after deleting deleteNodes.csv:" << findDepth(tree1.getRoot()) << endl << endl;

    convertIn(names[2], testBad);
    trees tree2;

    for (int i = 0; i < 129; i++) {
        nodes* temp = new nodes(testBad[i]);
        tree2.treeInsert(temp);
    }

    cout << "Inorder traversal after inserting testRandom.csv into BST : " << endl;

    treeWalk(tree2.getRoot());
    cout << endl << endl;

    cout << "Max depth of BST after inserting testRandom.csv:" << findDepth(tree2.getRoot()) << endl << endl;

    convertIn(names[1], deleteNodes);
    for (int i = 0; i < 15; i++) {
        nodes* temp = treeSearch(tree2.getRoot(), deleteNodes[i]);
        tree2.treeDelete(temp);
    }

    cout << "Inorder traversal after deleting deleteNodes.csv:" << endl;
    treeWalk(tree2.getRoot());
    cout << endl << endl;

    cout << "Max depth of BST after deleting deleteNodes.csv:" << findDepth(tree2.getRoot()) << endl << endl;
 
    redBlack tree3;

    for (int i = 0; i < 129; i++) {
        nodes* temp = new nodes(testRandom[i]);
        tree3.rbInsert(temp);
    }

    cout << "Inorder traversal after inserting testRandom.csv into RB Tree:" << endl;
    treeWalk(tree3.getRoot());
    cout << endl << endl;

    cout << "Max depth of BST after inserting testRandom.csv:" << findDepth(tree3.getRoot()) << endl << endl;
  
    for (int i = 0; i < 15; i++) {
        nodes* temp = treeSearch(tree3.getRoot(), deleteNodes[i]);
        tree3.rbDelete(temp);
    }

    cout << "Inorder traversal after deleting deleteNodes.csv:" << endl;
    treeWalk(tree3.getRoot());
    cout << endl << endl;

    cout << "Max depth of BST after deleting deleteNodes.csv:" << findDepth(tree3.getRoot()) << endl << endl;

    redBlack tree4;

    for (int i = 0; i < 129; i++) {
        nodes* temp = new nodes(testBad[i]);
        tree4.rbInsert(temp);
    }

    cout << "Inorder traversal after inserting testRandom.csv into RB Tree:" << endl;
    treeWalk(tree4.getRoot());
    cout << endl << endl;

    cout << "Max depth of BST after inserting testRandom.csv:" << findDepth(tree4.getRoot()) << endl << endl;

    for (int i = 0; i < 15; i++) {
        nodes* temp = treeSearch(tree4.getRoot(), deleteNodes[i]);
        tree4.rbDelete(temp);
    }

    cout << "Inorder traversal after deleting deleteNodes.csv:" << endl;
    treeWalk(tree4.getRoot());
    cout << endl << endl;

    cout << "Max depth of BST after deleting deleteNodes.csv:" << findDepth(tree4.getRoot()) << endl << endl;

}



    