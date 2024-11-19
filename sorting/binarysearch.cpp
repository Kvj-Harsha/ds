#include <iostream>
using namespace std;

int main()
{
    int x[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int key = 6;
    int start = 0;
    int end = 9;
    bool found = false;

    while (start <= end){
        int mid = (start + end) / 2;
        if (key == x[mid])
        {
            cout << "element found at index = " << mid;
            found = true;
            break;
        }

        else if (key > x[mid])
        {
            start = mid + 1;
        }

        else
        {
            end = mid - 1;
        }
    }

    if (!found)
    {
        cout << "Element Not Found!";
    }
    return 0;
}