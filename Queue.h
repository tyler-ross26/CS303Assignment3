#pragma once

#include <iostream>
#include <string>

using namespace std;

// Node structure to represent each element in the queue
template <typename T>
struct Node {
    T data;
    Node* next;

    Node(T value) : data(value), next(nullptr) {}
};

// Queue class definition using linked list
template <typename T>
class Queue {
private:
    Node<T>* front;  // Pointer to the front element of the queue
    Node<T>* rear;   // Pointer to the rear element of the queue
    int queueSize;   // Variable to keep track of the current size of the queue

public:
    Queue();          // Constructor to initialize the queue
    ~Queue();         // Destructor to clean up the queue when done
    void push(T value);  // Add a value to the queue
    void pop();          // Remove the front value from the queue
    T frontElement();    // Get the front element without removing it
    int size();          // Get the current size of the queue
    bool isEmpty();      // Check if the queue is empty
    void move_to_rear(); // Move the front element to the rear of the queue
    void display();      // Display all elements in the queue
    void insertion_sort(); // Sort the queue using insertion sort
};

// Constructor initializes the queue with front and rear as null and size as 0
template <typename T>
Queue<T>::Queue() : front(nullptr), rear(nullptr), queueSize(0) {}

// Destructor to delete all nodes when the queue is destroyed
template <typename T>
Queue<T>::~Queue() {
    while (front != nullptr) {
        Node<T>* temp = front;
        front = front->next;
        delete temp;
    }
}

// Push function to insert a new value at the rear of the queue
template <typename T>
void Queue<T>::push(T value) {
    Node<T>* newNode = new Node<T>(value);  // Create a new node with the given value

    if (rear == nullptr) {
        front = rear = newNode;  // If queue is empty, new node is both front and rear
    }
    else {
        rear->next = newNode;  // Add the new node to the rear
        rear = newNode;        // Update rear pointer
    }
    queueSize++;  // Increase the queue size
}

// Pop function to remove the front value from the queue
template <typename T>
void Queue<T>::pop() {
    if (front == nullptr) {
        return;  // If the queue is empty, there's nothing to pop
    }

    Node<T>* temp = front;
    front = front->next;  // Move the front pointer to the next element

    if (front == nullptr) {
        rear = nullptr;  // If the queue is now empty, set rear to null
    }

    delete temp;  // Free the memory of the removed node
    queueSize--;  // Decrease the queue size
}

// Function to return the front element of the queue
template <typename T>
T Queue<T>::frontElement() {
    if (front == nullptr) {
        return T();  // Return default value if queue is empty
    }
    return front->data;  // Return the data of the front node
}

// Function to return the current size of the queue
template <typename T>
int Queue<T>::size() {
    return queueSize;
}

// Function to check if the queue is empty
template <typename T>
bool Queue<T>::isEmpty() {
    return front == nullptr;  // If front is null, the queue is empty
}

// Function to move the front element to the rear of the queue
template <typename T>
void Queue<T>::move_to_rear() {
    if (front == nullptr || front == rear) {
        return;  // If the queue is empty or has only one element, do nothing
    }

    T frontValue = frontElement();  // Get the front element
    pop();                          // Remove the front element
    push(frontValue);                // Add it to the rear of the queue
}

// Function to display all elements in the queue
template <typename T>
void Queue<T>::display() {
    if (front == nullptr) {
        return;  // If the queue is empty, do nothing
    }

    Node<T>* temp = front;
    while (temp != nullptr) {
        cout << temp->data << " ";  // Print each element
        temp = temp->next;  // Move to the next node
    }
    cout << endl;
}

// Function to sort the queue using insertion sort
template <typename T>
void Queue<T>::insertion_sort() {
    if (front == nullptr || front->next == nullptr) {
        return;  // If the queue is empty or has only one element, no sorting needed
    }

    Node<T>* sorted = nullptr;  // This will hold the sorted part of the queue

    Node<T>* current = front;
    while (current != nullptr) {
        Node<T>* next = current->next;  // Save the next node
        current->next = nullptr;        // Break the link to avoid cycles

        if (sorted == nullptr || sorted->data >= current->data) {
            current->next = sorted;  // Insert at the front of the sorted part
            sorted = current;
        }
        else {
            Node<T>* temp = sorted;
            while (temp->next != nullptr && temp->next->data < current->data) {
                temp = temp->next;  // Find the correct position for current
            }
            current->next = temp->next;  // Insert current at the correct position
            temp->next = current;
        }

        current = next;  // Move to the next node in the original queue
    }

    front = sorted;  // Update front to the sorted list
    Node<T>* temp = front;
    while (temp != nullptr && temp->next != nullptr) {
        temp = temp->next;  // Find the last node in the sorted list
    }
    rear = temp;  // Set rear to the last node
}
