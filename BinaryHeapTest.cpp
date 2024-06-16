/* 
 * BinaryHeap.h
 *
 * Description: Template class for a binary heap ADT class
 *		array implementation 
 * Class Invariant: Always follow the weakly ordered property of a binary heap 
 *
 * Author: Kunpeng (Andy) Zhang
 * Date: April 5, 2024
 */

#include <iostream>
#include "BinaryHeap.h"

using std::cout;
using std::endl;

int main(){
	
	BinaryHeap<int>* myHeap = new BinaryHeap<int>(3);
	
	int a = 6;
	int b = 8;
	int c = 11;
	int d = 4;
	int e = 7;
	int f = 1;
	
	try{
		cout << "remove from element heap" << endl;
		myHeap -> remove();
	
	}catch(EmptyDataCollectionException & e){
		
		cout << "pass" << endl;
	}
	
	try{
		cout << "retrieve from element heap" << endl;
		myHeap -> retrieve();
	
	}catch(EmptyDataCollectionException & e){
		
		cout << "pass" << endl;
	}
	
	cout << "Insert first element" << endl;
	myHeap -> insert(a);
	cout << myHeap -> getElementCount() << endl;
	//myHeap -> print();
	
	cout << " " << endl; 
	
	cout << "Insert second element" << endl;
	myHeap -> insert(b);
	cout << myHeap -> getElementCount() << endl;
	//myHeap -> print();
	
	cout << " " << endl; 
	
	cout << "Insert third element" << endl;
	myHeap -> insert(c);
	cout << myHeap -> getElementCount() << endl;
	//myHeap -> print();
	
	cout << " " << endl; 
	
	cout << "Insert fourth element" << endl;
	myHeap -> insert(d);
	cout << myHeap -> getElementCount() << endl;
	//myHeap -> print();
	
	cout << " " << endl; 
	
	cout << "Insert fifth element" << endl;
	myHeap -> insert(e);
	cout << myHeap -> getElementCount() << endl;
	//myHeap -> print();
	
	cout << " " << endl; 
	
	cout << "Insert sixth element" << endl;
	myHeap -> insert(f);
	cout << myHeap -> getElementCount() << endl;
	//myHeap -> print();
	
	cout << " " << endl;
	
	/*
	cout << "test copy constructor" << endl;
	BinaryHeap<int>* newHeap = new BinaryHeap<int>(*myHeap);
	//newHeap -> print();
	
	cout << "remove element in original heap" << endl;
	myHeap -> remove();
	
	cout << "Display new heap" << endl;
	//newHeap -> print();
	
	
	cout << "show element Count" <<endl;
	cout << "myHeap:" << myHeap -> getElementCount() <<endl;
	cout << "newHeap:" << newHeap -> getElementCount() <<endl;
	
	int size = newHeap -> getElementCount();
	for(int i = 0; i < size; i ++){
		cout << "remove " << i + 1 << " element" << endl;
		newHeap -> remove();
		//newHeap -> print();
	}
	
	cout << "testing retrieve" << endl;
	int k = myHeap -> retrieve();
	cout << k << endl;
	
	
	delete newHeap;
	newHeap =  nullptr;
	*/
	
	delete myHeap;
	myHeap = nullptr;
	
	return 0;
}
