#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int value){
        data = value;
        right = NULL;
        left = NULL;
    }

};

void inorder(Node* root){
    if (root!=NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
    
}
int nofonodes(Node* root){
    if (root==NULL)
    {
        return 0;
    }
    return nofonodes(root->left)+nofonodes(root->right)+1;
}

int main(){

    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    int tot = nofonodes(root);
    cout << tot << "\n";
    inorder(root);
    return 0;
}