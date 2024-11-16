//K V Jaya Harsha
//CS23B1034
#include <iostream>
#include <vector>
using namespace std;
char findMax(const vector<char>& arr){
    char maxElement = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > maxElement) {
            maxElement = arr[i];
        }
    }
    return maxElement;
}
void countSort(vector<char>& arr) {
    char maxChar = findMax(arr);
    int maxElement = maxChar;
    vector<int> count(maxElement + 1, 0);
    for (int i = 0; i < arr.size(); i++) {
        count[arr[i]]++;
    }
    for (int i = 1; i <= maxElement; i++) {
        count[i] += count[i - 1];
    }
    vector<char> output(arr.size());
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = output[i];
    }
}
void radixsort(vector<char>& arr){
    for (int i = 0; i < arr.size(); i++) {
        countSort(arr);
    }
}
int main() {
    vector<char> arr = {'k', 'v', 'j', 'h', 'a', 'r', 's', 'h', 'a', 'b'};
    cout << "Original array: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    radixsort(arr);
    cout << "Sorted array: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}


