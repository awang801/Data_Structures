#include <iostream>
#include "MinHeap.h"
#include <fstream>

using namespace std;

int main ()
{
        int e= 0; //conditional for while loop
        int choice = 0;
        int c;
        MinHeap myHeap;

        int nums = 0;
        ifstream infile;
        infile.open("data.txt");
        while (infile >> nums)
        {
            myHeap.insert(nums);
        }
        infile.close();
        myHeap.heapify();

        while(e==0)
        {
            std::cout << "\nSelect from the following menu:\n"
                         "1- insert\n"
                         "2- deletemin\n"
                         "3- deletemax\n"
                         "4- levelorder\n"
                         "5- exit\n";
            std::cin >> choice;

            if (choice == 1)
            {
                std::cout << "\nPlease insert the number that you want to be inserted in the tree: \n";
                std::cin >> c;
                myHeap.insert(c);
            }
            else if (choice == 2)
            {
                myHeap.deletemin();
            }
            else if (choice == 3)
            {
                myHeap.deletemax();
            }
            else if (choice == 4)
            {
                std::cout << "levelorder: \n";
                myHeap.levelorder();
            }
            else if(choice == 5)
            {
                myHeap.~MinHeap();
                e = 1;
            }

        }
}
