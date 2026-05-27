/*
Count all subsequences with sum K

Given an array nums and an integer k.Return the number of non-empty subsequences of nums such that the sum of all elements in the subsequence is equal to k.


Example 1

Input : nums = [4, 9, 2, 5, 1] , k = 10
Output : 2
Explanation : The possible subsets with sum k are [9, 1] , [4, 5, 1].

Example 2

Input : nums = [4, 2, 10, 5, 1, 3] , k = 5
Output : 3
Explanation : The possible subsets with sum k are [4, 1] , [2, 3] , [5].

Constraints
1 <= nums.length <= 20
1 <= nums[i] <= 100
1 <= k <= 2000
*/

#include <iostream>
#include <vector>

using namespace std;

int helper(int i, int sum, vector<int> &nums)
{
    if (sum == 0)
        return 1;
    if (sum < 0 || i == nums.size())
        return 0;

    return helper(i + 1, sum - nums[i], nums) + helper(i + 1, sum, nums);
}

int countSubsequenceWithTargetSum(vector<int> &nums, int k)
{
    return helper(0, k, nums);
}

int main()
{
    vector<int> nums = {4, 9, 2, 5, 1};
    int target = 10;
    cout << "Number of subsequences with target sum " << target << ": "
         << countSubsequenceWithTargetSum(nums, target) << endl;

    return 0;
}