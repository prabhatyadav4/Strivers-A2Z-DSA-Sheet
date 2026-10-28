/*
128. Longest Consecutive Sequence

Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

Example 1:
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Example 2:
Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

Example 3:
Input: nums = [1,0,1,2]
Output: 3


Constraints:
0 <= nums.length <= 105
-109 <= nums[i] <= 109
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

int BruteLongestConsecutive(vector<int> &nums)
{
    int n = nums.size();
    int longest = 0;

    for (int i = 0; i < n; i++)
    {
        int current = nums[i];
        int count = 1;

        while (true)
        {
            bool found = false;

            for (int j = 0; j < n; j++)
            {
                if (nums[j] == current + 1)
                {
                    current++;
                    count++;
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                break;
            }
        }

        longest = max(longest, count);
    }

    return longest;
}

int BetterLongestConsecutive(vector<int> &nums)
{
    if (nums.empty())
    {
        return 0;
    }

    sort(nums.begin(), nums.end());

    int res = 1;
    int cnt = 1;

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] == nums[i - 1])
        {
            continue;
        }

        if (nums[i] == nums[i - 1] + 1)
        {
            cnt++;
        }
        else
        {
            cnt = 1;
        }

        res = max(res, cnt);
    }

    return res;
}

int OptimalLongestConsecutive(vector<int> &nums)
{
    unordered_set<int> st(nums.begin(), nums.end());
    int longest = 0;

    for (auto x : st)
    {
        if (st.find(x - 1) == st.end())
        {
            int cnt = 1;
            int curr = x;

            while (st.find(curr + 1) != st.end())
            {
                curr++;
                cnt++;
            }

            longest = max(longest, cnt);
        }
    }

    return longest;
}

int main()
{
    vector<int> nums1 = {100, 4, 200, 1, 3, 2};

    cout << "BRUTE: Longest consecutive sequence: "
         << BruteLongestConsecutive(nums1) << '\n';

    cout << "BETTER: Longest consecutive sequence: "
         << BetterLongestConsecutive(nums1) << '\n';

    cout << "OPTIMAL: Longest consecutive sequence: "
         << OptimalLongestConsecutive(nums1) << '\n';

    return 0;
}