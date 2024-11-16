//K V Jaya Harsha
//CS23B1034
#include<iostream>
using namespace std;
int linear(int arr[], int target, int size){
    int codi=-1;
    for (int i = 0; i < size-1; i++)
    {
        if (arr[i]==target)
        {
            codi = i;
        }
    }
    if (codi!=-1)
    {
        cout << "Element if found at " << codi+1 << " position!";
    }
    else{
        cout << "Element not found!";
    }
}
int main(){
    int k;
    cout << "Enter the size of the array: ";
    cin >> k;
    int arr[k];
    cout << endl;
    cout << "Enter the elements in the array: ";
    for (int i = 0; i < k; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter the target element!: ";
    int key;
    cin >> key;
    linear(arr,key,k);
    return 0;
}
