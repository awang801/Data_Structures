lab7: main.o MinHeap.o
	g++ -std=c++11 -g -Wall main.o MinHeap.o -o lab7
main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp
MinHeap.o: MinHeap.h MinHeap.cpp
	g++ -std=c++11 -g -Wall -c MinHeap.cpp

clean:
	rm *.o lab7
	echo clean done
