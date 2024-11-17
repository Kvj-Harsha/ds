#include <iostream>
using namespace std;

// Define the structure of a BST node
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val); // Create a new node if root is null
    }

    if (val < root->data) {
        root->left = insert(root->left, val); // Insert in the left subtree
    } else {
        root->right = insert(root->right, val); // Insert in the right subtree
    }

    return root;
}
bool search(Node* root, int key) {
    if (root == nullptr) {
        return false; // Key not found
    }

    if (root->data == key) {
        return true; // Key found
    } else if (key < root->data) {
        return search(root->left, key); // Search in the left subtree
    } else {
        return search(root->right, key); // Search in the right subtree
    }
}
void inorder(Node* root) {
    if (root == nullptr) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void preorder(Node* root) {
    if (root == nullptr) return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node* root) {
    if (root == nullptr) return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
Node* findMin(Node* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (root == nullptr) return root;

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node with one or no child
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
int main() {
    Node* root = nullptr;

    // Insert nodes
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    // Search for a value
    cout << "Search 40: " << (search(root, 40) ? "Found" : "Not Found") << endl;

    // Delete a node
    root = deleteNode(root, 50);
    cout << "Inorder Traversal after deleting 50: ";
    inorder(root);
    cout << endl;

    return 0;
}
