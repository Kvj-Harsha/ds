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

        // Bubble Sort Logic
        for (int i = size - 1; i > 0; i--)
        {
            for (int j = 0; j < i; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
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
