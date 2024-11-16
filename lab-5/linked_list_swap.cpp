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
        }
        else
        {
            temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    return head;
}
void swap_adjacent(Node *head)
{
    Node *temp = head;
    while (temp != nullptr && temp->next != nullptr)
    {
        int swap_data = temp->data;
        temp->data = temp->next->data;
        temp->next->data = swap_data;
        temp = temp->next->next;
    }
}
void display_l_l(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
int main()
{
    cout << "Number of nodes: ";
    int n;
    cin >> n;
    Node *head = create_l_l(n);
    cout << "Linked List: ";
    display_l_l(head);
    swap_adjacent(head);
    cout << "Swapped Linked List: ";
    display_l_l(head);
    return 0;
}
