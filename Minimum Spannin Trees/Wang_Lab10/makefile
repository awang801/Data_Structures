lab10: main.o minSpanTree.o BinarySearchTree.o Node.o disjoint.o
	g++ -std=c++11 -g -Wall main.o minSpanTree.o BinarySearchTree.o Node.o disjoint.o -o lab10
main.o: main.cpp minSpanTree.h BinarySearchTree.h Node.h disjoint.h
	g++ -std=c++11 -g -Wall -c main.cpp
minSpanTree.o: minSpanTree.h minSpanTree.cpp
	g++ -std=c++11 -g -Wall -c minSpanTree.cpp
BinarySearchTree.o: BinarySearchTree.h BinarySearchTree.cpp
	g++ -std=c++11 -g -Wall -c BinarySearchTree.cpp
Node.o: Node.h Node.cpp
	g++ -std=c++11 -g -Wall -c Node.cpp
disjoint.o: disjoint.h disjoint.cpp
	g++ -std=c++11 -g -Wall -c disjoint.cpp
clean: 
	rm *.o lab10
	echo clean done
