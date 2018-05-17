lab6: main.o Node.o BinarySearchTree.o MinHeap.o
	g++ -std=c++11 -g -Wall main.o Node.o BinarySearchTree.o -o lab6
main.o: main.cpp timer.h timer.hpp
	g++ -std=c++11 -g -Wall -c main.cpp
Node.o: Node.h Node.cpp
	g++ -std=c++11 -g -Wall -c Node.cpp
BinarySearchTree.o: BinarySearchTree.h BinarySearchTree.cpp
	g++ -std=c++11 -g -Wall -c BinarySearchTree.cpp
MinHeap.o: MinHeap.h MinHeap.cpp
	g++ -std=c++11 -g -Wall -c MinHeap.cpp
	
clean: 
	rm *.o lab6
	echo clean done 
