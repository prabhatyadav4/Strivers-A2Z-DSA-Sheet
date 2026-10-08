/*
45. Jump Game II

You are given a 0-indexed array of integers nums of length n. You are initially positioned at index 0.

Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at index i, you can jump to any index (i + j) where:

0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach index n - 1. The test cases are generated such that you can reach index n - 1.



Example 1:
Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:
Input: nums = [2,3,0,1,4]
Output: 2


Constraints:
1 <= nums.length <= 104
0 <= nums[i] <= 1000
It's guaranteed that you can reach nums[n - 1].
*/

#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> &nums, int index)
{
    // Base Case
    if (index >= nums.size() - 1)
    {
        return 0;
    }

    int minJumps = INT_MAX;

    for (int jump = 1; jump <= nums[index]; jump++)
    {
        int nextIndex = index + jump;

        if (nextIndex < nums.size())
        {
            int jumps = solve(nums, nextIndex);
            minJumps = min(minJumps, 1 + jumps);
        }
    }

    return minJumps;
}

int BruteJump(vector<int> &nums)
{
    return solve(nums, 0);
}

int OptimalJump(vector<int> &nums)
{
    int n = nums.size();

    int jumps = 0;
    int l = 0;
    int r = 0;

    while (r < n - 1)
    {
        int farthest = 0;

        for (int i = l; i <= r; i++)
        {
            farthest = max(farthest, i + nums[i]);
        }

        l = r + 1;
        r = farthest;
        jumps++;
    }

    return jumps;
}

int main()
{
    vector<int> nums = {2, 3, 1, 1, 4};

    int ans1 = BruteJump(nums);
    cout << "BRUTE: The minimum number of jumps are: " << ans1 << endl;

    int ans2 = OptimalJump(nums);
    cout << "OPTIMAL: The minimum number of jumps are: " << ans2 << endl;

    return 0;
}