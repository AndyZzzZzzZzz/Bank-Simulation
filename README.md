# Bank Simulation App

This project is a Bank Simulation Application that determines the average customer wait time and the decrease in average customer wait time when a new teller is added. It is implemented in C++ and uses a priority queue to manage events.

## Description

The Bank Simulation App processes a series of arrival and departure events to simulate the operation of a bank with one or more tellers. It calculates the average wait time for customers and demonstrates the impact of adding an additional teller on reducing this wait time.

### Key Features

- Processes arrival and departure events
- Calculates average customer wait time
- Demonstrates the effect of adding a new teller on wait time
- Implements a priority queue using a binary heap
- Includes exception handling for empty data collections

## Project Structure

The project is organized into the following directories:

- **src**: Contains the source code files.
- **include**: Contains the header files.
- **bin**: Contains the compiled binaries and executables.
- **obj**: Contains the object files.

### Files

- **src/BankSimApp.cpp**: The main application file that runs the simulation.
- **src/BinaryHeap.cpp**: Implementation of a binary heap used as the underlying data structure for the priority queue.
- **src/PriorityQueue.cpp**: Implementation of the priority queue ADT class.
- **src/Queue.cpp**: Implementation of a link-based queue used to manage the bank line.
- **src/Event.cpp**: Models arrival and departure events.
- **src/EmptyDataCollectionException.cpp**: Defines the exception that is thrown when data collection is empty.

- **include/BinaryHeap.h**: Header file defining the BinaryHeap class.
- **include/PriorityQueue.h**: Header file defining the PriorityQueue class.
- **include/Queue.h**: Header file defining the Queue class.
- **include/Event.h**: Header file defining the Event class.
- **include/EmptyDataCollectionException.h**: Header file defining the EmptyDataCollectionException class.

## Compilation Instructions (Without Makefile)

To compile and run the Bank Simulation App manually without using a Makefile, follow these steps:

1. **Open a terminal** and navigate to the directory where your source files are located.

2. **Compile the source files into object files** using the `g++` compiler. Ensure you include the `-std=c++11` flag for C++11 support and `-Wall` for displaying all warnings. Run the following commands:

    ```sh
    g++ -c -std=c++11 -Wall BankSimApp.cpp
    g++ -c -std=c++11 -Wall Queue.cpp
    g++ -c -std=c++11 -Wall Event.cpp
    g++ -c -std=c++11 -Wall EmptyDataCollectionException.cpp
    g++ -c -std=c++11 -Wall PriorityQueue.cpp
    g++ -c -std=c++11 -Wall BinaryHeap.cpp
    ```

3. **Link the object files** to create the executable. Run the following command:

    ```sh
    g++ -o BankSimApp BankSimApp.o Queue.o Event.o EmptyDataCollectionException.o PriorityQueue.o BinaryHeap.o
    ```

4. **Run the executable** with an input file. Use the following command, where `input.txt` is the file containing your input data:

    ```sh
    ./BankSimApp < input.txt
    ```

