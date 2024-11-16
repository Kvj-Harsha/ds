#include <iostream>
using namespace std;

void printarr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1 + j];
    }

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(int arr[], int s, int e)
{
    if (s < e)
    {
        int mid = (s + e) / 2;

        mergesort(arr, s, mid);
        mergesort(arr, mid + 1, e);

        merge(arr, s, mid, e);
    }
}

int main()
{
    int size = 5;
    int arr[size] = {345, 57, 327, 423, 2};

    printarr(arr, size);
    cout<<"\n";

    mergesort(arr, 0, size - 1);

    printarr(arr, size);

    return 0;
}