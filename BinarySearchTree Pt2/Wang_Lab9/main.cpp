#include <iostream>
#include "BinarySearchTree.h"
#include <fstream>

int main ()
{
        int e = 0;
        int choice;
        BinarySearchTree BST;
        int c1;
        int toInsert;

        BST.insert(3);
        BST.insert(8);
        BST.insert(6);
        BST.insert(4);
        BST.insert(2);
        BST.insert(7);
        BST.insert(9);
        BST.insert(16);
        BST.insert(1);
        BST.insert(5);
        BST.insert(10);
        while (e ==0)
        {
            std::cout << "\n\nSelect from the following menu:\n"
                         "1- insert\n"
                         "2- deletemin\n"
                         "3- levelorder\n"
                         "4- exit\n";
            std::cin >> choice;
            if (choice == 1)
            {
                std::cout << "\nPlease insert the number that you want to be inserted in the tree: \n";
                std::cin >> c1;
                BST.insert(c1);
            }
            else if (choice == 2)
            {
                BST.deletemin();
            }
            else if (choice == 3)
            {
                std::cout << "levelorder: \n";
                BST.levelorder();
            }
            else if(choice == 4)
            {
                e = 1;
            }

        }
        return(0);
}
