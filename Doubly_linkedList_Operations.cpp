/*
    Program Description:
    --------------------
    This program implements a Doubly Linked List with:
    - Node creation
    - Insertion at a specific position
    - Deletion at a specific position
    - Forward and backward traversal

    Time Complexity:
    ----------------
    - Insertion/Deletion: O(1) for head, O(n) for specific position
    - Traversal: O(n)

    Space Complexity:
    -----------------
    - O(n) for n nodes
*/

#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *createNode(int data)
{
    struct node *root = new node();
    root->data = data;
    root->prev = nullptr;
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
    cout << "Doubly Linked List Forward Traversal now is:\n";
    struct node *current = root;
    struct node *previous = NULL;
    while (current != NULL)
    {
        cout << current->data << "\t";
        previous = current;
        current = current->next;
    }
    cout << "\n Doubly Linked List Backward Traversal now is:\n";
    while (previous != NULL)
    {
        cout << previous->data << "\t";
        previous = previous->prev;
    }
    cout << "\n";
}

struct node *insertNode(struct node *root, int data, int pos)
{
    struct node *newNode = createNode(data);
    if (pos == 1)
    {
        newNode->next = root;
        if (root != nullptr)
            root->prev = newNode;
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
        cout << "Position out of bounds, insertion not possible.\n";
        return root;
    }
    if (current->next == nullptr)
    {
        current->next = newNode;
        newNode->prev = current;
    }
    else
    {
        newNode->next = current->next;
        newNode->prev = current;
        current->next->prev = newNode;
        current->next = newNode;
    }
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
        if (root != nullptr)
        {
            root->prev = nullptr;
        }
        delete temp;
        return root;
    }

    struct node *current = root;
    int i = 1;

    while (current != nullptr && i < pos)
    {
        current = current->next;
        i++;
    }

    if (current == nullptr)
    {
        cout << "Position out of bounds, deletion not possible.\n";
        return root;
    }

    if (current->next == nullptr)
    {
        current->prev->next = nullptr;
    }
    else
    {
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }

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
    p1->prev = head;
    p1->next = p2;
    p2->prev = p1;
    p2->next = p3;
    p3->prev = p2;
    p3->next = p4;
    p4->prev = p3;

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
