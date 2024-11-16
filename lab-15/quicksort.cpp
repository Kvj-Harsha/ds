//K V Jaya Harsha
//CS23B1034
#include <iostream>
using namespace std;
void swap(char &a, char &b) {
    char temp = a;
    a = b;
    b = temp;
}
int partition(char arr[], int low, int high) {
    char pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}
void quickSort(char arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
int main() {
    char arr[10] = {'k', 'v', 'j', 'h', 'a', 'r', 's', 'h', 'a', 'b'};
    int n = 10;
    cout << "Before sorting: ";
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    quickSort(arr, 0, n - 1);
    cout << "\nAfter sorting: ";
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}


