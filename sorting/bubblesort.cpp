#include<iostream>
using namespace std;

int main(){
    int x[6] = {2,9,1,6,12,5};
    cout << "before sorting" << endl;
    for (int i = 0; i < 6; i++)
    {
        cout << x[i] << " ";
    }
    
    for (int i = 0; i < 6-1; i++)
    {
        for (int j = 0; j < 6-i; j++)
        {
            if (x[j]>x[j+1])
            {
                int temp = x[j];
                x[j] = x[j+1];
                x[j+1] = temp;
            }
        }
    }
    cout << "after sorting" << endl;
    for (int i = 0; i < 6; i++)
    {
        cout << x[i] << " ";
    }
    
    
    return 0;
}