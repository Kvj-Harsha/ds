// CS23B1034
// K V Jaya Harsha
#include <iostream>
#include <stack>
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
    void tosearch(Node *root, int target)
    {
        if (root == NULL)
        {
            cout << "Tree is empty." << endl;
            return;
        }
        stack<Node *> s;
        s.push(root);
        while (!s.empty())
        {
            Node *current = s.top();
            s.pop();
            if (current->data == target)
            {
                cout << "True.\nElement found." << endl;
                return;
            }
            if (current->right != NULL)
            {
                s.push(current->right);
            }
            if (current->left != NULL)
            {
                s.push(current->left);
            }
        }
        cout << "False.\nElement not found." << endl;
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
    root->left->left->right = new Node(12);
    int n;
    cout << "Please enter the target: ";
    cin >> n;
    root->tosearch(root, n);
    return 0;
}
