#include <iostream>
#include "MinHeap.cpp"
#include <fstream>

int main ()
{
        int e = 0;
        int choice;
        MinHeap heap;
        int c1;
        int toInsert;
        std::ifstream myReadFile;
        myReadFile.open("data.txt");
        while (myReadFile >> toInsert)
        {
           heap.insert(toInsert);
        }
        myReadFile.close();
        while (e ==0)
        {
            std::cout << "\n\nSelect from the following menu:\n"
                         "1- insert\n"
                         "2- deletemin\n"
                         "3- deletemax\n"
                         "4- remove\n"
                         "5- levelorder\n"
                         "6- exit\n";
            std::cin >> choice;
            if (choice == 1)
            {
                std::cout << "\nPlease insert the number that you want to be inserted in the tree: \n";
                std::cin >> c1;
               heap.insert(c1);
            }
            else if (choice == 2)
            {
               heap.deletemin();
            }
            else if (choice == 3)
            {

                heap.deletemax();
            }
            else if (choice == 4)
            {

               std::cout << "\nWhich number do you like to remove from the tree? \n";
               std::cin >> c1;
              heap.remove(c1);
            }
            else if (choice == 5)
            {
              std::cout << "Level Order: ";
             heap.levelorder();
            }
            else if (choice == 6)
            {
                e = 1;
            }

        }
        return(0);
}
