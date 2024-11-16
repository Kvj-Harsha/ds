#include<iostream>
using namespace std;

int main(){
    int x[10] = {234,4,78,6,2342,468,232,4,212,1};
    for (int i = 1; i < 10; i++)
    {
        int j = i;

        while (j>0 && x[j-1]>x[j])
        {
            int temp  = x[j];
            x[j] = x[j-1];
            x[j-1] = temp;
            j--;
        }
        
    } 

    for (int i = 0; i < 10; i++)
    {
        cout << x[i] << " ";
    }
    
    return 0;
}