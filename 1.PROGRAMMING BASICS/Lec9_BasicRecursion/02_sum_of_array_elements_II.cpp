/*
897. Sum of Array Elements II

Given an array nums, find the sum of elements of array using recursion.

Example 1:
Input : nums = [1, 2, 3]

Output : 6

Explanation : The sum of elements of array is 1 + 2 + 3 => 6.

Example 2:
Input : nums = [5, 8, 1]

Output : 14

Explanation : The sum of elements of array is 5 + 8 + 1 => 14.

Constraints:
1 <= n <= 100
0 <= nums[i] <= 100
*/

#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> &nums, int index)
{
    if (index == nums.size())
    {
        return 0;
    }

    return nums[index] + solve(nums, index + 1);
}

int arraySum(vector<int> &nums)
{
    return solve(nums, 0);
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};

    cout << "The sum of elements of array are: " << arraySum(nums);

    return 0;
}