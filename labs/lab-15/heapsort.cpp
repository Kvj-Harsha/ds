//K V Jaya Harsha
//CS23B1034
#include <iostream>
using namespace std;
void heapify(char arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
void heapSort(char arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
int main() {
    char arr[10] = {'k', 'v', 'j', 'h', 'a', 'r', 's', 'h', 'a', 'b'};
    int n = 10;
   cout << "Before sorting: ";
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    heapSort(arr, n);
    cout << "\nAfter sorting: ";
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}



