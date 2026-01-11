/*
Two Sum

Given an array of integers nums and an integer target. Return the indices(0 - indexed) of two elements in nums such that they add up to target.

Each input will have exactly one solution, and the same element cannot be used twice. Return the answer in increasing order.

Example 1

Input: nums = [1, 6, 2, 10, 3], target = 7

Output: [0, 1]

Explanation:

nums[0] + nums[1] = 1 + 6 = 7

Example 2

Input: nums = [1, 3, 5, -7, 6, -3], target = 0

Output: [1, 5]

Explanation:

nums[1] + nums[5] = 3 + (-3) = 0
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> BruteTwoSum(vector<int> &nums, int target)
    {
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    return {i, j};
                }
            }
        }
        return {};
    }

    vector<pair<int, int>> BetterTwoSum(vector<int> &nums, int target)
    {
        vector<pair<int, int>> ans;
        sort(nums.begin(), nums.end());

        int left = 0, right = nums.size() - 1;

        while (left < right)
        {
            int sum = nums[left] + nums[right];

            if (sum == target)
            {
                ans.push_back({nums[left], nums[right]});
                left++;
                right--;
            }
            else if (sum < target)
                left++;
            else
                right--;
        }

        if (ans.empty())
            ans.push_back({-1, -1});

        return ans;
    }

    vector<int> OptimalTwoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++)
        {
            int second = target - nums[i];

            if (mp.find(second) != mp.end())
                return {mp[second], i};

            mp[nums[i]] = i;
        }
        return {};
    }
};

int main()
{
    Solution obj;

    vector<int> nums = {1, 6, 2, 10, 3};
    int target = 7;

    // Brute Force
    vector<int> brute = obj.BruteTwoSum(nums, target);
    cout << "Brute Output: ";
    if (!brute.empty())
        cout << brute[0] << " " << brute[1] << endl;
    else
        cout << "No Pair\n";

    // Better (Two Pointer - values)
    vector<pair<int, int>> better = obj.BetterTwoSum(nums, target);
    cout << "Better Output: "; 
    for (auto p : better)
        cout << p.first << " " << p.second << endl;

    // Optimal (Hash Map)
    vector<int> optimal = obj.OptimalTwoSum(nums, target);
    cout << "Optimal Output: ";
    if (!optimal.empty())
        cout << optimal[0] << " " << optimal[1] << endl;
    else
        cout << "No Pair\n";

    return 0;
}
