//K V Jaya Harsha
//CS23B1034
#include<iostream>
using namespace std;
int bubble(int arr[],int size){
    for (int i = 0; i < size-1; i++){
        for (int j = 0; j < size-i-1; j++){
            if (arr[j]>arr[j+1]){
                int temp;
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    return 0;
}
int main(){
    int k;
    cout << "Enter the size of the array: ";
    cin >> k;
    int arr[k];
    cout << endl;
    cout << "Enter the elements in the array: ";
    for (int i = 0; i < k; i++){
        cin >> arr[i];
    }
    cout << "Array before sorting!: ";
    for (int i = 0; i < k; i++){
        cout << arr[i] << " ";
    }
    bubble(arr,k);
    cout << endl;
    cout << "Array after sorting!: ";
    for (int i = 0; i < k; i++){
        cout << arr[i] << " ";
    }
    return 0;
}

