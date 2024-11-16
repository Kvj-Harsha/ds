#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {} // Constructor for easy node creation
};

// Function to swap data between two nodes
void swapData(Node *a, Node *b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

// Function to sort the linked list using Bubble Sort
void bubbleSort(Node *head)
{
    if (!head)
        return; // Return if the list is empty

    bool swapped;
    Node *current;
    Node *last = nullptr; // Marks the end of the sorted part

    do
    {
        swapped = false;
        current = head;

        while (current->next != last)
        {
            if (current->data > current->next->data)
            {
                swapData(current, current->next);
                swapped = true;
            }
            current = current->next;
        }
        last = current; // Move the end marker backwards
    } while (swapped);
}

// Function to print the list
void printList(Node *head)
{
    while (head)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Function to insert a new node at the beginning
void insertAtBegin(Node *&head, int data)
{
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

int main()
{
    Node *head = nullptr;
    int arr[] = {78, 20, 10, 32, 1, 5};

    for (int i = 0; i < 6; i++) // Insert elements into the linked list
        insertAtBegin(head, arr[i]);

    cout << "Linked list before sorting\n";
    printList(head);

    bubbleSort(head);

    cout << "Linked list after sorting\n";
    printList(head);

    return 0;
}
