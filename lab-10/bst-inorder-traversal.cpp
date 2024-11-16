// CS23B1034
// K V Jaya Harsha
#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
};
struct Node *nn(int item)
{
    struct Node *temp = new Node;
    temp->data = item;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
};
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
    if (val > node->data)
    {
        node->right = insert(node->right, val);
    }
    return node;
};
void inorderTraversal(Node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}
int main()
{
    struct Node *root = NULL;
    root = insert(root, 54);
    insert(root, 76);
    insert(root, 64);
    insert(root, 91);
    insert(root, 32);
    insert(root, 47);
    insert(root, 72);
    insert(root, 21);
    insert(root, 9);
    cout << "Displaying BST: ";
    inorderTraversal(root);
    cout << endl;
    return 0;
}
