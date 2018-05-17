
#include <iostream>
#include "minSpanTree.h"
#include "BinarySearchTree.h"
#include "Node.h"
#include "disjoint.h"
#include "timer.h"
#include <fstream>


int main ()
{
    int rando;
    Timer timer;
    int x;
    int y;
    double duration;
    int n;

    int numEdges;


    n = 1000;
    for (int h = 0; h <4; h++)
    {
      for (int i = 0; i < 5; i++)
      {
        srand(i);

        int** matrixData = new int*[n];
        for (int j = 0; j < n; j++)
        {
            matrixData[j] = new int[n];

            for (int k = 0; k < n; k++)
            {
              x = rand()%10;

              if (x >=0 && x<5)
              {
                matrixData[j][k] = 0;
              }
              else
              {
                rando = rand()%(4*n);
                matrixData[j][k] = rando;
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

          minSpanTree * span = new minSpanTree(matrixData, e, solution, n);
          timer.start();
          span->kruskal();
          duration = timer.stop();
          std::cout << "Kruskal's algorithm for size of "<< n << ": " << duration << "\n";
          delete span;
          minSpanTree * span2 = new minSpanTree(matrixData, e, solution, n);
          timer.start();
          span2->prim();
          duration = timer.stop();
          std::cout << "Prim's algorithm for size of "<< n << ": " << duration << "\n";
          delete span2;

        }
        n = n*2;
      }


}
