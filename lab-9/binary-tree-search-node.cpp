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
    int countNodes(Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int leftCount = 0;
        if (left != NULL)
        {
            leftCount = left->countNodes(root);
        }
        int rightCount = 0;
        if (right != NULL)
        {
            rightCount = right->countNodes(root);
        }
        return 1 + leftCount + rightCount;
    }
};
int main()
{
    Node *root = new Node(1);
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

    int totalNodes = root->countNodes(root);
    cout << "Total number of nodes in the tree: " << totalNodes << endl;

    return 0;
}
