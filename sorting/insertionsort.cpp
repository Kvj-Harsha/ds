#include<iostream>
using namespace std;

int main(){
    int x[10] = {234,4,78,6,2342,468,232,4,212,1};
    for (int i = 0; i < 10-1; i++)
    {
        int min = i;

        for (int j = i + 1; j < 10; j++)
        {
            if (x[j]<x[min])
            {
                min = j;
            }
        }

        int temp = x[i];
        x[i] = x[min];
        x[min] = temp;
    } 

    for (int i = 0; i < 10; i++)
    {
        cout << x[i] << " ";
    }
    
    return 0;
}