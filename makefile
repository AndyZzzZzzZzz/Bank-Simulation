all: BankSim 

BankSim: BankSimApp.o EmptyDataCollectionException.o Event.o 
	g++ -Wall -o BankSim BankSimApp.o EmptyDataCollectionException.o Event.o

BankSimApp.o: BankSimApp.cpp Queue.cpp Queue.h BinaryHeap.h Event.h PriorityQueue.h
	g++ -std=c++11 -Wall -c BankSimApp.cpp

Event.o: Event.cpp Event.h
	g++ -std=c++11 -Wall -c Event.cpp

EmptyDataCollectionException.o: EmptyDataCollectionException.cpp EmptyDataCollectionException.h
	g++ -std=c++11 -Wall -c EmptyDataCollectionException.cpp

clean: 
	rm -f BankSim *.o
