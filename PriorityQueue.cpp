/* 
 * PriorityQueue.cpp
 *
 * Description: Implementation of priority queue ADT class, using binary heap as its underlying 
 *		data structure
 * Class Invariant: Maintain the property of a priority queue
 *
 * Author: Kunpeng (Andy) Zhang
 * Date:  April 5, 2024
 */


#include "PriorityQueue.h"

//Constructor
//Declare the initial capacity of priority queue to 100 
template <typename ElementType>
PriorityQueue<ElementType>::PriorityQueue() : minheap(2){
	
}

//Destructor
template <typename ElementType>
PriorityQueue<ElementType>::~PriorityQueue(){
	
}

// Description: Returns true if this Priority Queue is empty, otherwise false.
// Postcondition: This Priority Queue is unchanged by this operation.
// Time Efficiency: O(1)
template <typename ElementType>
bool PriorityQueue<ElementType>::isEmpty() const{
	
	//Retuen true if getElementCount return's zero, false otherwise 
	return minheap.getElementCount() == 0;
}

// Description: Inserts newElement in this Priority Queue and 
//              returns true if successful, otherwise false.
// Time Efficiency: O(log2 n)
template <typename ElementType>
bool PriorityQueue<ElementType>::enqueue(ElementType & newElement){
	
	//Insert new element into minimum binary heap and return the result 
	return minheap.insert(newElement);

}

// Description: Removes (but does not return) the element with the next
//              "highest" priority value from the Priority Queue.
// Precondition: This Priority Queue is not empty.
// Exception: Throws EmptyDataCollectionException if Priority Queue is empty.
// Time Efficiency: O(log2 n)
template <typename ElementType>
void PriorityQueue<ElementType>::dequeue(){

	//If the minimum binary heap is empty, throw exception 
	if(isEmpty() == true){
		throw EmptyDataCollectionException();
	}else {
		//If the minimum binary heap is not empty, call remove method 
		try{
			minheap.remove();
		}catch(EmptyDataCollectionException & error){
		
		}
	}
	
}

// Description: Returns (but does not remove) the element with the next 
//              "highest" priority value from the Priority Queue.
// Precondition: This Priority Queue is not empty.
// Postcondition: This Priority Queue is unchanged by this operation.
// Exception: Throws EmptyDataCollectionException if this Priority Queue is empty.
// Time Efficiency: O(1)
template <typename ElementType>
ElementType & PriorityQueue<ElementType>::peek() const{
	
	//If the minimum binary heap is empty, throw exception 
	if(isEmpty() == true){
		throw EmptyDataCollectionException();
	}
	//If the minimum binary hepa is not empty, call retrieve method and return 
	//the result
	return minheap.retrieve();

		
	} 



