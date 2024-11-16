#include <iostream>
using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        
    }
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

TreeNode* findMin(TreeNode* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == nullptr) {
        return root;
    }

    // Recur down the tree
    if (key < root->value) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->value) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node to be deleted found

        // Case 1: Node with only one child or no child
        if (root->left == nullptr) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        // Case 2: Node with two children
        TreeNode* temp = findMin(root->right); // Get the inorder successor (smallest in the right subtree)
        root->value = temp->value; // Copy the inorder successor's value to this node
        root->right = deleteNode(root->right, temp->value); // Delete the inorder successor
    }

    return root;
}

void inorderTraversal(TreeNode* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        std::cout << root->value << " ";
        inorderTraversal(root->right);
    }
}

int main() {
    // Create a simple BST
    TreeNode* root = new TreeNode(50);
    root->left = new TreeNode(30);
    root->right = new TreeNode(70);
    root->left->left = new TreeNode(20);
    root->left->right = new TreeNode(40);
    root->right->left = new TreeNode(60);
    root->right->right = new TreeNode(80);

    std::cout << "Original tree: ";
    inorderTraversal(root);
    std::cout << std::endl;

    // Delete node
    root = deleteNode(root, 50);

    std::cout << "Tree after deleting 50: ";
    inorderTraversal(root);
    std::cout << std::endl;

    return 0;
}
