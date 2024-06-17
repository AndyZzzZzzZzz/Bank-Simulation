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
