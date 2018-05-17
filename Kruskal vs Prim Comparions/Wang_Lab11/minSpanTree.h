#include "BinarySearchTree.h"
#include "Node.h"

#ifndef SPAN_TREE
#define SPAN_TREE

class minSpanTree
{
    public:
        minSpanTree(int** matrixData, Node ** e, Node** solution, int s);
        ~minSpanTree();
        void kruskal();
        void prim();
        BinarySearchTree skew; //skew heap
        int** matrix;
        Node** solutionArray;
        int size;
        Node** edgeArray;
};
#endif
