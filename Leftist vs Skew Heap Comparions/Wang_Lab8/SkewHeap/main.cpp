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
                         "2- deletemin\n"
                         "3- preorder\n"
                         "4- inorder\n"
                         "5- Levelorder\n"
                         "6- end\n";
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
                BST.preorder(BST.m_root);
            }
            else if (choice == 4)
            {
                BST.inorder(BST.m_root);
            }
            else if (choice == 5)
            {
                BST.levelorder(BST.m_root);
            }
            else if (choice == 6)
            {
                e = 1;
            }
            else
            {

            }

        }
        return(0);
}
