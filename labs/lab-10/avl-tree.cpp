#include <iostream>
using namespace std;

// Node structure for a threaded binary tree
struct Node
{
    int data;
    Node *left;
    Node *right;
    bool leftThreaded; // true if left pointer is a thread (points to in-order predecessor)

    // Constructor
    Node(int value)
    {
        data = value;
        left = right = nullptr;
        leftThreaded = false;
    }
};

// Insert a node in a threaded binary search tree
Node *insert(Node *root, int value)
{
    if (!root)
    {
        return new Node(value);
    }

    Node *current = root;
    Node *parent = nullptr;

    // Traverse the tree to find the correct position
    while (current != nullptr)
    {
        if (value == current->data)
        {
            cout << "Duplicate values not allowed.\n";
            return root;
        }

        parent = current;

        if (value < current->data)
        {
            if (!current->leftThreaded)
            {
                current = current->left;
            }
            else
            {
                break;
            }
        }
        else
        {
            current = current->right;
        }
    }

    Node *newNode = new Node(value);

    if (value < parent->data)
    {
        newNode->left = parent->left; // Set thread to in-order predecessor
        newNode->leftThreaded = true;
        parent->left = newNode;
        parent->leftThreaded = false; // Break thread
    }
    else
    {
        parent->right = newNode;
    }

    return root;
}

// In-order traversal of the threaded binary search tree
void inorder(Node *root)
{
    if (!root)
        return;

    Node *current = root;

    // Go to the leftmost node
    while (current != nullptr)
    {
        while (!current->leftThreaded && current->left != nullptr)
        {
            current = current->left;
        }

        // Visit the node
        cout << current->data << " ";

        // Move to the in-order successor
        while (current->leftThreaded)
        {
            current = current->left;
            cout << current->data << " ";
        }

        current = current->right;
    }
}

// Driver code to test the threaded binary search tree
int main()
{
    Node *root = nullptr;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "In-order traversal of One-Way Left Threaded Binary Search Tree:\n";
    inorder(root);

    return 0;
}
