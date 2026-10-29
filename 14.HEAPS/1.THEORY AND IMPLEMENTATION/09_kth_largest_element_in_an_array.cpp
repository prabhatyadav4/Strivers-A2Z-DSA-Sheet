/*
215. Kth Largest Element in an Array

Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?

Example 1:
Input: nums = [3,2,1,5,6,4], k = 2
Output: 5

Example 2:
Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4


Constraints:
1 <= k <= nums.length <= 105
-104 <= nums[i] <= 104
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int BruteKthLargestElement(const vector<int> &arr, int k)
{
    vector<int> sortedArr = arr;
    sort(sortedArr.begin(), sortedArr.end(), greater<int>());

    return sortedArr[k - 1];
}

int OptimalKthLargestElement(const vector<int> &arr, int k)
{
    int n = arr.size();

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);

        if (pq.size() > k)
        {
            pq.pop();
        }
    }

    return pq.top();
}

int main()
{
    vector<int> arr = {12, 3, 5, 7, 19};
    int k = 3;

    cout << "BRUTE: The Kth Largest element in the array is: " << BruteKthLargestElement(arr, k) << endl;
    cout << "OPTIMAL: The Kth Largest element in the array is: " << OptimalKthLargestElement(arr, k) << endl;

    return 0;
}
