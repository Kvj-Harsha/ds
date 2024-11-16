//K V Jaya Harsha
//CS23B1034
#include<iostream>
using namespace std;
int binary(int begin, int end, int target, int arr[]){
    while (begin<=end){
        int mid;
        mid = (begin+end)/2;
        if (target==arr[mid]){
            return mid;
        }
        if (mid>target){
            end=mid-1;
        }
        else{
            begin=mid+1;
        }
    }   
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
    cout << "Enter the target element!: ";
    int key;
    cin >> key;
    cout << "Element found at index = " << binary(0,k-1,key,arr);
    return 0;
}

