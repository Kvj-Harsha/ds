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

void preorder(Node* root){
    if (root!=NULL)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
    
}
void inorder(Node* root){
    if (root!=NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
    
}
void postorder(Node* root){
    if (root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
    
}

int main(){

    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    return 0;
}