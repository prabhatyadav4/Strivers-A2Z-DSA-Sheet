/*
992. Subarrays with K Different Integers

Given an integer array nums and an integer k, return the number of good subarrays of nums.

A good array is an array where the number of different integers in that array is exactly k.

For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.

Example 1:
Input: nums = [1,2,1,2,3], k = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]

Example 2:
Input: nums = [1,2,1,3,4], k = 3
Output: 3
Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].


Constraints:
1 <= nums.length <= 2 * 104
1 <= nums[i], k <= nums.length
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int countDistinct(vector<int> &nums, int start, int end)
{
    int n = nums.size();

    unordered_set<int> st;

    for (int i = start; i <= end; i++)
    {
        st.insert(nums[i]);
    }

    return st.size();
}

int BruteSubarraysWithKDistinct(vector<int> &nums, int k)
{
    int n = nums.size();

    if (n == 0 || k <= 0)
    {
        return 0;
    }

    int count = 0;

    for (int i = 0; i < n; i++)
    {

        for (int j = i; j < n; j++)
        {
            int distinctCount = countDistinct(nums, i, j);

            if (distinctCount == k)
            {
                count++;
            }
        }
    }

    return count;
}

int BetterSubarraysWithKDistinct(vector<int> &nums, int k)
{
    int n = nums.size();

    if (n == 0 || k <= 0)
    {
        return 0;
    }

    int count = 0;

    for (int i = 0; i < n; i++)
    {

        unordered_map<int, int> freq;

        for (int j = i; j < n; j++)
        {

            freq[nums[j]]++;

            if (freq.size() == k)
            {
                count++;
            }

            if (freq.size() > k)
            {
                break;
            }
        }
    }

    return count;
}

int atMostK(vector<int> &nums, int k)
{
    int n = nums.size();

    if (n == 0 || k <= 0)
    {
        return 0;
    }

    unordered_map<int, int> freq;

    int l = 0, r = 0, count = 0;

    while (r < n)
    {
        freq[nums[r]]++;

        while (freq.size() > k)
        {
            freq[nums[l]]--;

            if (freq[nums[l]] == 0)
            {
                freq.erase(nums[l]);
            }

            l++;
        }

        if (freq.size() <= k)
        {
            count += r - l + 1;
        }

        r++;
    }

    return count;
}

int OptimalSubarraysWithKDistinct(vector<int> &nums, int k)
{
    return atMostK(nums, k) - atMostK(nums, k - 1);
}

int main()
{
    vector<int> nums = {1, 2, 1, 2, 3};
    int k = 2;

    int ans1 = BruteSubarraysWithKDistinct(nums, k);
    cout << "BRUTE: The number of good subarrays are: " << ans1 << endl;

    int ans2 = BetterSubarraysWithKDistinct(nums, k);
    cout << "BETTER: The number of good subarrays are: " << ans2 << endl;

    int ans3 = OptimalSubarraysWithKDistinct(nums, k);
    cout << "OPTIMAL: The number of good subarrays are: " << ans3 << endl;

    return 0;
}