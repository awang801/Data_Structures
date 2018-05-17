
#include <iostream>
#include "minSpanTree.h"
#include "BinarySearchTree.h"
#include "Node.h"
#include "disjoint.h"
#include <fstream>


int main ()
{
    std::ifstream infile;
    infile.open("data.txt");
    int input;

    int numGraphs = infile.get() - '0';
    int size;

    int numEdges;
    for (int i = 0; i < numGraphs; i++)
    {
        size = infile.get();
        while (!(isdigit(size)))
        {
            size = infile.get();
        }
        size -= '0';

        int** matrixData = new int*[size];
        for (int j = 0; j < size; j++)
        {
            matrixData[j] = new int[size];

            for (int k = 0; k < size; k++)
            {
                infile >> input;
                matrixData[j][k] = input;
                if (matrixData[j][k] != 0)
                {
                    numEdges++;
                }
            }
        }

        Node** e = new Node*[numEdges];
        Node** solution = new Node*[numEdges];
        for (int k = 0; k < numEdges; k++)
        {
            solution[k] = nullptr;
            e[k] = nullptr;
        }

        std::cout << "Graph" << i+1 << ":\n";

        minSpanTree * span = new minSpanTree(matrixData, e, solution, size);
        span->kruskal();
        std::cout << "\n";

        span->prim();
        std::cout << "\n\n";

        delete span;
    }
    infile.close();

}
