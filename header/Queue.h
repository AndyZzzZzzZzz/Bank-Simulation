/* 
 * Queue.h 
 *
 * Description: Link-based implementation of Queue as an ADT class, uses a singly-linked doubly
 *		headed linked-list.
 * Class Invariant: Queue maintained in FIFO order
 *
 * Author: Kunpeng (Andy) Zhang
 * Date: April 5, 2024
 */
 
#ifndef QUEUE_H
#define QUEUE_H

#include "EmptyDataCollectionException.h"

template <typename ElementType>
class Queue {

    private:
    	
    	//Create a private data type Node 
    	struct Node{
    		//Hold element type data
    		ElementType data;
    		//Set the next pointer to null
    		Node * next = nullptr;
    		
    		//Constructor 
    		Node(ElementType& newData, Node* nextNode = nullptr)
            : data(newData), next(nextNode) {}
    	};
    	
    	//integer variable storing size of linked list 
    	int size;
    	//pointer to the head of linked list
    	Node* head;
    	//pointer to the tail of linked list 
    	Node* tail;
    public:

        // Description: Constructor
        Queue();
	
	//Description: Destructor
	~Queue();
	 
	// Description: Returns true if this Queue is empty, otherwise false.
	// Postcondition: This Queue is unchanged by this operation.
	// Time Efficiency: O(1)
	bool isEmpty() const;

	// Description: Inserts newElement at the "back" of this Queue 
	//              (not necessarily the "back" of this Queue's data structure) 
	//              and returns true if successful, otherwise false.
	// Time Efficiency: O(1)
	bool enqueue(ElementType & newElement);

	// Description: Removes (but does not return) the element at the "front" of this Queue 
	//              (not necessarily the "front" of this Queue's data structure).
	// Precondition: This Queue is not empty.
	// Exception: Throws EmptyDataCollectionException if this Queue is empty.   
	// Time Efficiency: O(1)
	void dequeue(); 

	// Description: Returns (but does not remove) the element at the "front" of this Queue
	//              (not necessarily the "front" of this Queue's data structure).
	// Precondition: This Queue is not empty.
	// Postcondition: This Queue is unchanged by this operation.
	// Exception: Throws EmptyDataCollectionException if this Queue is empty.
	// Time Efficiency: O(1)
	ElementType & peek() const;
	
        
};
#include "Queue.cpp"

#endif


