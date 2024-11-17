#include <iostream>
#include <algorithm>
using namespace std;

int mostFrequent(int arr[], int n)
{
    // Sort the array
    sort(arr, arr + n);

    // Find the max frequency using linear traversal
    int max_count = 1, res = arr[0], curr_count = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1])
            curr_count++;
        else
            curr_count = 1;
        
        if (curr_count > max_count) {
            max_count = curr_count;
            res = arr[i];
        }
    }

    return res;
}

// Driver program
int main()
{
    int arr[] = { 40, 50, 30, 40, 50, 30, 30 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Most Frequent Element: " << mostFrequent(arr, n) << endl;
    return 0;
}
