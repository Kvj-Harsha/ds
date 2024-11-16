#include<iostream>
using namespace std;

int main(){
    int x[10] = {1,2,3,4,5,6,7,8,9,10};
    int key = 6;
    for (int i = 0; i < 10; i++)
    {
        if (x[i]==key)
        {
            cout << "Element found at " << i << "th index and " << i+1 << "th position. " << endl;
            break;
        } 
    } 
    return 0;
}