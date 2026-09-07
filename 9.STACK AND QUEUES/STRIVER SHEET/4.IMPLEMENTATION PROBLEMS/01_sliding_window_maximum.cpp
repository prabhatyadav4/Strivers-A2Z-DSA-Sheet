/*
239. Sliding Window Maximum

You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation:
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

Example 2:

Input: nums = [1], k = 1
Output: [1]

Constraints:
1 <= nums.length <= 105
-104 <= nums[i] <= 104
1 <= k <= nums.length
*/

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> BruteMaxSlidingWindow(vector<int> &nums, int k)
{
    vector<int> result;

    for (int i = 0; i <= nums.size() - k; i++)
    {
        int maxValue = nums[i];

        for (int j = i; j < i + k; j++)
        {
            maxValue = max(maxValue, nums[j]);
        }

        result.push_back(maxValue);
    }

    return result;
}

vector<int> OptimalMaxSlidingWindow(vector<int> &nums, int k)
{
    deque<int> dq;
    vector<int> result;

    for (int i = 0; i < nums.size(); i++)
    {
        if (!dq.empty() && dq.front() <= i - k)
        {
            dq.pop_front();
        }

        while (!dq.empty() && nums[dq.back()] < nums[i])
        {
            dq.pop_back();
        }

        dq.push_back(i);

        if (i >= k - 1)
        {
            result.push_back(nums[dq.front()]);
        }
    }

    return result;
}

int main()
{
    vector<int> arr = {4, 0, -1, 3, 5, 3, 6, 8};
    int k = 3;

    vector<int> ans1 = BruteMaxSlidingWindow(arr, k);

    for (int num : ans1)
    {
        cout << num << " ";
    }

    cout << endl;
    
    vector<int> ans2 = OptimalMaxSlidingWindow(arr, k);

    for (int num : ans2)
    {
        cout << num << " ";
    }

    return 0;
}