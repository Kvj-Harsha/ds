// CS23B1034
// K V Jaya Harsha
#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node *prev;
};

Node *create_dll(int n)
{
    Node *head = nullptr;
    Node *temp = nullptr;
    Node *newNode = nullptr;
    int value;

    for (int i = 0; i < n; i++)
    {
        cout << "Element " << (i + 1) << " : ";
        cin >> value;

        newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;
        newNode->prev = nullptr;

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
            newNode->prev = temp;
        }
    }
    return head;
}

void display_forward(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void display_backward(Node *tail)
{
    Node *temp = tail;
    while (temp != nullptr)
    {
        cout << temp->data << " -> ";
        temp = temp->prev;
    }
    cout << "NULL" << endl;
}

int count_non_zero(Node *head)
{
    int count = 0;
    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp->data != 0)
        {
            count++;
        }
        temp = temp->next;
    }
    return count;
}

int main()
{
    cout << "Number of nodes: ";
    int n;
    cin >> n;
    Node *head = create_dll(n);
    cout << "DLL_Forword: ";
    display_forward(head);
    Node *tail = head;
    while (tail != nullptr && tail->next != nullptr)
    {
        tail = tail->next;
    }
    cout << "DLL_Backside: ";
    display_backward(tail);
    int non_zero_count = count_non_zero(head);
    cout << "non-zero nodes: " << non_zero_count << endl;

    return 0;
}
