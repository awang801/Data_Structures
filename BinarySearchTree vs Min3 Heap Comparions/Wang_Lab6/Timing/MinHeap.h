#ifndef MINHEAP
#define MINHEAP

class MinHeap
{
    public:
        MinHeap();
        MinHeap(long size);
        ~MinHeap();
        void insert(long num);
        void deletemin();
        void deletemax();
        void remove(long num);
        void levelorder();
        void prlongSet(long index); //prlongs 3 nodes who all share the same parent
        bool shiftUp(long index);
        bool shiftDown(long index);
        long* myArray;
        long maxIndex;
        long currentIndex;
};
#endif
