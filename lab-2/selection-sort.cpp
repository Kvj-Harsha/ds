//CS23B1034
//K V Jaya Harsha
#include <iostream>
using namespace std;
int selectionsort(char arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int min = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min]) { 
                min = j;
            }
        }
        char temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
    return 0;
}
int main() {
    cout << "Enter the size of array: ";
    int size;
    cin >> size;
    char arr[size];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    cout << "The array before sorting: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    selectionsort(arr, size);
    cout << "The array after sorting: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
