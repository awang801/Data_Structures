#include <iostream>
#include "Node.h"
#include "SkewHeap.h"
#include "BinarySearchTree.h"
#include "timer.h"
#include <fstream>

int main ()
{
    long rando;
    double duration;
    long n = 50000;
    double x;

    BinarySearchTree Leftist;
    SkewHeap Skew;
    Timer timer;
      for(int i=1; i<=4; i++)
      {
        srand(i);
        std::cout << "Leftist Tree Building with n = " << n << "\n";
        for (int k = 0; k<5; k++)
        {
        timer.start();
          for (int j=0; j<n ; j++)
          {
            rando = rand()%(4*n);
            Leftist.insert(rando);
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

        std::cout << "Skew Heap Building with n = " << n << "\n";
        for (int k = 0; k<5; k++)
        {

          timer.start();
          for (int j=0; j<n ; j++)
          {
            rando = rand()%(4*n);
            Skew.insert(rando);
          }
          duration = timer.stop();
          std::cout << duration << "\n";



        }
        n = n+n;
      }

      n= 50000;

      for (int i = 1; i<=4; i++)
      {
        srand(i);
        std::cout << "Leftist Heap with n = " << n << "\n";
        for (int k = 0; k<5; k++)
        {
        timer.start();
          for (int j = 0; j<n; j++)
          {
            x = rand()%10;
            if (x >= 0 && x<5)
            {
              Leftist.deletemin();
            }
            else if (x >=5 && x<= 10)
            {
              rando = rand()%(4*n);
              Leftist.insert(rando);
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
        std::cout << "Skew Heap Operations with n = " << n << "\n";

        for (int k = 0; k<5; k++)
        {

        timer.start();

          for (int j = 0; j<n; j++)
          {

            x = rand()%10;
            if (x >= 0 && x<5)
            {
              Skew.deletemin();
            }
            else if (x >=5 && x<= 10)
            {
              rando = rand()%(4*n);
              Skew.insert(rando);

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
    return(0);
}
