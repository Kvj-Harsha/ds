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
    cout << "(HEAD)" << endl;
}
void interchange(Node *&head, int value)
{
    cout << "You are interchanging " << value << " and " << value + 1 << ". " << endl;

    Node *a = NULL;
    Node *b = head;
    for (int i = 1; i < value; ++i)
    {
        a = b;
        b = b->next;
        if (b == head)
            return;
    }
    Node *bb = b->next;
    if (bb == head)
        return;
    if (a != NULL)
    {
        a->next = bb;
    }
    else
    {
        head = bb;
    }
    b->next = bb->next;
    bb->next = b;
    if (b->next == head)
    {
        Node *temp = head;
        while (temp->next != b)
        {
            temp = temp->next;
        }
        temp->next = b;
    }
}
int main()
{
    cout << "Number of nodes: ";
    int n;
    cin >> n;
    Node *head = create_l_l(n);
    cout << "Circular Linked List: ";
    display_l_l(head);
    cout << "Enter the no of node to interchange ";
    int vall;
    cin >> vall;
    interchange(head, vall);
    cout << "The interchanged Circular Linked List: ";
    display_l_l(head);
    return 0;
}