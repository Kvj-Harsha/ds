//CS23B1034
//K V Jaya Harsha
#include<iostream>
using namespace std;
int selection(char arr[],int size){
    for (int i = 1; i < size; i++){
        int temp = arr[i];
        int j = i-1;
        while (j>=0 && arr[j]>temp){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=temp;
    }
    return 0;
}
int main(){
    cout << "Enter the size of array: ";
    int size;
    cin >> size;
    char arr[size];
    cout << "Enter the elements in the array! "<< endl;
    for (int i = 0; i < size; i++){
        cin >> arr[i];
    }
    cout << "Before sorting!" << endl;
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    selection(arr,size);
    cout << "After sorting!" << endl;
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }    
    return 0;
}
