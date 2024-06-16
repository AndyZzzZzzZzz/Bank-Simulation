all: HeapTest

HeapTest: BinaryHeapTest.o BinaryHeap.h Event.o EmptyDataCollectionException.o
	g++ -o HeapTest -Wall BinaryHeapTest.o Event.o EmptyDataCollectionException.o
	
BinaryHeapTest.o: BinaryHeapTest.cpp 
	g++ -c -Wall BinaryHeapTest.cpp
	
Event.o: Event.cpp Event.h
	g++ -c -Wall Event.cpp

EmptyDataCollectionException.o: EmptyDataCollectionException.cpp EmptyDataCollectionException.h 
	g++ -c -Wall EmptyDataCollectionException.cpp

clean:	
	rm -f HeapTest *.o

