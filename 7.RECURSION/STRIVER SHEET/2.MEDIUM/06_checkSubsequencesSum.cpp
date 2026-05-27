/*
Check if there exists a subsequence with sum K

Given an array nums and an integer k. Return true if there exist subsequences such that the sum of all elements in subsequences is equal to k else false.

Example 1

Input : nums = [1, 2, 3, 4, 5] , k = 8
Output : Yes
Explanation : The subsequences like [1, 2, 5] , [1, 3, 4] , [3, 5] sum up to 8.

Example 2

Input : nums = [4, 3, 9, 2] , k = 10
Output : No
Explanation : No subsequence can sum up to 10.

Constraints
1 <= nums.length <= 20
1 <= nums[i] <= 100
1 <= k <= 2000
*/

#include <iostream>
#include <vector>
using namespace std;

bool helper(int i, int sum, vector<int> &nums)
{
    if (i == nums.size())
    {
        return sum == 0;
    }

    return helper(i + 1, sum - nums[i], nums) + helper(i + 1, sum, nums);
}

bool checkSubsequenceSum(vector<int> &nums, int target)
{
    return helper(0, target, nums);
}

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    int target = 5;
    
    checkSubsequenceSum(nums, target) ? cout << "YES" : cout << "NO";

    return 0;
}