/*
743. Check if the Array is Sorted I

Basic

Given an array arr of size n, the task is to check if the given array is sorted in (ascending / Increasing / Non-decreasing) order. If the array is sorted then return True, else return False.

Example 1:
Input: n = 5, arr = [1,2,3,4,5]

Output: True

Explanation: The given array is sorted i.e Every element in the array is smaller than or equals to its next values, So the answer is True.

Example 2:
Input: n = 5, arr = [5,4,6,7,8]

Output: False

Explanation: The given array is Not sorted i.e Every element in the array is not smaller than or equal to its next values, So the answer is False. Here element 5 is not smaller than or equal to its future elements.

Constraints:
1 ≤ n ≤ 106
- 109 ≤ arr[i] ≤ 109
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool arraySortedOrNotI(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            return false;
        }
    }
    return true;
}

bool arraySortedOrNotII(vector<int> arr)
{
    return is_sorted(arr.begin(), arr.end());
}

int main()
{
    int arr1[] = {1, 2, 3, 4, 5};
    int n1 = 5;

    vector<int> arr2 = {5, 4, 6, 7, 8};

    cout << "arraySortedOrNotI: " << (arraySortedOrNotI(arr1, n1) ? "True" : "False") << endl;
    cout << "arraySortedOrNotII: " << (arraySortedOrNotII(arr2) ? "True" : "False") << endl;

    return 0;
}