/*
This program implements a singly linked list in C++. It provides the following functionalities:
1. Create and initialize nodes in the linked list.
2. Traverse and print the contents of the linked list.
3. Insert a new node at a specific position in the linked list.
4. Delete a node from a specific position in the linked list.

The program first creates a linked list with five nodes. It then allows the user to:
- Insert a node at a given position.
- Delete a node from a given position.
- Finally, the linked list is displayed after each operation.
*/

#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct node *createNode(int data)
{
    struct node *root = new node();
    root->data = data;
    root->next = nullptr;
    return root;
}

void printList(struct node *root)
{
    cout << "Singly Linked List Traversal now is:\n";
    while (root != nullptr)
    {
        cout << root->data << "-->";
        root = root->next;
    }
    cout << "null \n";
}

struct node *insertNode(struct node *root, int data, int pos)
{
    struct node *newNode = createNode(data);
    if (pos == 1)
    {
        newNode->next = root;
        return newNode;
    }
    struct node *current = root;
    int i = 1;
    while (current != nullptr && i < pos - 1)
    {
        current = current->next;
        i++;
    }
    if (current == nullptr)
    {
        cout << "Position out of bounds\n";
        delete newNode;
        return root;
    }
    newNode->next = current->next;
    current->next = newNode;
    return root;
}

struct node *deleteNode(struct node *root, int pos)
{
    if (root == nullptr)
    {
        cout << "List is empty\n";
        return root;
    }
    if (pos == 1)
    {
        struct node *temp = root;
        root = root->next;
        delete temp;
        return root;
    }
    struct node *current = root;
    struct node *previous = nullptr;
    int i = 1;
    while (current != nullptr && i < pos)
    {
        previous = current;
        current = current->next;
        i++;
    }
    if (current == nullptr)
    {
        cout << "Position out of bounds\n";
        return root;
    }
    previous->next = current->next;
    delete current;
    return root;
}

int main()
{
    struct node *head = createNode(10);
    struct node *p1 = createNode(20);
    struct node *p2 = createNode(30);
    struct node *p3 = createNode(40);
    struct node *p4 = createNode(50);

    head->next = p1;
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    printList(head);

    int pos;
    int value;

    cout << "Enter the position where you want to insert a new node: \n";
    cin >> pos;
    cout << "Enter the value of the new node: \n";
    cin >> value;
    head = insertNode(head, value, pos);
    printList(head);

    cout << "Enter the position of the node you want to delete: \n";
    cin >> pos;
    head = deleteNode(head, pos);
    printList(head);

    return 0;
}
