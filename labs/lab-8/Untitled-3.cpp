// CS23B1034
// K V Jaya Harsha
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = nullptr;
    }
};

Node *insertNode(Node *head, int data)
{
    Node *newNode = new Node(data);

    if (head == nullptr)
    {
        newNode->next = newNode;
        return newNode;
    }

    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
    return head;
}

void displayList(Node *head)
{
    if (head == nullptr)
        return;

    Node *temp = head;
    cout << temp->data << " ";
    temp = temp->next;

    while (temp != head)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
Node *getLastNode(Node *head)
{
    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    return temp;
}
Node *mergeLists(Node *head1, Node *head2)
{
    if (head1 == nullptr)
        return head2;
    if (head2 == nullptr)
        return head1;

    Node *newHead = nullptr;
    Node *tail = nullptr;

    Node *last1 = getLastNode(head1);
    Node *last2 = getLastNode(head2);
    last1->next = nullptr;
    last2->next = nullptr;
    if (head1->data <= head2->data)
    {
        newHead = head1;
        head1 = head1->next;
    }
    else
    {
        newHead = head2;
        head2 = head2->next;
    }
    tail = newHead;

    while (head1 != nullptr && head2 != nullptr)
    {
        if (head1->data <= head2->data)
        {
            tail->next = head1;
            tail = head1;
            head1 = head1->next;
        }
        else
        {
            tail->next = head2;
            tail = head2;
            head2 = head2->next;
        }
    }
    if (head1 != nullptr)
    {
        tail->next = head1;
    }
    else
    {
        tail->next = head2;
    }
    tail = newHead;
    while (tail->next != nullptr)
    {
        tail = tail->next;
    }
    tail->next = newHead;
    return newHead;
}

int main()
{
    Node *head1 = nullptr;
    head1 = insertNode(head1, 1);
    head1 = insertNode(head1, 2);
    head1 = insertNode(head1, 3);
    head1 = insertNode(head1, 4);
    head1 = insertNode(head1, 8);
    Node *head2 = nullptr;
    head2 = insertNode(head2, 0);
    head2 = insertNode(head2, 6);
    head2 = insertNode(head2, 9);
    cout << "First Circular Singly Linked List: ";
    displayList(head1);
    cout << "Second Circular Singly Linked List: ";
    displayList(head2);
    Node *mergedHead = mergeLists(head1, head2);
    cout << "Merged Circular Singly Linked List: ";
    displayList(mergedHead);
    return 0;
}