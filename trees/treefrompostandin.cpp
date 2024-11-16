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

// Function to build the binary tree using PostOrder and InOrder traversals
Node* buildTree(int postOrder[], int inOrder[], int start, int end, int& postIndex) {
    // Base case: If no elements are left to construct the tree
    if (start > end) {
        return nullptr;
    }

    // Get the current root from PostOrder traversal
    int curr = postOrder[postIndex];
    postIndex--;

    // Create the root node
    Node* root = new Node(curr);

    // If this node has no children, return it
    if (start == end) {
        return root;
    }

    // Find the position of the current root in the InOrder traversal
    int pos = searchInOrder(inOrder, start, end, curr);

    // Recursively build the right and left subtrees
    root->right = buildTree(postOrder, inOrder, pos + 1, end, postIndex);
    root->left = buildTree(postOrder, inOrder, start, pos - 1, postIndex);

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
    // Example input: PostOrder and InOrder traversals
    int postOrder[] = {4, 2, 5, 3, 1};
    int inOrder[] = {4, 2, 1, 5, 3};
    int n = sizeof(postOrder) / sizeof(postOrder[0]);

    // Index to keep track of PostOrder traversal
    int postIndex = n - 1;

    // Build the tree
    Node *root = buildTree(postOrder, inOrder, 0, n - 1, postIndex);

    // Print the in-order traversal of the constructed tree
    cout << "In-order traversal of the constructed tree: ";
    printInOrder(root);
    cout << endl;

    return 0;
}
