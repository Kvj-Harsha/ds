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
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    Node *mergetwosortedll(Node *&head1, Node *&head2)
    {
        Node *temp2 = new Node(-1);
        Node *temp = temp2;
        while (head1 != NULL && head2 != NULL)
        {
            if (head1->data < head2->data)
            {
                temp->next = head1;
                head1 = head1->next;
            }
            else
            {
                temp->next = head2;
                head2 = head2->next;
            }
            temp = temp->next;
        }

        if (head1 != NULL)
        {
            temp->next = head1;
        }
        else
        {
            temp->next = head2;
        }
        return temp2->next;
    }
};

int main()
{
    Node *list1 = NULL;
    Node *list2 = NULL;
    Node n1(0);

    n1.insertnew(list1, 9);
    n1.insertnew(list1, 7);
    n1.insertnew(list1, 5);
    n1.insertnew(list1, 3);
    n1.insertnew(list1, 1);

    n1.insertnew(list2, 10);
    n1.insertnew(list2, 6);
    n1.insertnew(list2, 2);

    cout << "1: ";
    n1.display(list1);
    cout << "2: ";
    n1.display(list2);

    Node *nl = n1.mergetwosortedll(list1, list2);

    cout << "Merged List: ";
    n1.display(nl);

    return 0;
}
