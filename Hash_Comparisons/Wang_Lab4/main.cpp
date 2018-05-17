/* main.cpp
 * Alan Wang
 * main class
 * diplays choices and outputs, and takes in inputs from user
 */
#include <iostream>
#include "DoubleLinkedList.h"
#include <stdexcept>
#include <fstream>
#include "OpenHash.h"
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include "timer.h"
int main()
{
    long rando;
    double duration;


    std::ifstream myReadFile;
    myReadFile.open("text.txt");\
    std::string textValue;
    myReadFile >> textValue;
    DoubleLinkedList<long>* l = new DoubleLinkedList<long>(600011);
    DoubleLinkedList<long>* l2 = new DoubleLinkedList<long>(600011);

    Timer timer;
    l->setHashType(1);
    l2->setHashType(2);
    srand (time(NULL));

        for(double i=0.2; i<=0.9; i+=0.1)
        {
            std::cout << "Open Hash with factor: " << i << "\n";

            for(int k=0; k<5; k++)
            {
                OpenHash<long> open(600011);
                timer.start();
                for(long j=0; j<(i*600011); j++)
                {
                    rando = rand()%2147483647;
                    open.insert(rando);
                }
                duration = timer.stop();
                std::cout << duration<< "\n";
            }
        }
        for(double i=0.2; i<=0.9; i+=0.1)
        {

            std::cout << "Quadratic Hash with factor: " << i << "\n";

            for (int k=0; k<5; k++)
            {
                timer.start();
                for(long j=0; j<(i*600011); j++)
                {
                    rando = rand()%2147483647;
                    if(!l->find(rando))
                    {
                        l->insert(rando);
                    }
                }
                duration = timer.stop();
                std::cout << duration<< "\n";
            }
        }
        for(double i=0.2; i<=0.9; i+=0.1)
        {

            std::cout << "Double Hash with factor: " << i << "\n";
            for (int k=0; k<5; k++)
            {
                timer.start();
                for(long j=0; j<(i*600011); j++)
                {
                    rando = rand()%2147483647;
                    if(!l2->find(rando))
                    {
                        l2->insert(rando);
                    }
                }
                duration = timer.stop();
                std::cout << duration<< "\n";
            }
        }

    return(0);//calls the destructor
}

