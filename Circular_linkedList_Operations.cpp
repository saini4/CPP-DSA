/*
 * Circular Linked List Implementation
 *
 * This program implements a circular linked list with functionalities to:
 * 1. Create nodes.
 * 2. Print the list.
 * 3. Insert a node at a specified position.
 * 4. Delete a node from a specified position.
 *
 * The list is circular, meaning the last node points back to the first,
 * allowing for continuous traversal.
 *
 * Time Complexities:
 * - Creating a node: O(1)
 * - Printing the list: O(n)
 * - Inserting a node: O(n) (O(1) for inserting at the head)
 * - Deleting a node: O(n) (O(1) for deleting the head)
 *
 * Space Complexity:
 * - O(n) for storing n nodes in the list.
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
    if (root == nullptr)
    {
        cout << "List is empty.\n";
        return;
    }
    cout << "Circular Linked List Traversal now is:\n";
    struct node *head = root;
    cout << head->data << "-->";
    head = head->next;
    while (head != root)
    {
        cout << head->data << "-->";
        head = head->next;
    }
    cout << "back to head node\n";
}

struct node *insertNode(struct node *root, int data, int pos)
{
    struct node *newNode = createNode(data);
    if (pos == 1)
    {
        struct node *current = root;
        while (current->next != root)
        {
            current = current->next;
        }
        newNode->next = root;
        current->next = newNode;
        return newNode;
    }
    struct node *current = root;
    int i = 1;
    while (current->next != root && i < pos - 1)
    {
        current = current->next;
        i++;
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
        while (temp->next != root)
        {
            temp = temp->next;
        }
        temp->next = root->next;
        struct node *newHead = root->next;
        delete root;
        return newHead;
    }
    struct node *current = root;
    struct node *previous = nullptr;
    int i = 1;
    while (current->next != root && i < pos)
    {
        previous = current;
        current = current->next;
        i++;
    }
    if (current == root)
    {
        cout << "Position out of range\n";
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
    p4->next = head; // Closing the circular link

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
