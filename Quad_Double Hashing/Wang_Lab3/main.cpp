/* main.cpp
 * Alan Wang
 * main class
 * diplays choices and outputs, and takes in inputs from user
 */
#include <iostream>
#include "DoubleLinkedList.h"
#include <stdexcept>
#include <fstream>
int main()
{

    int e = 0; //conditional for while loop
    int choice; // input for choose a function
    int c; // input value for whichever function is chosen.
    int hashType;

    std::cout << "\n\n Please Choose one of the following hash methods:\n"
              << "1 - Quadratic\n"
              << "2 - Double Hashing\n"
              << "3 - exit\n";

    std::cin >> choice;
    if(choice == 3)
    {
        e = 0;
    }
    else
    {
        hashType = choice;
    }


    std::ifstream myReadFile;
    myReadFile.open("text.txt");\
    std::string textValue;
    myReadFile >> textValue;
    DoubleLinkedList<int>* l = new DoubleLinkedList<int>(std::stoi(textValue));
    l->setHashType(hashType);
    while (!myReadFile.eof())
    {\

        myReadFile >> textValue;
        l->insert(std::stoi(textValue));
        if(myReadFile.eof())
        {
            break;
        }

    }
    myReadFile.close();



    while(e ==0) //value e will only change when user hits 7
    {
        std::cout << "\n\nSelect from the following menu:\n"
                << "1) Insert\n"
                << "2) Delete\n"
                << "3) Print\n"
                << "4) Exit\n"
                << "Enter your choice: \n";
    std::cin >> choice;
    if(choice == 1)
    {
        std::cout<<"Enter a value of your choice";
        std::cin >> c;
        if(l->insert(c))
        {
            std::cout << "value successfully inserted";
        }
        else
        {
            std::cout << "value unsuccessfully inserted";
        }
    }
    if(choice==2)
    {
        std::cout << "Enter your value of choice: ";
        std::cin >> c;
        if(l->deletenode(c))
        {
            std::cout << "Value Successfully removed";
        }
        else
        {
            std::cout << "Value not found in List";
        }
    }
    if (choice ==3)
    {
        l->print();
    }
    if (choice==4)
    {
        e = 1;
    }
    }
    return(0);//calls the destructor
}

