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
    if (value <= 0) return;  // Invalid value check

    Node *temp = head;
    Node *prev = nullptr;

    // Traverse to the node just before the node to be interchanged
    for (int i = 1; i < value; ++i) {
        prev = temp;
        temp = temp->next;
        if (temp == head)  // If reached the head again, stop
            return;
    }

    Node *current = temp;
    Node *nextNode = current->next;

    if (nextNode == head) {  // If the next node is the head, it means we are interchanging the last and first nodes
        cout << "Interchanging the last element with the first element." << endl;

        // Find the last node
        while (temp->next != head) {
            temp = temp->next;
        }
        // Adjust pointers for swapping the head and last nodes
        temp->next = head->next;
        head->next = nextNode;
        head = nextNode;  // Update the head to be the last node
    } else {
        // Interchanging node 'value' with node 'value + 1'
        cout << "Interchanging node " << value << " and " << value + 1 << "." << endl;

        if (prev != nullptr) {
            prev->next = nextNode;
        } else {
            head = nextNode;  // Update head if we are interchanging the first element with the second
        }
        current->next = nextNode->next;
        nextNode->next = current;
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
