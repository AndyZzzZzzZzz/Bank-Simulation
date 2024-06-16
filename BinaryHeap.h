/* 
 * BinaryHeap.h
 *
 * Description: Template class for a minimum binary heap ADT class
 *		array implementation 
 * Class Invariant: Always follow the weakly ordered property of a minimum binary heap 
 *
 * Author: Kunpeng (Andy) Zhang
 * Date: April 5, 2024
 */
#ifndef BINARYHEAP_H
#define BINARYHEAP_H
 
 //Include exception file 
 #include "EmptyDataCollectionException.h"
 
 template <typename ElementType>
 class BinaryHeap{
 	
 	private:
 		//Pointer to dynamic allocated array 
 		ElementType* elements;
 		//Element Count to keep track of current size
 		unsigned int elementCount;
 		//Capacity to keep track of maximum size
 		unsigned int capacity;
 		
 		// Description: Expand the binary heap if elementCount reaches capacity
 		// Postcondition: New binary heap is double its original size
 		// Time efficiency: O(n)
 		void expandHeap();
 		
 		// Description: Recursively put the array back into a minimum Binary Heap.
 		// Postcondition: Minimum binary heap is weakly ordered
 		// Time efficiency: O(log2 n)
 		void reHeapUp(unsigned int index);
 		
 		// Description: Recursively put the array back into a minimum Binary Heap.
 		// Postcondition: Minimum binary heap is weakly ordered
 		// Time efficiency: O(log2 n)
 		void reHeapDown(unsigned int index);
 		
 	public:
 		//Constructor
 		BinaryHeap(unsigned int capacity);
 		
 		//Destructor
 		~BinaryHeap();
 		
		// Description: Returns the number of elements in the Binary Heap.
		// Postcondition: The Binary Heap is unchanged by this operation.
		// Time Efficiency: O(1)
		unsigned int getElementCount() const;

		// Description: Inserts newElement into the Binary Heap. 
		//              It returns true if successful, otherwise false.      
		// Time Efficiency: O(log2 n)
		bool insert(ElementType & newElement);

		// Description: Removes (but does not return) the necessary element.
		// Precondition: This Binary Heap is not empty.
		// Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
		// Time Efficiency: O(log2 n)
		void remove();

		// Description: Retrieves (but does not remove) the necessary element.
		// Precondition: This Binary Heap is not empty.
		// Postcondition: This Binary Heap is unchanged.
		// Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
		// Time Efficiency: O(1) 
		ElementType & retrieve() const;

 
 };
 #include "BinaryHeap.cpp"
 
#endif
