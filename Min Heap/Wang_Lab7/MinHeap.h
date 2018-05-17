#ifndef MINHEAP
#define MINHEAP

class MinHeap
{
    public:
        MinHeap();
        ~MinHeap();
        void insert(int value);
        void heapify();
        void deletemin();
        void deletemax();
        void levelorder();
        void trickleDown(int index);
        void shiftDownMin(int index);
        void shiftDownMax(int index);
        void shiftUp(int index);
        void shiftUpMin(int index);
        void shiftUpMax(int index);
        int size;
        int place;
        int myArray[200];
};
#endif
