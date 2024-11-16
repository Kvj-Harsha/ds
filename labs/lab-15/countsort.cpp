#include <iostream>
#include <vector>
using namespace std;

int findMax(const vector<int> &arr)
{
    int maxElement = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] > maxElement)
        {
            maxElement = arr[i];
        }
    }
    return maxElement;
}

void countSort(vector<int> &arr)
{

    int maxElement = findMax(arr);

    vector<int> count(maxElement + 1, 0);

    for (int num : arr)
    {
        count[num]++;
    }

    for (int i = 1; i <= maxElement; i++)
    {
        count[i] += count[i - 1];
    }

    vector<int> output(arr.size());

    for (int i = arr.size() - 1; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    arr = output;
}

int main()
{
    vector<int> arr = {4, 2, 2, 8, 3, 3, 1};

    cout << "Original array: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    countSort(arr);

    cout << "Sorted array: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
