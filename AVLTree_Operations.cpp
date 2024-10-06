/*
   AVL Tree Implementation in C++

   This program implements an AVL tree, a self-balancing binary search tree (BST).
   It ensures that the height difference between left and right subtrees is at most 1, maintaining balance through rotations.

   Functions:
   - getHeight: Returns the height of a node.
   - balancedFactor: Calculates the balance factor (height difference).
   - leftRotate, rightRotate: Rotates the tree to restore balance.
   - insert: Inserts a new key and maintains AVL balance.
   - preOrder: Traverses the tree in pre-order.

   Time Complexity:
   - Insertion: O(log n)
   - Rotation: O(1)
   - Pre-order Traversal: O(n)

   Space Complexity: O(n)

        4
       / \
      2   5
     / \    \
    1   3    6

*/

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    int height;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
        this->height = 1; // Initialize height as 1 for new node
    }
};

int getHeight(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return root->height;
}

int max(int leftHeight, int rightHeight)
{
    return (leftHeight > rightHeight) ? leftHeight : rightHeight;
}

int balancedFactor(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return getHeight(root->left) - getHeight(root->right);
}

Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

Node *insert(Node *root, int key)
{
    if (root == NULL)
    {
        return new Node(key);
    }

    if (key < root->data)
    {
        root->left = insert(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = insert(root->right, key);
    }
    else
    {
        return root;
    }

    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

    int BF = balancedFactor(root);

    // Left Left Case
    if (BF > 1 && key < root->left->data)
    {
        return rightRotate(root);
    }

    // Right Right Case
    if (BF < -1 && key > root->right->data)
    {
        return leftRotate(root);
    }

    // Left Right Case
    if (BF > 1 && key > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left Case
    if (BF < -1 && key < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void preOrder(Node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main()
{
    Node *root = NULL;

    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);

    preOrder(root);
    return 0;
}
