#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node *thread;

    Node *createNode(int key)
    {
        Node *newNode = new Node;
        newNode->data = key;
        newNode->left = nullptr;
        newNode->right = nullptr;
        newNode->thread = nullptr;
        return newNode;
    }

    Node *leftmost(Node *node)
    {
        if (node == nullptr)
            return nullptr;
        while (node->left != nullptr)
        {
            node = node->left;
        }
        return node;
    }

    Node *insert(Node *root, int key)
    {
        if (root == nullptr)
            return createNode(key);

        if (key < root->data)
        {
            if (root->left == nullptr)
            {
                Node *newNode = createNode(key);
                newNode->thread = root; // Set the thread to the inorder predecessor
                root->left = newNode;
            }
            else
            {
                root->left = insert(root->left, key);
            }
        }
        else
        {
            root->right = insert(root->right, key);
        }

        return root;
    }

    // Function for inorder traversal of the left-threaded BST
    void inorder(Node *root)
    {
        if (root != NULL)
        {
            inorder(root->right);
            cout << root->data << " ";
            inorder(root->left);
        }
    }

    int main()
    {
        Node *root = nullptr;

        // Insert nodes into the left-threaded BST
        root = insert(root, 57);
        root = insert(root, 76);
        root = insert(root, 64);
        root = insert(root, 91);
        root = insert(root, 32);
        root = insert(root, 47);
        root = insert(root, 72);
        root = insert(root, 21);
        root = insert(root, 9);

        // Perform inorder traversal
        cout << "Inorder traversal of the left-threaded BST: ";
        inorder(root);
        cout << endl;

        return 0;
    }
