#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

int isBST(Node *root) {
    static Node *prev = NULL;

    if (root != NULL) {
        if (!isBST(root->left)) {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data) {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    } else {
        return 1;
    }
}

void inOrder(Node *root) {
    if (root != NULL) {
        inOrder(root->left);
        cout << root->data << "\t";
        inOrder(root->right);
    }
}

int searchBST(Node *root, int key) {
    while (root != NULL) {
        if (key == root->data) {
            cout << "Element " << key << " found in BST" << endl;
            return 1;
        }
        if (key < root->data) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
    cout << "Element not found" << endl;
    return 0;
}

void insertBST(Node *root, int key) {
    Node *newNode = new Node(key);
    Node *prev = NULL;

    while (root != NULL) {
        if (key == root->data) {
            cout << "Element " << key << " is already in BST" << endl;
            return;
        }
        prev = root;
        if (key < root->data) {
            root = root->left;
        } else {
            root = root->right;
        }
    }

    if (key < prev->data) {
        prev->left = newNode;
    } else {
        prev->right = newNode;
    }
}

int main() {
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

    if (isBST(root)) {
        cout << "Tree is BST" << endl;
    } else {
        cout << "Tree isn't BST" << endl;
    }

    searchBST(root, 40);
    insertBST(root, 60);
    insertBST(root, 90);

    inOrder(root);
    return 0;
}
