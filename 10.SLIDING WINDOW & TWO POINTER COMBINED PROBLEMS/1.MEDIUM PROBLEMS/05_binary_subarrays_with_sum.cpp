/*
930. Binary Subarrays With Sum

Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array.

Example 1:
Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]

Example 2:
Input: nums = [0,0,0,0,0], goal = 0
Output: 15


Constraints:
1 <= nums.length <= 3 * 104
nums[i] is either 0 or 1.
0 <= goal <= nums.length
*/

#include <iostream>
#include <vector>
using namespace std;

int BruteNumsSubarraysWithSum(vector<int> &nums, int goal)
{
    int n = nums.size();
    int count = 0;

    for (int i = 0; i < n; i++)
    {

        for (int j = i; j < n; j++)
        {

            int currentSum = 0;

            for (int k = i; k <= j; k++)
            {
                currentSum += nums[k];
            }

            if (currentSum == goal)
            {
                count++;
            }
        }
    }

    return count;
}

int BetterNumsSubarrayWithSum(vector<int> &nums, int goal)
{
    int n = nums.size();
    int count = 0;

    for (int i = 0; i < n; i++)
    {

        int currentSum = 0;

        for (int j = i; j < n; j++)
        {

            currentSum += nums[j];

            if (currentSum == goal)
            {
                count++;
            }

            if (currentSum > goal)
            {
                break;
            }
        }
    }

    return count;
}

int countAtMost(vector<int> &nums, int goal)
{
    if (goal < 0)
    {
        return 0;
    }

    int n = nums.size();
    int l = 0, r = 0, currentSum = 0, count = 0;

    while (r < n)
    {

        currentSum += nums[r];

        while (currentSum > goal)
        {
            currentSum -= nums[l];
            l++;
        }

        count += r - l + 1;
        r++;
    }

    return count;
}

int OptimalNumsSubarrayWithSum(vector<int> &nums, int goal)
{
    return countAtMost(nums, goal) - countAtMost(nums, goal - 1);
}

int main()
{

    vector<int> nums = {1, 0, 1, 0, 1};
    int goal = 2;

    int ans1 = BruteNumsSubarraysWithSum(nums, goal);
    cout << "BRUTE: The number of subarrays equal to sum are: : " << ans1 << endl;

    int ans2 = BetterNumsSubarrayWithSum(nums, goal);
    cout << "BETTER: The number of subarrays equal to sum are: : " << ans2 << endl;

    int ans3 = OptimalNumsSubarrayWithSum(nums, goal);
    cout << "OPTIMAL: The number of subarrays equal to sum are: : " << ans3 << endl;

    return 0;
}