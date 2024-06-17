/* 
 * BinaryHeap.cpp
 *
 * Description: Template class for a minimum binary heap ADT class
 *		array implementation 
 * Class Invariant: Always follow the weakly ordered property of a minimum binary heap 
 *
 * Author: Kunpeng (Andy) Zhang
 * Date: April 5, 2024
 */

#include "BinaryHeap.h"


//Contructor to initialize array 
template<typename ElementType>
BinaryHeap<ElementType>::BinaryHeap(unsigned int capacity){
	
	//Set capacity to initial capacity
	this -> capacity = capacity;
	//Create a dynamic array with given capacity
	elements = new ElementType[capacity];
	//Set element count to zero
	elementCount = 0;
}

//Destructor
template<typename ElementType>
BinaryHeap<ElementType>::~BinaryHeap() {
	
	//Delete dynamically allocated array 
	delete[] elements;
	//Set the pointer to null
	elements = nullptr;
}


// Description: Returns the number of elements in the Binary Heap.
// Postcondition: The Binary Heap is unchanged by this operation.
// Time Efficiency: O(1)
template<typename ElementType>
unsigned int BinaryHeap<ElementType>::getElementCount() const {

	//return element count 
	return elementCount;
	
}

// Description: Inserts newElement into the Binary Heap. 
// 		It returns true if successful, otherwise false.      
// Time Efficiency: O(log2 n)
template<typename ElementType>
bool BinaryHeap<ElementType>::insert(ElementType& newElement) {

	//If elementCount reaches capacity, call expandHeap to increment array size
	if (elementCount == capacity) {
		expandHeap();
	}
	
	//Store new element to position element count
	elements[elementCount] = newElement;
	//Increment element count and assign it to index
	int index = elementCount ++;
	//Call reHeapUp on index to ensure the ordering of minimum binary heap
	reHeapUp(index);
	return true;
	
}

// Description: Retrieves (but does not remove) the necessary element.
// Precondition: This Binary Heap is not empty.
// Postcondition: This Binary Heap is unchanged.
// Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
// Time Efficiency: O(1) 
template<typename ElementType>
ElementType& BinaryHeap<ElementType>::retrieve() const {
	
    //If binary heap is empty, throw exception 
    if (elementCount == 0){
    	throw EmptyDataCollectionException();
    }
    
    //Return the first element stored in the array 
    return elements[0];
    
}

// Description: Removes (but does not return) the necessary element.
// Precondition: This Binary Heap is not empty.
// Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
// Time Efficiency: O(log2 n)
template <class ElementType>
void BinaryHeap<ElementType>::remove() {  
   
   //If binary heap is empty, throw exception 
   if(elementCount == 0) 
      throw EmptyDataCollectionException();
   //Replace the first element in the array with the last element 
   elements[0] = elements[elementCount - 1];
   //Decrement element count 
   elementCount--;
   
   // No need to call reheapDown() if we have just removed is the only element
   if ( elementCount > 0 ) 
      //If there are more element in the array, call reHeapDown 
      reHeapDown(0);
   
   return;
}

// Utility method
// Description: Recursively put the array back into a minimum Binary Heap.
// Postcondition: Minimum binary heap is weakly ordered
// Time efficiency: O(log2 n)
template<typename ElementType>
void BinaryHeap<ElementType>::reHeapUp(unsigned int indexOfChild) {
	
	//Calculate index of parent 
	int indexOfParent = (indexOfChild - 1)/2;
	
	//If the children is not root and its parent has a value larger than it, iterate 
	//through the heap and making it back to minimum binary heap 
	while (indexOfChild > 0 && !(elements[indexOfParent] <= elements[indexOfChild])) {
		
		// Swap parent with children
		ElementType temp = elements[indexOfChild];
		elements[indexOfChild] = elements[indexOfParent];
		elements[indexOfParent] = temp;
		
		//Update index of children to parent 
		indexOfChild = indexOfParent;
		//Calculate the index of new parent 
		indexOfParent = (indexOfChild - 1)/2;
		
	}
    
    	return;
}

// Description: Recursively put the array back into a minimum Binary Heap.
// Postcondition: Minimum binary heap is weakly ordered
// Time efficiency: O(log2 n)
template <class ElementType>
void BinaryHeap<ElementType>::reHeapDown(unsigned int indexOfRoot) {
   
   //Store index of the root 
   unsigned int indexOfMinChild = indexOfRoot;
   
   // Find indices of children.
   unsigned int indexOfLeftChild = 2 * indexOfRoot + 1;
   unsigned int indexOfRightChild = 2 * indexOfRoot + 2;

   // Base case: elements[indexOfRoot] is a leaf as it has no children
   if (indexOfLeftChild > elementCount - 1) return;

   // If we need to swap, select the smallest child
   // If (elements[indexOfRoot] > elements[indexOfLeftChild])
   if ( ! (elements[indexOfRoot] <= elements[indexOfLeftChild]) )
      indexOfMinChild = indexOfLeftChild;

   // Check if there is a right child, is it the smallest?
   if (indexOfRightChild < elementCount) {
      // if (elements[indexOfMinChild] > elements[indexOfRightChild])
      if ( ! (elements[indexOfMinChild] <= elements[indexOfRightChild]) )
         indexOfMinChild = indexOfRightChild;
   }

   // Swap parent with smallest of children.
   if (indexOfMinChild != indexOfRoot) {
      
      ElementType temp = elements[indexOfRoot];
      elements[indexOfRoot] = elements[indexOfMinChild];
      elements[indexOfMinChild] = temp;
      
      // Recursively put the array back into a heap
      reHeapDown(indexOfMinChild);
   }
   return;
} 

// Description: Expand the binary heap if elementCount reaches capacity
// Postcondition: New binary heap is double its original size
// Time efficiency: O(n)
template<typename ElementType>
void BinaryHeap<ElementType>::expandHeap() {
    //double the current capacity
    capacity *= 2;
    //Create a new dynamic array with updated capacity 
    ElementType* newHeap = new ElementType[capacity];
    //Loop through the original heap and copy every element to the new array
    for(unsigned int i = 0; i < elementCount; i ++){
		newHeap[i] = elements[i];
	
	}
    //Delete original array
    delete[] elements;
    //Assign pointer to the new array 
    elements = newHeap;
    
    return;
}


