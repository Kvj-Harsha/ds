// CS23B1034
// K V Jaya Harsha
#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    bool leftThreaded;
    Node(int key)
    {
        data = key;
        left = right = nullptr;
        leftThreaded = false;
    }
};
Node *createNode(int key)
{
    return new Node(key);
}
Node *insert(Node *root, int key)
{
    if (root == nullptr)
    {
        return createNode(key);
    }

    if (key < root->data)
    {
        if (root->left == nullptr)
        {
            Node *newNode = createNode(key);
            newNode->left = root->left;
            newNode->leftThreaded = true;
            root->left = newNode;
            root->leftThreaded = false;
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
void inorder(Node *root)
{
    if (root == nullptr)
        return;
    if (!root->leftThreaded)
    {
        inorder(root->left);
    }
    cout << root->data << " ";
    inorder(root->right);
}
int main()
{
    Node *root = nullptr;
    root = insert(root, 54);
    insert(root, 76);
    insert(root, 64);
    insert(root, 91);
    insert(root, 32);
    insert(root, 47);
    insert(root, 72);
    insert(root, 21);
    insert(root, 9);
    cout << "Displaying Threaded BST: ";
    inorder(root);
    cout << endl;
    return 0;
}
