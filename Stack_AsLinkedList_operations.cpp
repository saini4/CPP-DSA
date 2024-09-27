/*
    Program Description:
    This C++ program implements a stack using a singly linked list with the following operations:
    1. pushStack(int data) - Push an element onto the stack.
    2. popStack() - Pop and return the top element.
    3. peekStack() - Return the top element without removing it.
    4. traversalStack() - Print all stack elements.

    Time Complexities:
    - pushStack(): O(1)
    - popStack(): O(1)
    - peekStack(): O(1)
    - traversalStack(): O(n), where n is the number of elements.
*/

#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

struct node *createNode(int data)
{
    struct node *head = new node;
    head->data = data;
    head->next = NULL;
    return head;
}

void pushStack(int data)
{
    struct node *newNode = createNode(data);
    if (top != NULL)
    {
        newNode->next = top;
    }
    top = newNode;
}

int popStack()
{
    struct node *temp = top;
    if (top != NULL)
    {
        top = top->next;
        int x = temp->data;
        delete temp;
        return x;
    }
    cout << "Stack reached to the bottom" << endl;
    return -1;
}

int peekStack()
{
    if (top != NULL)
    {
        return top->data;
    }
    cout << "Stack reached to the bottom" << endl;
    return -1;
}

void traversalStack()
{
    if (top == NULL)
    {
        cout << "Stack is empty" << endl;
        return;
    }
    struct node *ptr = top;
    while (ptr != NULL)
    {
        cout << ptr->data << endl;
        ptr = ptr->next;
    }
}

int main()
{
    pushStack(5);
    pushStack(15);
    pushStack(25);
    pushStack(35);
    pushStack(45);
    pushStack(55);

    popStack();
    cout << "Top element: " << peekStack() << endl;

    cout << "Stack elements:" << endl;
    traversalStack();

    return 0;
}
