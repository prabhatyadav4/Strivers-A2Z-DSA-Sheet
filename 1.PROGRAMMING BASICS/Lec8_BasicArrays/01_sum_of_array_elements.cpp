/*
886. Sum of Array Elements

Given an array arr of size n, the task is to find the sum of all the elements in the array.

Example 1:
Input: n=5, arr = [1,2,3,4,5]

Output: 15

Explanation: Sum of all the elements is 1+2+3+4+5 = 15

Example 2:
Input: n=6, arr = [1,2,1,1,5,1]

Output: 11

Explanation: Sum of all the elements is 1+2+1+1+5+1 = 11

Constraints:
1 <= n <= 105
1 <= arr[i] <= 104
*/

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int sumI(int arr[], int n)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    return sum;
}

int sumII(vector<int> arr, int n)
{
    return accumulate(arr.begin(), arr.end(), 0);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;

    cout << "sumI: " << sumI(arr, n) << endl;

    vector<int> v(arr, arr + n);
    cout << "sumII: " << sumII(v, n) << endl;

    return 0;
}