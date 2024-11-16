// CS23B1034
// K V Jaya Harsha
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *create_l_l(int n)
{
    Node *head = nullptr;
    Node *temp = nullptr;
    Node *last = nullptr;
    int value;

    for (int i = 0; i < n; i++)
    {
        cout << "Element " << (i + 1) << " : ";
        cin >> value;
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode;
            last = head;
        }
        else
        {
            last->next = newNode;
            last = newNode;
        }
    }

    if (last != nullptr)
    {
        last->next = head;
    }
    return head;
}

void display_l_l(Node *head)
{
    if (head == nullptr)
        return;

    Node *temp = head;
    do
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);

    cout << "(head)" << endl;
}

int main()
{
    cout << "Number of nodes: ";
    int n;
    cin >> n;
    Node *head = create_l_l(n);
    cout << "Circular Linked List: ";
    display_l_l(head);
    return 0;
}
