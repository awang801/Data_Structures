#ifndef MINHEAP
#define MINHEAP

class MinHeap
{
    public:
        MinHeap();
        ~MinHeap();
        void insert(int num);
        void deletemin();
        void deletemax();
        void remove(int num);
        void levelorder();
        void printSet(int index); //prints 3 nodes who all share the same parent
        bool shiftUp(int index);
        bool shiftDown(int index);
        int myArray[200];
        int maxIndex;
        int currentIndex;
};
#endif
