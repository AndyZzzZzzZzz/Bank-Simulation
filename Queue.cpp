/* 
 * Queue.cpp
 *
 * Description: Link-based implementation of Queue as an ADT class, uses a singly-linked doubly
 *		headed linked-list.
 * Class Invariant: Queue maintained in FIFO order
 *
 * Author: Kunpeng (Andy) Zhang
 * Date: April 5, 2024
 */
 
#include "Queue.h"

template<typename ElementType>
// Description: Constructor
Queue<ElementType>::Queue(){
	//set head of the linked list to null
	head = nullptr;
	//set tail of the linked list to null
	tail = nullptr;
	//set size of the linked list to zero 
	size = 0;
	
}

//Description: Destructor
template<typename ElementType>
Queue<ElementType>::~Queue(){

	//If the linked list is not empty, call dequeue method 
	while(size != 0){
		dequeue();
	}
	//set head of the linked list to null
	head = nullptr;
	//set tail of the linked list to null
	tail = nullptr;
}


// Description: Returns true if this Queue is empty, otherwise false.
// Postcondition: This Queue is unchanged by this operation.
// Time Efficiency: O(1)
template<typename ElementType>
bool Queue<ElementType>::isEmpty() const{

	//return true if size of the linked list is zero, false if otherwise 
	return size == 0;
}

// Description: Inserts newElement at the "back" of this Queue 
//              (not necessarily the "back" of this Queue's data structure) 
//              and returns true if successful, otherwise false.
// Time Efficiency: O(1)
template<typename ElementType>
bool Queue<ElementType>::enqueue(ElementType & newElement){
	
	//Create a new node using the newElement
	Node* myNode = new Node(newElement);
	
	//If the linked list is empty, set both head and tail pointing to the node
	if(size == 0){
		head = tail = myNode;
		
		//Increment size
		size ++;
		//Return true for successful insertion 
		return true;
	}
	else{
		//If linked list is not empty, append the new node in the end 
		tail -> next = myNode;
		//Update the tail pointer 
		tail = myNode;
		//Increment size
		size ++;
		//Return true for successful insertion 
		return true;
	}
	//If insertion is not successful, return false
	return false;
	
}

// Description: Removes (but does not return) the element at the "front" of this Queue 
//              (not necessarily the "front" of this Queue's data structure).
// Precondition: This Queue is not empty.
// Exception: Throws EmptyDataCollectionException if this Queue is empty.   
// Time Efficiency: O(1)
template<typename ElementType>
void Queue<ElementType>::dequeue(){
	
	//If the linked list is empty, throw exception
	if(size == 0){
		throw EmptyDataCollectionException();
	}
	else{
		//If the linked list is not empty, set a temporary pointer to head
		Node* temp = head;
		//Increment head to skip the first node in queue
		head = head -> next;
		//Delete temp
		delete temp;
		//Decrement size accordingly
		size --;
	}
	//If the linked list is empty after dequeue, set the tail pointer to null
	if(head == nullptr){
		tail = nullptr;
	}
	

}

// Description: Returns (but does not remove) the element at the "front" of this Queue
//              (not necessarily the "front" of this Queue's data structure).
// Precondition: This Queue is not empty.
// Postcondition: This Queue is unchanged by this operation.
// Exception: Throws EmptyDataCollectionException if this Queue is empty.
// Time Efficiency: O(1)
template<typename ElementType>
ElementType & Queue<ElementType>::peek() const{
	//If the linked list is empty, throw exception 
	if(size == 0){
		throw EmptyDataCollectionException();
	}
	//Return the first node's data in linked list
	return head -> data;
	
}

