#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

// Function to create a circular linked list
Node *create_l_l(int n) {
    Node *head = nullptr;
    Node *last = nullptr;
    int value;
    for (int i = 0; i < n; i++) {
        cout << "Element " << (i + 1) << " : ";
        cin >> value;
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            last = head;
        } else {
            last->next = newNode;
            last = newNode;
        }
    }

    if (last != nullptr) {
        last->next = head; // Make the list circular
    }
    return head;
}

// Function to display the circular linked list
void display_l_l(Node *head) {
    if (head == nullptr)
        return;
    Node *temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "(HEAD)" << endl;
}

// Function to interchange nodes in the circular linked list
void interchange(Node *&head, int value) {
    // Check if the value is the last node
    if (value == value) { 
        cout << "Interchanging the last element with the first element." << endl;
        Node *temp = head;
        Node *prev = nullptr;

        // Traverse to the last element
        while (temp->next != head) {

            
            prev = temp;
            temp = temp->next;
        }

        // Swap the head and the last node
        if (prev != nullptr) {
            prev->next = head; // Link the previous node to the current head
            temp->next = head->next; // Point the last node to the second node
            head->next = temp; // Link the current head to the last node
            head = temp; // Update the head to be the last node
        }
        return;
    }

    // Interchange element at position 'value' with 'value + 1'
    cout << "You are interchanging " << value << " and " << value + 1 << ". " << endl;

    Node *a = nullptr;
    Node *b = head;
    for (int i = 1; i < value; ++i) {
        a = b;
        b = b->next;
        if (b == head)
            return;
    }
    Node *bb = b->next;
    if (bb == head)
        return;
    if (a != nullptr) {
        a->next = bb;
    } else {
        head = bb;
    }
    b->next = bb->next;
    bb->next = b;
    if (b->next == head) {
        Node *temp = head;
        while (temp->next != b) {
            temp = temp->next;
        }
        temp->next = b;
    }
}

int main() {
    cout << "Number of nodes: ";
    int n;
    cin >> n;
    Node *head = create_l_l(n);
    cout << "Circular Linked List: ";
    display_l_l(head);
    cout << "Enter the number of the node to interchange: ";
    int vall;
    cin >> vall;
    interchange(head, vall);
    cout << "The interchanged Circular Linked List: ";
    display_l_l(head);
    return 0;
}
