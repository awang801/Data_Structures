#include <iostream>
#include "Node.h"
#include "BinarySearchTree.h"
#include <fstream>

int main ()
{
        int e = 0;
        int choice;
        BinarySearchTree BST;
        int c1;
        int toInsert;
        std::ifstream myReadFile;
        myReadFile.open("data.txt");
        while (myReadFile >> toInsert)
        {
            BST.insert(toInsert);
        }
        myReadFile.close();
        while (e ==0)
        {
            std::cout << "\n\nSelect from the following menu:\n"
                         "1- insert\n"
                         "2- remove\n"
                         "3- deletemin\n"
                         "4- deletemax\n"
                         "5- preorder\n"
                         "6- inorder\n"
                         "7- levelorder\n"
                         "8- exit\n";
            std::cin >> choice;
            if (choice == 1)
            {
                std::cout << "\nPlease insert the number that you want to be inserted in the tree: \n";
                std::cin >> c1;
                BST.insert(c1);
            }
            else if (choice == 2)
            {
                std::cout << "\nWhich number do you like to remove from the tree? \n";
                std::cin >> c1;
                BST.remove(c1);
            }
            else if (choice == 3)
            {
                BST.deletemin();
            }
            else if (choice == 4)
            {
                BST.deletemax();
            }
            else if (choice == 5)
            {
                std::cout << "preorder: ";
                BST.preorder(BST.m_root);
            }
            else if (choice == 6)
            {
                std::cout << "inorder: ";
                BST.inorder(BST.m_root);
            }
            else if (choice == 7)
            {
                std::cout << "levelorder: ";
                BST.levelorder(BST.m_root);
            }
            else if(choice == 8)
            {
                e = 1;
            }

        }
        return(0);
}
