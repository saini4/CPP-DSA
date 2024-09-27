/*
 * Program: Queue Implementation Using Linked List
 * Description: This program implements a simple queue using a linked list.
 * It supports basic operations: enqueue (adding elements), dequeue (removing elements),
 * and printing the current state of the queue.
 *
 * Time Complexity:
 * - Enqueue: O(1)
 * - Dequeue: O(1)
 * - Print Queue: O(n), where n is the number of elements in the queue
 *
 * Space Complexity:
 * - O(n), where n is the number of elements in the queue (due to storage in nodes)
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
    Node *temp = front;
    if (front == nullptr)
    {
        cout << "Queue is empty" << endl;
        return;
    }
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void enqueue(int data)
{
    Node *newNode = new Node(data);
    if (rear == nullptr)
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
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
    front = front->next;
    if (front == nullptr)
    {
        rear = nullptr;
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
