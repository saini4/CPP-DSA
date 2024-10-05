/*
    This program implements a Binary Search Tree (BST) with the following operations:

    1. **isBST()**:
       - Checks whether a tree is a valid BST.
       - Time Complexity: O(n), where n is the number of nodes in the tree.
       - Space Complexity: O(h), where h is the height of the tree (due to recursion stack).

    2. **inOrder()**:
       - Traverses the tree in an in-order manner (left, root, right).
       - Time Complexity: O(n), where n is the number of nodes.
       - Space Complexity: O(h), where h is the height of the tree (recursion stack).

    3. **searchBST()**:
       - Searches for a given key in the BST.
       - Time Complexity: O(h), where h is the height of the tree.
       - Space Complexity: O(1).

    4. **insertBST()**:
       - Inserts a new key into the BST.
       - Time Complexity: O(h), where h is the height of the tree.
       - Space Complexity: O(1).

    5. **pred()**:
       - Finds the predecessor (maximum value node in the left subtree).
       - Time Complexity: O(h), where h is the height of the tree.
       - Space Complexity: O(1).

    6. **deleteBST()**:
       - Deletes a key from the BST.
       - Time Complexity: O(h), where h is the height of the tree.
       - Space Complexity: O(1).

    7. **Main function**:
       - Demonstrates insertion, searching, deletion, and checking if the tree is a valid BST.
*/

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

int isBST(Node *root)
{
    static Node *prev = NULL;

    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
}

void inOrder(Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << root->data << "\t";
        inOrder(root->right);
    }
}

int searchBST(Node *root, int key)
{
    while (root != NULL)
    {
        if (key == root->data)
        {
            cout << "Element " << key << " found in BST" << endl;
            return 1;
        }
        if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    cout << "Element not found" << endl;
    return 0;
}

void insertBST(Node *root, int key)
{
    Node *newNode = new Node(key);
    Node *prev = NULL;

    while (root != NULL)
    {
        if (key == root->data)
        {
            cout << "Element " << key << " is already in BST" << endl;
            return;
        }
        prev = root;
        if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }

    if (key < prev->data)
    {
        prev->left = newNode;
    }
    else
    {
        prev->right = newNode;
    }
}

Node *pred(Node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

Node *deleteBST(Node *root, int key)
{
    if (root == NULL)
    {
        cout << "Element not found in the BST" << endl;
        return NULL;
    }

    if (key < root->data)
    {
        cout << "Going left to delete " << key << endl;
        root->left = deleteBST(root->left, key);
    }
    else if (key > root->data)
    {
        cout << "Going right to delete " << key << endl;
        root->right = deleteBST(root->right, key);
    }
    else
    {
        cout << "Found node " << key << " to delete" << endl;

        if (root->left == NULL && root->right == NULL)
        {
            cout << "Deleting leaf node " << key << endl;
            delete root;
            return NULL;
        }
        else if (root->left == NULL)
        {
            cout << "Node " << key << " has only right child" << endl;
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            cout << "Node " << key << " has only left child" << endl;
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            cout << "Node " << key << " has two children" << endl;
            Node *iPre = pred(root);
            cout << "In-order predecessor is " << iPre->data << endl;
            root->data = iPre->data;
            root->left = deleteBST(root->left, iPre->data);
        }
    }
    return root;
}

int main()
{
    Node *root = new Node(50);
    Node *p1 = new Node(30);
    Node *p2 = new Node(70);
    Node *p3 = new Node(10);
    Node *p4 = new Node(40);

    root->left = p1;
    root->right = p2;
    p1->left = p3;
    p1->right = p4;

    inOrder(root);
    cout << endl;

    if (isBST(root))
    {
        cout << "Tree is BST" << endl;
    }
    else
    {
        cout << "Tree isn't BST" << endl;
    }

    searchBST(root, 40);
    insertBST(root, 60);
    insertBST(root, 90);
    insertBST(root, 100);
    inOrder(root);
    root = deleteBST(root, 70);
    inOrder(root);
    return 0;
}
