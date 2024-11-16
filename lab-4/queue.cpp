// CS23B1034
// K V Jaya Harsha
#include <iostream>
using namespace std;
class Queue
{
    int front, rear, capacity;
    int *queue;

public:
    Queue(int cap)
    {
        front = -1;
        rear = -1;
        capacity = cap;
        queue = new int[cap];
    }
    ~Queue()
    {
        delete[] queue;
    }
    void enque(int data)
    {
        if (rear == capacity - 1)
        {
            cout << "Queue Overflow" << endl;
            return;
        }
        if (front == -1)
        {
            front = 0;
        }
        queue[++rear] = data;
    }
    void dequeue()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue Underflow" << endl;
            return;
        }
        for (int i = 0; i < rear; i++)
        {
            queue[i] = queue[i + 1];
        }
        rear--;
        if (rear < front)
        {
            rear = -1;
            front = -1;
        }
    }
    void display()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue Underflow -- it is empty.";
            return;
        }
        for (int i = front; i <= rear; i++)
        {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
    void frontelement()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue Underflow -- it is empty.";
            return;
        }
        cout << "Front element is " << queue[front] << ". " << endl;
    }
};
int main()
{
    Queue q1(10);
    q1.dequeue();
    q1.enque(10);
    q1.enque(20);
    q1.enque(30);
    q1.enque(40);
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.enque(10);
    q1.enque(20);
    q1.enque(30);
    q1.enque(40);
    q1.enque(50);
    q1.enque(60);
    q1.enque(70);
    q1.enque(80);
    q1.enque(90);
    q1.enque(100);
    q1.display();
    q1.frontelement();
    return 0;
}
