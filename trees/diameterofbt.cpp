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

int heightof(Node* root){
    if(root==NULL){
        return 0;
    }

    int lh = heightof(root->left);
    int rh = heightof(root->right);

    return max(lh,rh) + 1;

}

int diameter(Node* root){
    if (root==NULL)
    {
        return 0;
    }

    int lh = heightof(root->left);
    int rh = heightof(root->right);
    int cd = lh + rh + 1;

    int ld = diameter(root->left);
    int rd = diameter(root->right);

    return max(cd, max(ld,rd));
    
}

int main(){

    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // int ht = heightof(root);
    int d = diameter(root);
    cout << d;
    // preorder(root);
    // inorder(root);
    // postorder(root);
    return 0;
}