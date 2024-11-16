#include <iostream>
using namespace std;

int partition(int arr[], int first, int last)
{
    int pivot = arr[last];
    int i = first - 1;
    int j = first;

    for (; j < last; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[last]);
    return i + 1;
}

void quicksort(int arr[], int first, int last)
{
    if (first >= last)
    {
        return;
    }

    int pi = partition(arr, first, last);
    quicksort(arr, first, pi - 1);
    quicksort(arr, pi + 1, last);
}

int main()
{

    int size = 6;

    int arr[size] = {3, 46, 7, 34, 23, 4};

    quicksort(arr, 0, size - 1);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}