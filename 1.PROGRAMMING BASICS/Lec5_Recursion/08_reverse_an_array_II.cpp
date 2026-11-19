/*
821. Reverse an array 2

Given an array nums of n integers, return reverse of the array.

Example 1:
Input : nums = [1, 2, 3, 4, 5]
Output : [5, 4, 3, 2, 1]

Example 2:
Input : nums = [1, 3, 3, 3, 5]
Output : [5, 3, 3, 3, 1]

Constraints:
1 <= n <= 100
1 <= nums[i] <= 100
*/

#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int> &nums, int left, int right)
{
    if (left >= right)
    {
        return;
    }

    swap(nums[left], nums[right]);

    solve(nums, left + 1, right - 1);
}

vector<int> reverseArray(vector<int> &nums)
{
    solve(nums, 0, nums.size() - 1);

    return nums;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};

    cout << "The reverse of an array is: ";

    for (int num : reverseArray(nums))
    {
        cout << num << " ";
    }

    return 0;
}