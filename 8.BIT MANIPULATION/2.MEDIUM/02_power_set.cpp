/*
78. Subsets

Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Example 2:

Input: nums = [0]
Output: [[],[0]]


Constraints:
1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> getPowerSet(vector<int> &nums)
{
    int n = nums.size();

    int subset = (1 << n);

    vector<vector<int>> ans;

    for (int i = 0; i < subset; i++)
    {

        vector<int> subsets;

        for (int j = 0; j < n; j++)
        {

            if (i & (1 << j))
            {
                subsets.push_back(nums[j]);
            }
        }

        ans.push_back(subsets);
    }

    return ans;
}

int main()
{
    vector<int> nums = {5, 7, 8};

    vector<vector<int>> subsets = getPowerSet(nums);

    // Print original input array
    cout << "Initial Input Array: ";
    for (auto num : nums)
    {
        cout << num << " ";
    }
    cout << endl;

    // Print all subsets
    cout << "Subsets: " << endl;
    for (auto subset : subsets)
    {
        cout << "[ ";
        for (auto num : subset)
        {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}