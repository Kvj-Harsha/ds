#include <iostream>
using namespace std;

void merge(char arr[], int beg, int mid, int end) {
    int i = beg, j = mid + 1;
    int index = 0;
    char temp[end - beg + 1];

    // Merging the two halves
    while (i <= mid && j <= end) {
        if (arr[i] < arr[j]) {
            temp[index++] = arr[i++];
        } else {
            temp[index++] = arr[j++];
        }
    }

    // Copy remaining elements of the left half, if any
    while (i <= mid) {
        temp[index++] = arr[i++];
    }

    // Copy remaining elements of the right half, if any
    while (j <= end) {
        temp[index++] = arr[j++];
    }

    // Copy temp array back to arr
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
