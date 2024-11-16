#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    bool leftThreaded;

    Node(int value)
    {
        data = value;
        left = right = nullptr;
        leftThreaded = false;
    }
};

// Insert a node into the threaded binary tree
Node *insert(Node *root, int value)
{
    if (!root)
    {
        return new Node(value); // Empty tree
    }

    Node *parent = nullptr;
    Node *current = root;

    // Traverse the tree to find where to insert the new node
    while (current != nullptr)
    {
        parent = current;

        if (value < current->data)
        {
            if (!current->leftThreaded)
            {
                current = current->left;
            }
            else
            {
                break; // Found the threaded link, insert here
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
        newNode->left = parent->left; // Maintain thread
        newNode->leftThreaded = true;
        parent->left = newNode;
        parent->leftThreaded = false;
    }
    else
    {
        parent->right = newNode;
    }

    return root;
}

// Find the rightmost node (the largest value)
Node *findRightmost(Node *root)
{
    while (root->right != nullptr)
    {
        root = root->right;
    }
    return root;
}

// Reverse in-order traversal of a threaded binary search tree (start from the end)
void reverseInorder(Node *root)
{
    if (!root)
        return;

    // Start from the rightmost node
    Node *current = findRightmost(root);

    while (current != nullptr)
    {
        // Visit the current node
        cout << current->data << " ";

        // Follow the left-threaded pointer to get the in-order predecessor
        if (current->leftThreaded)
        {
            current = current->left; // Move to predecessor
        }
        else
        {
            // Move to the left subtree to continue reverse in-order traversal
            current = current->left;
            if (current != nullptr)
            {
                while (current->right != nullptr)
                {
                    current = current->right;
                }
            }
        }
    }
}

// Driver code
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

    cout << "Reverse in-order traversal (starting from end) of the One-Way Left Threaded Binary Search Tree:\n";
    reverseInorder(root);

    return 0;
}
