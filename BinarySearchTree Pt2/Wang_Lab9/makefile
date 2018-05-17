lab5: main.o BinarySearchTree.o
	g++ -std=c++11 -g -Wall main.o BinarySearchTree.o -o lab9
main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

BinarySearchTree.o: BinarySearchTree.h BinarySearchTree.cpp
	g++ -std=c++11 -g -Wall -c BinarySearchTree.cpp
	
clean: 
	rm *.o lab5
	echo clean done 
