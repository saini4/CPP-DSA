/*
This program performs Breadth-First Search (BFS) on a graph represented by a 7x7 adjacency matrix.
BFS starts at node 0 and explores all its neighbors before moving to the next level of neighbors.

Graph:
      0---1---2
      |   |  /|\
      |   | / | \
      3---4---5---6

Time Complexity: O(V + E), where V is the number of vertices, E is the number of edges.
Space Complexity: O(V) for the queue and visited array, O(V^2) for the adjacency matrix.
*/

#include <iostream>
using namespace std;

class Queue
{
public:
    int *arr;
    int front;
    int rear;
    int size;

    Queue(int size)
    {
        this->size = size;
        arr = new int[size];
        this->front = -1;
        this->rear = -1;
    }

    void enqueue(int data)
    {
        if ((rear + 1) % size == front)
        {
            cout << "Queue is full" << endl;
            return;
        }
        if (front == -1 && rear == -1)
        {
            front = rear = 0;
            arr[rear] = data;
        }
        else
        {
            rear = (rear + 1) % size;
            arr[rear] = data;
        }
    }

    int dequeue()
    {
        if (front == -1)
        {
            cout << "Queue is empty" << endl;
            return 0;
        }
        int value = arr[front];
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % size;
        }
        return value;
    }

    bool isEmpty()
    {
        return front == -1;
    }
};

int main()
{
    int adjM[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}};

    Queue V(7);
    Queue Q(7);

    for (int i = 0; i < 7; i++)
    {
        V.arr[i] = 0;
    }

    int startNode = 0;
    cout << startNode << endl;

    V.arr[startNode] = 1;
    Q.enqueue(startNode);

    while (!Q.isEmpty())
    {
        int node = Q.dequeue();

        for (int j = 0; j < 7; j++)
        {
            if (adjM[node][j] == 1 && V.arr[j] == 0)
            {
                cout << j << endl;
                V.arr[j] = 1;
                Q.enqueue(j);
            }
        }
    }

    return 0;
}
