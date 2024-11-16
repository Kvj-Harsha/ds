#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Function to create a new node
struct Node *nn(int item)
{
    struct Node *temp = new Node;
    temp->data = item;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Function to insert a node into the BST
struct Node *insert(struct Node *&node, int val)
{
    if (node == NULL)
    {
        return nn(val);
    }
    if (val < node->data)
    {
        node->left = insert(node->left, val);
    }
    else if (val > node->data)
    {
        node->right = insert(node->right, val);
    }
    return node;
}

// Function for in-order traversal (prints nodes in ascending order)
void inorderTraversal(Node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

// Helper function to find the minimum value node in a subtree
Node *minValueNode(Node *node)
{
    Node *current = node;
    while (current && current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

// Function to delete a node from the BST
Node *deletenode(Node *&root, int key)
{
    if (root == NULL)
        return root;

    // Recur down the tree to find the node to be deleted
    if (key < root->data)
    {
        root->left = deletenode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deletenode(root->right, key);
    }
    else
    {
        // Node with only one child or no child
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        Node *temp = minValueNode(root->right);

        // Copy the inorder successor's data to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deletenode(root->right, temp->data);
    }
    return root;
}

int main()
{
    struct Node *root = NULL;

    // Inserting nodes into the BST
    root = insert(root, 54);
    insert(root, 76);
    insert(root, 64);
    insert(root, 91);
    insert(root, 32);
    insert(root, 47);
    insert(root, 72);
    insert(root, 21);
    insert(root, 9);

    // Displaying the BST using in-order traversal
    cout << "BST before deletion: ";
    inorderTraversal(root);
    cout << endl;

    // Deleting a node (e.g., node with value 64)
    root = deletenode(root, 64);

    // Displaying the BST after deletion
    cout << "BST after deleting 64: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
