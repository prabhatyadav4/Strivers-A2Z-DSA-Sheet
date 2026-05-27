/*
39. Combination Sum

Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.



Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.

Example 2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]

Example 3:

Input: candidates = [2], target = 1
Output: []


Constraints:
1 <= candidates.length <= 30
2 <= candidates[i] <= 40
All elements of candidates are distinct.
1 <= target <= 40
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(int i, int target, vector<int> &curr, vector<int> &candidates, vector<vector<int>> &ans)
{
    if (i == candidates.size())
    {
        if (target == 0)
        {
            ans.push_back(curr);
        }
        return;
    }

    if (candidates[i] <= target)
    {
        curr.push_back(candidates[i]);
        solve(i, target - candidates[i], curr, candidates, ans);
        curr.pop_back();
    }

    solve(i + 1, target, curr, candidates, ans);
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> curr;
    int i = 0;

    solve(i, target, curr, candidates, ans);

    return ans;
}

int main()
{
    vector<int> arr = {2, 3, 5};
    int target = 8;

    vector<vector<int>> res = combinationSum(arr, target);

    cout << "Combinations are: " << endl;
    for (int i = 0; i < res.size(); i++)
    {
        cout << "[ ";

        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }

        cout << "]\n";
    }

    return 0;
}