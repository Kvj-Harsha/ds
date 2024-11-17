#include <iostream>
using namespace std;

void countingSort(int arr[], int n,         
int exp) {
    int C[10] = {0};

    for (int i = 0; i < n; i++) {
        int index = (arr[i]/exp)%10;
        C[index]++;
    }

    for (int i=1; i<10; i++)
        C[i] += C[i-1];

    int *output = new int[n];
    for (int i = n - 1; i >= 0; i--) {
        int index = (arr[i]/exp)%10;
        output[C[index]-1] = arr[i];
        C[index]--;
    }

    for (int i=0; i<n; i++)
        arr[i] = output[i];
}

void radixsort (int arr [], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];

    int digit = 1;
    while (max / digit > 0) {
        countingSort(arr, n, digit);
        digit *= 10;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {170, 45, 75, 90, 802,      
24, 2, 66};
    int n = 
sizeof(arr)/sizeof(arr[0]);
    
radixsort(arr, n);
    printArray(arr, n);
    return 0;
}