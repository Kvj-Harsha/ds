#include <iostream>
using namespace std;

// Structure for a tree node
struct Node {
    int data;
    Node *left = nullptr;
    Node *right = nullptr;

    // Constructor to initialize a node
    Node(int data) : data(data) {}
};

// Function to find the index of the current root in the InOrder traversal
int searchInOrder(int inOrder[], int start, int end, int curr) {
    for (int j = start; j <= end; j++) {
        if (inOrder[j] == curr)
            return j;
    }
    return -1;
}

// Function to build the binary tree using InOrder and PreOrder traversals
Node* buildTree(int inOrder[], int preOrder[], int start, int end) {
    if (start > end) {
        return nullptr; // No elements left to construct the tree
    }

    static int preIndex = 0; // Static variable to track PreOrder traversal index

    // Create the root node with the current PreOrder element
    int curr = preOrder[preIndex++];
    Node *root = new Node(curr);

    // If this node has no children, return it
    if (start == end) {
        return root;
    }

    // Find the position of the current root in the InOrder traversal
    int pos = searchInOrder(inOrder, start, end, curr);

    // Recursively build the left and right subtrees
    root->left = buildTree(inOrder, preOrder, start, pos - 1);
    root->right = buildTree(inOrder, preOrder, pos + 1, end);

    return root;
}

// Function to perform an in-order traversal of the tree
void printInOrder(Node *root) {
    if (root == nullptr) {
        return;
    }
    printInOrder(root->left);  // Visit left subtree
    cout << root->data << " "; // Print current node
    printInOrder(root->right); // Visit right subtree
}

int main() {
    // Example input: InOrder and PreOrder traversals
    int inOrder[] = {4, 2, 5, 1, 6, 3};
    int preOrder[] = {1, 2, 4, 5, 3, 6};
    int n = sizeof(inOrder) / sizeof(inOrder[0]);

    // Build the tree
    Node *root = buildTree(inOrder, preOrder, 0, n - 1);

    // Print the in-order traversal of the constructed tree
    cout << "In-order: ";
    printInOrder(root);
    cout << endl;

    return 0;
}
