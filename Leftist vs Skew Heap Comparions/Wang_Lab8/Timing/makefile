lab8: main.o Node.o SkewHeap.o BinarySearchTree.o timer.h timer.hpp
	g++ -std=c++11 -g -Wall main.o Node.o SkewHeap.o BinarySearchTree.o -o lab8
main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp
Node.o: Node.h Node.cpp
	g++ -std=c++11 -g -Wall -c Node.cpp
SkewHeap.o: SkewHeap.h SkewHeap.cpp
	g++ -std=c++11 -g -Wall -c SkewHeap.cpp
BinarySearchTree.o: BinarySearchTree.h BinarySearchTree.cpp
	g++ -std=c++11 -g -Wall -c BinarySearchTree.cpp
clean: 
	rm *.o lab8
	echo clean done 
