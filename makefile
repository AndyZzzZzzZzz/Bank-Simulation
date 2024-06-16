# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall

# Target executable name
TARGET = BankSimApp

# Source files
SRCS = BankSimApp.cpp BinaryHeap.cpp PriorityQueue.cpp Queue.cpp Event.cpp EmptyDataCollectionException.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Header files
HEADERS = BinaryHeap.h PriorityQueue.h Queue.h Event.h EmptyDataCollectionException.h

# Default target
all: $(TARGET)

# Rule to build the target executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule to build object files
BankSimApp.o: BankSimApp.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c BankSimApp.cpp

BinaryHeap.o: BinaryHeap.cpp BinaryHeap.h
	$(CXX) $(CXXFLAGS) -c BinaryHeap.cpp

PriorityQueue.o: PriorityQueue.cpp PriorityQueue.h BinaryHeap.h EmptyDataCollectionException.h
	$(CXX) $(CXXFLAGS) -c PriorityQueue.cpp

Queue.o: Queue.cpp Queue.h EmptyDataCollectionException.h
	$(CXX) $(CXXFLAGS) -c Queue.cpp

Event.o: Event.cpp Event.h
	$(CXX) $(CXXFLAGS) -c Event.cpp

EmptyDataCollectionException.o: EmptyDataCollectionException.cpp EmptyDataCollectionException.h
	$(CXX) $(CXXFLAGS) -c EmptyDataCollectionException.cpp

# Clean up generated files
clean:	
	rm -f $(TARGET) *.o

# Phony targets
.PHONY: all clean
