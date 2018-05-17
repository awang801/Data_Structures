#include "MinHeap.h"
#include <iostream>
using namespace std;

MinHeap::MinHeap()
{
    maxIndex = 0;
    currentIndex = 0;
    //myArray = new long[0];
}

MinHeap::MinHeap(long size)
{
    myArray = new long[size];
    for (long i=0; i<size; i++)
    {
      myArray[i] = 0;
    }
}
MinHeap::~MinHeap()
{
  
}

void MinHeap::insert(long num)
{
    bool end = true;
    currentIndex = maxIndex;
    myArray[maxIndex] = num;
    while(end)
    {
        end = shiftUp(currentIndex);
    }
    maxIndex++;
}

void MinHeap::deletemin()
{
    if (maxIndex == 0)
    {
        return;
    }
    else if (maxIndex == 1)
    {
        myArray[0] = 0;
        maxIndex--;
    }
    else
    {
        bool end = true;
        long change = myArray[maxIndex-1];
        myArray[maxIndex-1] = 0;
        myArray[0] = change;
        currentIndex = 0;
        while(end)
        {
            end = shiftDown(currentIndex);
        }
        maxIndex--;
    }
}

void MinHeap::deletemax()
{
    if (maxIndex == 0)
    {
        return;
    }
    else if (maxIndex == 1)
    {
        myArray[0] = 0;
        maxIndex--;
    }
    else
    {
        long max = 0;
        long spot = 0;
        long index = ((maxIndex - 2)/3) + 1;
        while(index < maxIndex)
        {
            if (myArray[index] > max)
            {
                max = myArray[index];
                spot = index;
            }
            index++;
        }
        if (myArray[maxIndex-1] == max)
        {
            myArray[maxIndex-1] = 0;
            maxIndex--;
        }
        else
        {
            myArray[spot] = myArray[maxIndex-1];
            myArray[maxIndex-1] = 0;
            bool end = true;
            currentIndex = spot;
            while(end)
            {
                end = shiftUp(currentIndex);
            }
            maxIndex--;
        }
    }
}

void MinHeap::remove(long num)
{
    long index = 0;
    bool end = true;
    while(index < maxIndex)
    {
        if (myArray[index] == num)
        {
            myArray[index] = myArray[maxIndex-1];
            myArray[maxIndex-1] = 0;
            currentIndex = index;
            while(end)
            {
                end = shiftUp(currentIndex);
            }
            currentIndex = index;
            end = true;
            while(end)
            {
                end = shiftDown(currentIndex);
            }
            maxIndex--;
        }
        index++;
    }
    for(long i = 0; i < maxIndex; i++)
    {
        if (myArray[i] == num)
        {
            remove(num);
        }
    }
}

bool MinHeap::shiftUp(long index)
{
    if (myArray[index] == 0)
    {
        return false;
    }
    else
    {
        long parent = (index-1)/3;
        if (myArray[index] < myArray[parent])
        {
            long change = myArray[parent];
            myArray[parent] = myArray[index];
            myArray[index] = change;
            currentIndex = parent;
            return true;
        }
        else
        {
            return false;
        }
    }
}

bool MinHeap::shiftDown(long index)
{
    long child = (3*index)+1;

    if(index == 0)
    {
        child = 1;
    }

    if(myArray[child] == 0)
    {
        return false;
    }
    else
    {
        long min = myArray[child];
        long minChild = child;
        for (long i = 1; i < 3; i++)
        {
            if (myArray[child + i] != 0 && myArray[child + i] < min)
            {
                min = myArray[child + i];
                minChild = child + i;

            }
        }
        if (myArray[index] > myArray[minChild])
        {
            long change = myArray[minChild];
            long in = myArray[index];

            myArray[minChild] = in;
            myArray[index] = change;
            currentIndex = minChild;

            return true;
        }
        else
        {
            return false;
        }

    }
}

void MinHeap::levelorder()
{
    long i = 1;
    long levelSize = 3;
    if (maxIndex > 0)
    {
        std::cout << "\n"<< myArray[0] << "\n";
    }
    if (maxIndex > 1)
    {
      while(i<maxIndex)
      {
        do
        {
        prlongSet(i);

          if(myArray[i+3] != 0 && (i+3) < levelSize)
          {
              std::cout << "- ";
          }
          i = i + 3;
        }while(i <= levelSize || myArray[i] == 0);
        levelSize = levelSize*3 + levelSize;
        std::cout << "\n";
      }
    }

}

void MinHeap::prlongSet(long index)
{
    long i = 0;
    while(i < 3 && myArray[index] != 0)
    {
        std::cout << myArray[index] << " ";
        i++;
        index++;
    }
}
