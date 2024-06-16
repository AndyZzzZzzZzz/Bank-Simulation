#include <iostream>
#include "PriorityQueue.h"

using std::cout;
using std::endl;

int main() {
    cout << "Priority Queue Test Driver" << endl;

    PriorityQueue<int> pq;

    cout << "Testing isEmpty() on empty queue: ";
    cout << (pq.isEmpty() ? "PASS" : "FAIL") << endl;

    int numbers[] = {55, 22, 88, 3, 99, 10, 30};
    cout << "Enqueuing elements: ";
    for (int num : numbers) {
        cout << num << " ";
        pq.enqueue(num);
    }
    cout << endl;

    cout << "Testing isEmpty() on non-empty queue: ";
    cout << (!pq.isEmpty() ? "PASS" : "FAIL") << endl;

    cout << "Current top element (peek): " << pq.peek() << endl;

    cout << "Dequeuing all elements in priority order:" << endl;
    while (!pq.isEmpty()) {
        cout << "Top element: " << pq.peek() << ". Dequeuing..." << endl;
        pq.dequeue();
        if (!pq.isEmpty()) {
            cout << "Next top element: " << pq.peek() << endl;
        } else {
            cout << "Queue is now empty." << endl;
        }
    }

    cout << "Attempting to dequeue from an empty queue..." << endl;
    try {
        pq.dequeue();
        cout << "FAIL: Expected an EmptyDataCollectionException" << endl;
    } catch (const EmptyDataCollectionException& e) {
        cout << "PASS: Caught EmptyDataCollectionException as expected." << endl;
    }

    cout << "Attempting to peek at an empty queue..." << endl;
    try {
        pq.peek();
        cout << "FAIL: Expected an EmptyDataCollectionException" << endl;
    } catch (const EmptyDataCollectionException& e) {
        cout << "PASS: Caught EmptyDataCollectionException as expected." << endl;
    }

    return 0;
}

