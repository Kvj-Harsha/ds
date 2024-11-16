// CS23B1034
// K V Jaya Harsha
#include <iostream>

using namespace std;
class CircularQueue
{
    int front, rear, capacity, *queue;

public:
    CircularQueue(int c)
    {
        front = rear = -1;
        capacity = c;
        queue = new int[capacity];
    }
    ~CircularQueue()
    {
        delete[] queue;
    }
    void enque(int data)
    {
        if ((front == 0 && rear == capacity - 1) || (rear == (front - 1) % (capacity - 1)))
        {
            cout << "Queue Overflow" << endl;
            return;
        }
        else if (front == -1)
        {
            front = rear = 0;
            queue[rear] = data;
        }
        else if (rear == capacity - 1 && front != 0)
        {
            rear = 0;
            queue[rear] = data;
        }
        else
        {
            rear++;
            queue[rear] = data;
        }
    }
    void dequeue()
    {
        if (front == -1)
        {
            cout << "Queue Overflow" << endl;
            return;
        }
        if (front == rear)
        {
            front = rear = -1;
        }
        else if (front == capacity - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
    }
    void display()
    {
        if (front == -1)
        {
            cout << "Queue Underflow" << endl;
            return;
        }
        if (rear >= front)
        {
            for (int i = front; i <= rear; i++)
            {
                cout << queue[i] << " ";
            }
        }
        else
        {
            for (int i = front; i < capacity; i++)
            {
                cout << queue[i] << " ";
            }
            for (int i = 0; i <= rear; i++)
            {
                cout << queue[i] << " ";
            }
        }
        cout << endl;
    }
    void frontElement()
    {
        if (front == -1)
        {
            cout << "Queue underflow" << endl;
            return;
        }
        cout << "\nFront Element is: " << queue[front] << endl;
    }
};
int main()
{
    CircularQueue q1(10);
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
    q1.frontElement();
    return 0;
}
