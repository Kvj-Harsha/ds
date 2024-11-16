// CS23B1034
// K V Jaya Harsha
// merge-two-sorted-single-linked-list
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }

    void insertnew(Node *&head, int val)
    {
        Node *nn = new Node(val);
        nn->next = head;
        head = nn;
    }

    void display(Node *head)
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << " NULL" << endl;
    }

    void mergetwosortedll(Node *&head)
    {
    }
};

int main()
{

    return 0;
}