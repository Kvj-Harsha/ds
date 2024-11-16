// CS23B1034
// K V Jaya Harsha
#include <iostream>
using namespace std;
class PriorityQueue
{
    int *arr, size, capacity;

public:
    PriorityQueue(int cap)
    {
        capacity = cap;
        arr = new int[capacity];
        size = 0;
    }
    ~PriorityQueue()
    {
        delete[] arr;
    }
    void enque(int element)
    {
        if (size >= capacity)
        {
            cout << "Queue Overflow!" << endl;
            return;
        }
        arr[size] = element;
        size++;
        int i = size - 1;
        while (i > 0 && arr[i] < arr[i - 1])
        {
            int temp = arr[i];
            arr[i] = arr[i - 1];
            arr[i - 1] = temp;
            i--;
        }
    }
    void deque()
    {
        if (size == 0)
        {
            cout << "Queue Underflow!" << endl;
            return;
        }
        for (int i = 0; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        size--;
    }
    void display()
    {
        if (size == 0)
        {
            cout << "Queue Underflow!" << endl;
            return;
        }
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    int front()
    {
        if (size == 0)
        {
            cout << "Queue Underflow!" << endl;
            return -1;
        }
        return arr[0];
    }
};
int main()
{
    PriorityQueue pq(10);
    pq.enque(30);
    pq.enque(50);
    pq.enque(10);
    pq.enque(20);
    cout << "Priority Queue: ";
    pq.display();
    cout << "Front element: " << pq.front() << endl;
    pq.deque();
    cout << "After dequeue, Priority Queue: ";
    pq.display();
    return 0;
}
