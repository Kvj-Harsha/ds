#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {} // Constructor for easy node creation
};

// Function to insert a new node at the beginning
void insertAtBegin(Node *&head, int data)
{
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

// Function to sort the linked list using Insertion Sort
void insertionSort(Node *&head)
{
    if (!head || !head->next)
        return; // Return if the list is empty or has one element

    Node *sorted = nullptr; // Sorted part of the list
    Node *current = head;   // Current node to be inserted

    while (current)
    {
        Node *next = current->next; // Store the next node
        if (!sorted || sorted->data >= current->data)
        {
            // Insert at the beginning of the sorted list
            current->next = sorted;
            sorted = current;
        }
        else
        {
            // Find the correct position to insert the current node
            Node *temp = sorted;
            while (temp->next && temp->next->data < current->data)
            {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next; // Move to the next node to be inserted
    }
    head = sorted; // Update head to the new sorted list
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

int main()
{
    Node *head = nullptr;
    int arr[] = {78, 20, 10, 32, 1, 5};

    for (int i = 0; i < 6; i++) // Insert elements into the linked list
        insertAtBegin(head, arr[i]);

    cout << "Linked list before sorting:\n";
    printList(head);

    insertionSort(head);

    cout << "Linked list after sorting:\n";
    printList(head);

    return 0;
}
