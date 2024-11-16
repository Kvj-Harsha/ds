#include <iostream>
#include <queue>
using namespace std;

// Structure for a tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function for Level Order Traversal
void levelOrderTraversal(Node* root) {
    if (root == nullptr) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        cout << current->data << " ";

        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
    cout << endl;
}

// Function to calculate the sum at the Kth level
int sumAtKthLevel(Node* root, int K) {
    if (root == nullptr) return 0;

    queue<Node*> q;
    q.push(root);

    int level = 0;
    int sum = 0;

    while (!q.empty()) {
        int size = q.size();

        // Check if this is the Kth level
        if (level == K) {
            for (int i = 0; i < size; i++) {
                Node* current = q.front();
                q.pop();
                sum += current->data;
            }
            return sum; // Return the sum as we don't need further levels
        }

        // Process the current level and enqueue the next level
        for (int i = 0; i < size; i++) {
            Node* current = q.front();
            q.pop();
            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
        level++;
    }
    return 0; // If K is greater than the height of the tree
}

int main() {
    // Example tree:
    //         1
    //       /   \
    //      2     3
    //     / \   / \
    //    4   5 6   7
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Level Order Traversal
    cout << "Level Order Traversal: ";
    levelOrderTraversal(root);

    // Sum at Kth level
    int K = 2; // Example: Find sum at level 2
    cout << "Sum at level " << K << ": " << sumAtKthLevel(root, K) << endl;

    return 0;
}
