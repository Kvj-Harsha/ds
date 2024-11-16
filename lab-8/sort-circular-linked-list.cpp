// CS23B1034
// K V Jaya Harsha
// sorting-doubly-circular-linked-list
#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *prev;
    Node *next;

    Node(int value)
    {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};
struct cll
{
    Node *head = nullptr;
    Node *tail = nullptr;
};
void insertnode(Node *&head, int data)
{
    Node *nn = new Node(data);
    if (head == nullptr)
    {
        head = nn;
        nn->next = head;
        nn->prev = head;
    }
    else
    {
        Node *tail = head->prev;
        tail->next = nn;
        nn->prev = tail;
        nn->next = head;
        head->prev = nn;
    }
}
void display(Node *head)
{
    if (head == nullptr)
    {
        return;
    }
    Node *temp = head;
    do
    {
        cout << temp->data << "<->";
        temp = temp->next;
    } while (temp != head);
    cout << "HEAD" << endl;
}
void bubblesortll(Node *&head)
{
    if (head == nullptr)
        return;

    bool swapped;
    Node *current;
    Node *last = nullptr;

    do
    {
        swapped = false;
        current = head;

        while (current->next != last && current->next != head)
        {
            if (current->data > current->next->data)
            {
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = true;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);
}

int main()
{
    Node *head = NULL;
    insertnode(head, 13);
    insertnode(head, 2);
    insertnode(head, 334);
    insertnode(head, 53);
    insertnode(head, 783);
    cout << "before sort: ";
    display(head);
    cout << "after sort: ";
    bubblesortll(head);
    display(head);
    return 0;
}