#include "BinarySearchTree.h"
#include "dijkstra.h"
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream infile;
    infile.open("data.txt");
    int numGraphs = 0;
    infile >> numGraphs;

    for(int z = 0; z < numGraphs; z++)
    {
        int vertices;

        infile >> vertices;
        //std::cout << vertices;


        int** graph = new int*[vertices];

        for(int i = 0; i < vertices; i++)
        {
            graph[i] = new int[vertices];
            for(int j = 0; j < vertices; j++)
                infile >> graph[i][j];
        }
        Dijkstra dijk(vertices, graph);
        int* pathWeights = dijk.Calculate();
        //std::cout << "test2";


        for(int i = 0; i < vertices; i++)
        {
            std::cout << pathWeights[i] << " ";
        }

            std::cout << "\n";

    }
    return 0;
}
