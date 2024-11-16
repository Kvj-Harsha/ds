//K V Jaya Harsha
//CS23B1034
#include <iostream>
using namespace std;
void merge(char arr[], int beg, int mid, int end) {
    int i = beg, j = mid + 1;
    int index = 0;
    char temp[end - beg + 1];
    while (i <= mid && j <= end) {
        if (arr[i] < arr[j]) {
            temp[index] = arr[i];
            i++;
        } else {
            temp[index] = arr[j];
            j++;
        }
        index++;
    }
    while (i <= mid) {
        temp[index] = arr[i];
        i++;
        index++;
    }
    while (j <= end) {
        temp[index] = arr[j];
        j++;
        index++;
    }
    for (int k = 0; k < index; k++) {
        arr[beg + k] = temp[k];
    }
}
void merge_sort(char arr[], int beg, int end) {
    if (beg < end) {
        int mid = (beg + end) / 2;
        merge_sort(arr, beg, mid);
        merge_sort(arr, mid + 1, end);
        merge(arr, beg, mid, end);
    }
}
int main() {
    char sdtarray[10]={'c','a','l','m','e','k','v','j','b','y'};
    merge_sort(sdtarray, 0, 9);
    cout << "Sorted characters: ";
    for (int i = 0; i < 10; i++) {
        cout << sdtarray[i] << " ";
    }
    cout << endl;
    return 0;
}


