lab6: main.o MinHeap.o
	g++ -std=c++11 -g -Wall main.o -o lab6
main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp
MinHeap.o: MinHeap.h MinHeap.cpp
	g++ -std=c++11 -g -Wall -c MinHeap.cpp
	
clean:
	rm *.o lab6
	echo clean done
