lab12: Node.o BinarySearchTree.o dijkstra.o main.o
	g++ -g -std=c++11 Node.o BinarySearchTree.o dijkstra.o main.o -o lab12

main.o: dijkstra.h Node.h BinarySearchTree.h main.cpp
	g++ -g -std=c++11 -c main.cpp
	
dijkstra.o: dijkstra.h dijkstra.cpp
	g++ -g -std=c++11 -c dijkstra.cpp

BinarySearchTree.o: Node.h BinarySearchTree.h BinarySearchTree.cpp
	g++ -g -std=c++11 -c BinarySearchTree.cpp

Node.o: Node.h Node.cpp
	g++ -g -std=c++11 -c Node.cpp

clean:
	rm *.o lab12
