#include <iostream>
#include "Node.h"
#include "BinarySearchTree.h"
#include "MinHeap.cpp"
#include <fstream>
#include <stdio.h>
#include <time.h>
#include "timer.h"

int main ()
{
        long rando;
        double duration;
        long n = 50000;
        double x;

        BinarySearchTree BST;
        MinHeap* Heap = new MinHeap(500000);
        Timer timer;
          for(int i=1; i<=4; i++)
          {
            srand(i);
            std::cout << "Binary Search Tree Building with n = " << n << "\n";
            for (int k = 0; k<5; k++)
            {
            timer.start();
              for (int j=0; j<n ; j++)
              {
                rando = rand()%(4*n);
                BST.insert(rando);
              }
              duration = timer.stop();
              std::cout << duration << "\n";

            }
          n = n + n;
          }
          n = 50000;
          for(int i=1; i<=4; i++)
          {
            srand(i);

            std::cout << "Min 3 Heap Building with n = " << n << "\n";
            for (int k = 0; k<5; k++)
            {
              Heap = new MinHeap(500000);
              timer.start();
              for (int j=0; j<n ; j++)
              {
                rando = rand()%(4*n);
                Heap->insert(rando);
              }
              duration = timer.stop();
              std::cout << duration << "\n";
              delete Heap;
              Heap = NULL;

            }
            n = n+n;
          }

          n= 50000;

          for (int i = 1; i<=4; i++)
          {
            srand(i);
            std::cout << "Binary Search Tree with n = " << n << "\n";
            for (int k = 0; k<5; k++)
            {
            timer.start();
              for (int j = 0; j<n; j++)
              {
                x = rand()%10;
                if (x >= 0 && x<1)
                {
                  BST.deletemin();
                }
                else if (x>= 1 && x<2)
                {
                  BST.deletemax();
                }
                // else if (x>=2 && x<5)
                // {
                //   rando = rand()%(4*n);
                //   BST.remove(rando);
                // }
                else if (x >5 && x<= 10)
                {
                  rando = rand()%(4*n);
                  BST.insert(rando);
                }
                else
                {

                }

              }
              duration = timer.stop();
              std::cout << duration << "\n";

            }
            n = n + n;
          }

        n = 50000;

          for (int i = 1; i<=4; i++)
          {
            srand(i);
            std::cout << "Min 3 Heap with n = " << n << "\n";

            for (int k = 0; k<5; k++)
            {
            Heap = new MinHeap(500000);
            timer.start();

              for (int j = 0; j<n; j++)
              {

                x = rand()%10;
                if (x >= 0 && x<1)
                {
                  Heap->deletemin();
                }
                else if (x>= 1 && x<2)
                {
                  Heap->deletemax();
                }
                else if (x>=2 && x<5)
                {
                  rando = rand()%(4*n);
                  Heap->remove(rando);
                }
                else if (x >5 && x<= 10)
                {
                  rando = rand()%(4*n);
                  Heap->insert(rando);

                }
                else
                {

                }

              }
              duration = timer.stop();
              std::cout << duration << "\n";
              delete Heap;
              Heap = NULL;
            }
            n = n + n;
          }
        return(0);
}
