/*
1004. Max Consecutive Ones III

Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

Example 1:

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
Example 2:

Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.


Constraints:
1 <= nums.length <= 105
nums[i] is either 0 or 1.
0 <= k <= nums.length
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int BruteLongestOnes(vector<int> &nums, int k)
{
    int n = nums.size();
    int maxLen = 0;

    for (int i = 0; i < n; i++)
    {

        int zeros = 0;

        for (int j = i; j < n; j++)
        {
            if (nums[j] == 0)
            {
                zeros++;
            }

            if (zeros > k)
            {
                break;
            }

            maxLen = max(maxLen, j - i + 1);
        }
    }

    return maxLen;
}

int BetterLongestOnes(vector<int> &nums, int k)
{
    int n = nums.size();
    int l = 0, r = 0, maxLen = 0, zeros = 0;

    while (r < n)
    {
        if (nums[r] == 0)
        {
            zeros++;
        }

        while (zeros > k)
        {
            if (nums[l] == 0)
            {
                zeros--;
            }

            l++;
        }

        maxLen = max(maxLen, r - l + 1);

        r++;
    }

    return maxLen;
}

int OptimalLongestOnes(vector<int> &nums, int k)
{
    int n = nums.size();
    int l = 0, r = 0, maxLen = 0, zeros = 0;

    while (r < n)
    {
        if (nums[r] == 0)
        {
            zeros++;
        }

        if (zeros > k)
        {
            if (nums[l] == 0)
            {
                zeros--;
            }

            l++;
        }

        if (zeros <= k)
        {
            maxLen = max(maxLen, r - l + 1);
        }

        r++;
    }

    return maxLen;
}

int main()
{
    vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k = 2;

    int length1 = BruteLongestOnes(nums, k);
    cout << "BRUTE: The maximum number of consecutive 1's is: " << length1 << endl;

    int length2 = BetterLongestOnes(nums, k);
    cout << "BETTER: The maximum number of consecutive 1's is: " << length2 << endl;

    int length3 = OptimalLongestOnes(nums, k);
    cout << "OPTIMAL: The maximum number of consecutive 1's is: " << length3 << endl;

    return 0;
}