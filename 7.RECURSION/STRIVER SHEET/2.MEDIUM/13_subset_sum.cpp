/*
Subset Sum : Sum of all Subsets

Problem Statement: Given an array print all the sum of the subset generated from it, in the increasing order.

Examples
Input: N = 3, arr[] = {5,2,1}
Output: 0,1,2,3,5,6,7,8
Explanation: We have to find all the subset’s sum and print them.in this case the generated subsets are [ [], [1], [2], [2,1], [5], [5,1], [5,2]. [5,2,1],so the sums we get will be  0,1,2,3,5,6,7,8

Input: N=3,arr[]= {3,1,2}
Output: 0,1,2,3,3,4,5,6
Explanation: We have to find all the subset’s sum and print them.in this case the generated subsets are [ [], [1], [2], [2,1], [3], [3,1], [3,2]. [3,2,1],so the sums we get will be  0,1,2,3,3,4,5,6
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(int i, int sum, vector<int> &nums, vector<int> &res)
{
    if (i == nums.size())
    {
        res.push_back(sum);
        return;
    }

    solve(i + 1, sum + nums[i], nums, res);
    solve(i + 1, sum, nums, res);
}

vector<int> subsetSums(vector<int> &nums)
{
    vector<int> res;

    solve(0, 0, nums, res);

    sort(res.begin(), res.end());

    return res;
}

int main()
{
    vector<int> arr = {3, 1, 2};

    vector<int> result = subsetSums(arr);

    cout << "The sum of the subset are: ";

    for (int sum : result)
    {
        cout << sum << " ";
    }
    cout << endl;

    return 0;
}