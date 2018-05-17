lab4: main.o
	g++ -g -std=c++11 -Wall main.o -o lab4

main.o: main.cpp DoubleLinkedList.h DoubleLinkedList.hpp OpenHash.h OpenHash.hpp Node.h Node.hpp timer.h timer.hpp
	g++ -g -std=c++11 -Wall -c main.cpp
clean:
	rm *.o lab3
	echo clean done
