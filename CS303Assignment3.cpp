// Name: Tyler Ross
// Date: 11/12/2024
// CS303 Assignment 3
#include "Queue.h"
#include "linear_search.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Create a queue and add 10 integer values
    Queue<int> q;
    for (int i = 1; i <= 10; i++) {
        q.push(i);  // Insert integers from 1 to 10 into the queue
    }

    // Display the elements in the queue after insertion
    cout << "Queue elements after pushing 10 values:" << endl;
    q.display();

    // Test various queue operations
    cout << "\nTesting Queue functions:" << endl;

    // Display the front element of the queue
    cout << "Front element: " << q.frontElement() << endl;
    // Display the current size of the queue
    cout << "Queue size: " << q.size() << endl;
    // Check if the queue is empty
    cout << "Is the queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;

    // Pop one element from the queue and display the new size
    q.pop();
    cout << "After one pop, queue size: " << q.size() << endl;

    // Display the front element of the queue after popping
    cout << "Front element after pop: " << q.frontElement() << endl;

    // Move the front element to the rear of the queue
    cout << "\nQueue after moving the front element to the rear:" << endl;
    q.move_to_rear();
    q.display();

    // Sort the queue using insertion sort and display the result
    cout << "\nSorting the queue using insertion sort:" << endl;
    q.insertion_sort();
    q.display();

    // Create a vector of integers and populate it
    vector<int> vec = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    // Display the vector before performing the search
    cout << "\nVector before linear search:" << endl;
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;

    // Perform a linear search for the number 5 in the vector
    int target = 5;
    int position = linear_search(vec, target);

    // Display the result of the search
    if (position != -1) {
        cout << "Last occurrence of element " << target << " found at position " << position << "." << endl;
    }
    else {
        cout << "Element " << target << " not found in the vector." << endl;
    }
    return 0;
}
