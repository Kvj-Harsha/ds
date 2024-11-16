// CS23B1034
// K V Jaya Harsha
#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
    void inorder(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    void preorder(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        cout << root->data << " ";
        inorder(root->left);
        inorder(root->right);
    }
    void postorder(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        inorder(root->left);
        inorder(root->right);
        cout << root->data << " ";
    }
};
int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->right->right = new Node(8);
    root->right->right->left = new Node(9);
    root->left->left->left = new Node(10);
    root->left->left->right = new Node(11);
    root->left->left->right->right = new Node(12);
    cout << "inorder: ";
    root->inorder(root);
    cout << '\n';
    cout << "preorder: ";
    root->preorder(root);
    cout << '\n';
    cout << "postorder: ";
    root->postorder(root);
    return 0;
}
