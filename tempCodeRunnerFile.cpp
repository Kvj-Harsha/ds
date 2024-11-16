#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

struct BST {
    Node* root;

    BST() {
        root = nullptr;
    }

    Node* insert(Node* root, int data) {
        if (root == nullptr) {
            return new Node(data);
        }
        if (data < root->data) {
            root->left = insert(root->left, data);
        } else {
            root->right = insert(root->right, data);
        }
        return root;
    }

    Node* findMin(Node* root) {
        while (root && root->left != nullptr) {
            root = root->left;
        }
        return root;
    }

    Node* deleteNode(Node* root, int data) {
        if (root == nullptr) {
            return root;
        }
        if (data < root->data) {
            root->left = deleteNode(root->left, data);
        } else if (data > root->data) {
            root->right = deleteNode(root->right, data);
        } else {
            // Node with one or no children
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            // Node with two children: get inorder successor
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }

    void preOrder(Node* root) {
        if (root == nullptr) {
            return;
        }
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }

    void inOrder(Node* root) {
        if (root == nullptr) {
            return;
        }
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }

    void postOrder(Node* root) {
        if (root == nullptr) {
            return;
        }
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }

    Node* search(Node* root, int key) {
        if (root == nullptr || root->data == key) {
            return root;
        }
        if (key < root->data) {
            return search(root->left, key);
        }
        return search(root->right, key);
    }

    void insert(int data) {
        root = insert(root, data);
    }

    void deleteNode(int data) {
        root = deleteNode(root, data);
    }

    void preOrderTraversal() {
        preOrder(root);
        cout << endl;
    }

    void inOrderTraversal() {
        inOrder(root);
        cout << endl;
    }

    void postOrderTraversal() {
        postOrder(root);
        cout << endl;
    }

    bool search(int key) {
        return search(root, key) != nullptr;
    }
};

int main() {
    BST tree;

    // Insert elements
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "In-order Traversal: ";
    tree.inOrderTraversal();

    cout << "Pre-order Traversal: ";
    tree.preOrderTraversal();

    cout << "Post-order Traversal: ";
    tree.postOrderTraversal();

    // Search for a node
    int key = 40;
    if (tree.search(key)) {
        cout << key << " is found in the BST.\n";
    } else {
        cout << key << " is not found in the BST.\n";
    }

    // Delete a node
    tree.deleteNode(50);
    cout << "In-order Traversal after deleting 50: ";
    tree.inOrderTraversal();

    return 0;
}
