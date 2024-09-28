/*
    Program Description:
    This program implements a circular queue using an array in C++. 
    The queue supports the following operations:
    1. enqueue(int data) - Adds an element to the rear of the queue.
    2. dequeue() - Removes an element from the front of the queue.
    3. isEmpty() - Checks if the queue is empty.
    4. isFull() - Checks if the queue is full.

    Time Complexities:
    - enqueue(int data): O(1) - Constant time insertion at the rear of the queue.
    - dequeue(): O(1) - Constant time removal from the front of the queue.
    - isEmpty(): O(1) - Constant time check for emptiness.
    - isFull(): O(1) - Constant time check for fullness.
*/

#include <iostream>
using namespace std;

class Queue{
    int front;
    int rear;
    int size;
    int arr[6];
public: 
    Queue(){
        front = 0;
        rear = 0;
        size = 6;
    }
    
    bool isEmpty() {
        return front == rear;
    }

    bool isFull() {
        return (rear + 1) % size == front;
    }

    void enqueue(int data){
        if(isFull()){
            cout<<"Queue is full"<<endl;
            return;
        } else {
            arr[rear] = data;
            rear = (rear + 1) % size;
            cout << "Enqueued: " << data << endl;
        }
    }

    void dequeue(){
        if(isEmpty()){
            cout<<"Queue is already empty"<<endl;
            return;
        } else {
            cout << "Dequeued: " << arr[front] << endl;
            arr[front] = 0;
            front = (front + 1) % size;
        }
    }
};

int main(){
    Queue q;
    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);
    q.enqueue(25);
    q.enqueue(100);
    q.enqueue(165);
    q.dequeue();
    q.dequeue();

    return 0;
}
