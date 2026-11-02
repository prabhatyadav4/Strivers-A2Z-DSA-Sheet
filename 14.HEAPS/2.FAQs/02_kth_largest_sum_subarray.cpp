/*
K-th Largest Sum Contiguous Subarray

Given an array arr[] of size n, find the sum of the K-th largest sum among all contiguous subarrays. In other words, identify the K-th largest sum from all possible subarrays and return it.

Examples:

Input: arr[] = [3, 2, 1], k = 2
Output: 5
Explanation: The different subarray sums we can get from the array are = [6, 5, 3, 2, 1]. Where 5 is the 2nd largest.

Input: arr[] = [2, 6, 4, 1], k = 3
Output: 11
Explanation: The different subarray sums we can get from the arrayare = [13, 12, 11, 10, 8, 6, 5, 4, 2, 1]. Where 11 is the 3rd largest.

Constraints:
1 ≤ arr.size() ≤ 103
-105 ≤ arr[i] ≤ 105
1 ≤ k ≤ (arr.size()*(arr.size()+1))/2
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int BruteKthLargest(vector<int> &arr, int k)
{
    int n = arr.size();

    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;

        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            ans.push_back(sum);
        }
    }

    sort(ans.begin(), ans.end(), greater<int>());

    return ans[k - 1];
}

int OptimalKthLargest(vector<int> &arr, int k)
{
    int n = arr.size();

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;

        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            pq.push(sum);

            if (pq.size() > k)
            {
                pq.pop();
            }
        }
    }

    return pq.top();
}

int main()
{
    vector<int> arr = {2, 6, 4, 1};
    int k = 3;

    cout << "BRUTE: The sum of the K-th largest sum of subarray is: " << BruteKthLargest(arr, k) << endl;
    cout << "OPTIMAL: The sum of the K-th largest sum of subarray is: " << OptimalKthLargest(arr, k) << endl;

    return 0;
}