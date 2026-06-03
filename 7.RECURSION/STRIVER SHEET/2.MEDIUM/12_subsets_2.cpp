/*
90. Subsets II

Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:
Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

Example 2:
Input: nums = [0]
Output: [[],[0]]


Constraints:
1 <= nums.length <= 10
-10 <= nums[i] <= 10
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(int i, vector<int> &nums, vector<int> &subsets, vector<vector<int>> &res)
{
    if (i == nums.size())
    {
        res.push_back(subsets);
        return;
    }

    subsets.push_back(nums[i]);
    solve(i + 1, nums, subsets, res);
    subsets.pop_back();

    int index = i + 1;
    while (index < nums.size() && nums[index] == nums[index - 1])
        index++;
    solve(index, nums, subsets, res);
}

vector<vector<int>> subsetsII(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    vector<int> subsets;

    solve(0, nums, subsets, res);

    return res;
}

int main()
{
    vector<int> nums = {1, 2, 2};

    vector<vector<int>> res = subsetsII(nums);

    cout << "All possible subsets of nums are: ";

    for (int i = 0; i < res.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j];
            if (j != res[i].size() - 1)
                cout << ", ";
        }
        cout << "]" << ",";
    }

    return 0;
}