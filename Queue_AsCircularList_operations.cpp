/*
This program implements a circular queue using a linked list in C++.
The queue supports the following operations:

1. Enqueue: Adds an element to the rear of the queue.
   Time Complexity: O(1)

2. Dequeue: Removes an element from the front of the queue.
   Time Complexity: O(1)

3. Print Queue: Displays all the elements in the queue.
   Time Complexity: O(n), where n is the number of elements in the queue.

Space Complexity: O(n), where n is the number of elements stored in the queue.
*/
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

Node *front = nullptr;
Node *rear = nullptr;

void printQueue()
{
    if (front == nullptr)
    {
        cout << "Queue is empty" << endl;
        return;
    }

    Node *temp = front;
    while (temp != rear)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << rear->data << endl; // Print the last node
}

void enqueue(int data)
{
    Node *newNode = new Node(data);
    if (rear == nullptr)
    {
        front = newNode;
        rear = newNode;
        newNode->next = front;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }
}

void dequeue()
{
    if (front == nullptr)
    {
        cout << "Queue is empty" << endl;
        return;
    }

    Node *temp = front;
    if (front == rear)
    {
        front = nullptr;
        rear = nullptr;
    }
    else
    {
        front = front->next;
        rear->next = front;
    }
    delete temp;
}

int main()
{
    enqueue(5);
    enqueue(10);
    enqueue(15);
    enqueue(25);
    enqueue(100);
    enqueue(165);
    printQueue();

    dequeue();
    dequeue();
    printQueue();

    return 0;
}