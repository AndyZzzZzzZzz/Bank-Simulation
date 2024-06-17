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


### Files

- **BankSimApp.cpp**: The main application file that runs the simulation.
- **BinaryHeap.cpp**: Implementation of a binary heap used as the underlying data structure for the priority queue.
- **PriorityQueue.cpp**: Implementation of the priority queue ADT class.
- **Queue.cpp**: Implementation of a link-based queue used to manage the bank line.
- **Event.cpp**: Models arrival and departure events.
- **EmptyDataCollectionException.cpp**: Defines the exception that is thrown when data collection is empty.

- **BinaryHeap.h**: Header file defining the BinaryHeap class.
- **PriorityQueue.h**: Header file defining the PriorityQueue class.
- **Queue.h**: Header file defining the Queue class.
- **Event.h**: Header file defining the Event class.
- **EmptyDataCollectionException.h**: Header file defining the EmptyDataCollectionException class.

## Compilation Instructions (Using Makefile)

To compile and run the Bank Simulation App using the provided Makefile, follow these steps:

1. **Open a terminal** and navigate to the directory where your source files and Makefile are located.

2. **Run the `make` command** to compile the project. This will use the Makefile to compile the source files and link them into an executable.

    ```sh
    make
    ```

3. **Run the executable** with an input file. Use the following command, where `input.txt` is the file containing your input data:

    ```sh
    ./BankSim < input.txt
    ```

### Example

Assuming your input file `input.txt` contains the following data:

```plaintext
26 5
1  5
28 5
2  5
20 5
4  5
22 5
88 3
24 5
30 5

```
The output should be 

```plaintext
Simulation Begins
Processing an arrival event at time:     1
Processing an arrival event at time:     2
Processing an arrival event at time:     4
Processing a departure event at time:    6
Processing a departure event at time:   11
Processing a departure event at time:   16
Processing an arrival event at time:    20
Processing an arrival event at time:    22
Processing an arrival event at time:    24
Processing a departure event at time:   25
Processing an arrival event at time:    26
Processing an arrival event at time:    28
Processing an arrival event at time:    30
Processing a departure event at time:   30
Processing a departure event at time:   35
Processing a departure event at time:   40
Processing a departure event at time:   45
Processing a departure event at time:   50
Processing an arrival event at time:    88
Processing a departure event at time:   91
Simulation Ends

Final Statistics:

	Total number of people processed: 10
	Average amount of time spent waiting: 5.6
```
