lab5: main.o Node.o BinarySearchTree.o
	g++ -std=c++11 -g -Wall main.o Node.o BinarySearchTree.o -o lab5
main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp
Node.o: Node.h Node.cpp
	g++ -std=c++11 -g -Wall -c Node.cpp
BinarySearchTree.o: BinarySearchTree.h BinarySearchTree.cpp
	g++ -std=c++11 -g -Wall -c BinarySearchTree.cpp
	
clean: 
	rm *.o lab5
	echo clean done 
