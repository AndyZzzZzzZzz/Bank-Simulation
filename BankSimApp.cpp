/*
 * BankSimApp.cpp
 * 
 * Description: Bank Simulation App that takes determines the average customer wait time and        
 *		decrease in average customer wait time when new teller is added.
 *              
 *
 * Author: Kunpeng (Andy) Zhang
 * Last Modification Date: April 4th, 2024
 */
 
 //include iostream for input output 
 #include <iostream>
 //include Event.h file
 #include "Event.h"
 //include exception file 
 #include "EmptyDataCollectionException.h"
 //Include priority queue file
 #include "PriorityQueue.h"
 //Include queue file 
 #include "Queue.h"

 using namespace std;
 
//Helper method that process the arrival event 
void processArrival(Event& newEvent, PriorityQueue<Event>& eventPriorityQueue, Queue<Event>& bankLine, int& currentTime, bool& tellerAvailable){
	
	try{
		//Dequeue the first element in event priority queue 
		eventPriorityQueue.dequeue();
		
		}catch(EmptyDataCollectionException & error){
		
	} 
	
	//Set new event to current customer 
	Event customer = newEvent;
	
	//If the bank line is empty and teller is available 
	if(bankLine.isEmpty() && tellerAvailable){
		
		//Set departure time to current time plus customer's process time 
		int departureTime = currentTime + customer.getLength();
		
		//Create a new departure event with the above departure time 
		Event newDepartureEvent('D', departureTime);
		

		//Add the departure event to event priority queue 
		eventPriorityQueue.enqueue(newDepartureEvent);
		
		//Mark teller as unavailable 
		tellerAvailable = false;
	}else{
		//If bank line is not empty, enqueue the next customer 
		bankLine.enqueue(customer);
	
	}
	
}

//Helper method that process the departure event 
void processDeparture(Event& newEvent, PriorityQueue<Event>& eventPriorityQueue, Queue<Event>& bankLine, int& currentTime, bool& tellerAvailable, int& cumulativeWaitTime){
	
	try{
		//Dequeue the first element in event priority queue 
		eventPriorityQueue.dequeue();
		
		}catch(EmptyDataCollectionException & error){
		
	} 
	
	//If bank line is empty
	if(!bankLine.isEmpty()){
	
		Event customer;
		
		try{
			//Extract the first event is bank line as the next customer 
			customer = bankLine.peek();
		
		}catch(EmptyDataCollectionException & error){
		
		} 

		try{
			//Dequeue bank line 
			bankLine.dequeue();
		
		}catch(EmptyDataCollectionException & error){
		
		} 
		
		//Calculate wait time using current time minus the customer's arrival time 
		int waitTime = currentTime - customer.getTime();
		//add the wait time to cumulative wait time
		cumulativeWaitTime += waitTime;
		
		//Caculate departure time as current time plus customer's process time 
		int departureTime = currentTime + customer.getLength();
		
		//Create a new departure event using the above departure time 
		Event newDepartureEvent('D', departureTime);
		
		//Add departure even to the event priority queue
		eventPriorityQueue.enqueue(newDepartureEvent);
		
	}else{
		//If bank line is empty, mark teller as available 
		tellerAvailable = true;
	}


}

int main(){

	cout << "Simulation Begins" << endl;

	//Create a bank line using queue
	Queue<Event> bankLine; 
	//Create an event queue using priority queue 
	PriorityQueue<Event> eventPriorityQueue;
	
	//boolean variable to check whether teller is available 
	bool tellerAvailable = true;
	//Integer variable to keep track current time
	int currentTime;
	//Integer variable for arrival time
	int arriveTime;
	//Integer variable for process time
	int processTime;
	//Integer variable for total customer count 
	int customerCount = 0;
	//Integer variable that keep track of cumulative wait time 
	int cumulativeWaitTime = 0;
	
	//Create and add arrival events to event queue
	while(cin >> arriveTime >> processTime){
		//Create event as type arrival with corresponding arrival time and process time
		Event newArrivalEvent('A', arriveTime, processTime);
		//Add event to priority queue 
		eventPriorityQueue.enqueue(newArrivalEvent);
		//Increment customer count 
		customerCount ++;
	}
	
	//Iterate through event priority queue until its empty 
	while(! eventPriorityQueue.isEmpty()){
		
		Event newEvent;
		
		try{
			//Extract the top event stored in priority queue
			newEvent = eventPriorityQueue.peek();
		
		}catch(EmptyDataCollectionException & error){
		
		} 
		
		//Set the current time to even's arrival time 
		currentTime = newEvent.getTime();
		//If the top event is an arrival event
		if(newEvent.isArrival()){
			
			if(newEvent.getTime() < 10){
				cout << "Processing an arrival event at time:     " << newEvent.getTime() << endl;
			}else{
				cout << "Processing an arrival event at time:    " << newEvent.getTime() << endl;
			}
			
			//process the arrival event 
			processArrival(newEvent, eventPriorityQueue, bankLine, currentTime, tellerAvailable);
		}else{
			if(newEvent.getTime() < 10){
			
				cout << "Processing a departure event at time:    " << newEvent.getTime() << endl;
				
			}else{
				cout << "Processing a departure event at time:   " << newEvent.getTime() << endl;
			}
			 
			//If the top event is a departure event, process the departure event
			processDeparture(newEvent, eventPriorityQueue, bankLine, currentTime, tellerAvailable, cumulativeWaitTime);
		}
	
	}
	//Calculate the average wait time 
	float averageWaitTime = static_cast<float>(cumulativeWaitTime)/customerCount;
	
	//Print out the final statistics 
	cout << "Simulation Ends" << endl;
	cout << "" << endl;
	cout << "Final Statistics:" << endl;
	cout << "" << endl;
	cout << "	Total number of people processed: " << customerCount << endl;
	cout << "	Average amount of time spent waiting: " << averageWaitTime << endl;

	return 0;
}
