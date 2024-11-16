//CS23B1034
//K V Jaya Harsha
#include <iostream>
using namespace std;
int main() {

    char arr1[]={'e','q','r','t','w'};
    char arr2[]={'b','c','v','x'};

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int size3 = size1 + size2;
    char arr[size3]; 

    int i = 0, j = 0, k = 0;
    while (i < size1 && j < size2) {
        if (arr1[i] <= arr2[j]) {
            arr[k] = arr1[i];
            i++;
        } 
        else {
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }

     while (i < size1) {
        arr[k] = arr1[i];
        i++;
        k++;
    }

    while (j < size2) {
        arr[k] = arr2[j];
        j++;
        k++;
    }

    cout << "Sorted Array: ";
    for (int i = 0; i < size3; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}

