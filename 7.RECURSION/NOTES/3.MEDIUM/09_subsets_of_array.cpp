/*
Subsets

Given an array arr[] of distinct positive integers, your task is to find all its subsets.

Note: You can return the subsets in any order, the driver code will print them in sorted order.

Examples:
Input: arr[] = [1, 2, 3]
Output: [[], [1], [1, 2], [1, 2, 3], [1, 3], [2], [2, 3], [3]]
Explanation:
The subsets of [1, 2, 3] in lexicographical order are:
[], [1], [1, 2], [1, 2, 3], [1, 3], [2], [2, 3], [3]

Input: arr[] = [2, 4]
Output: [[], [2], [2, 4], [4]]
Explanation:
The subsets of [2, 4] in lexicographical order are:
[], [2], [2, 4], [4]

Constraints :
1 ≤ arr.size() ≤ 10
1 ≤ arr[i] ≤ 103
*/

#include <iostream>
#include <vector>
using namespace std;

void solve(int i, vector<int> &arr, vector<vector<int>> &res, vector<int> &subset)
{
    if (i == arr.size())
    {
        res.push_back(subset);
        return;
    }

    subset.push_back(arr[i]);
    solve(i + 1, arr, res, subset);

    subset.pop_back();
    solve(i + 1, arr, res, subset);
}

vector<vector<int>> subsetsRec(vector<int> &arr)
{
    vector<int> subset;
    vector<vector<int>> res;

    solve(0, arr, res, subset);

    return res;
}

vector<vector<int>> subsetsBit(vector<int> &arr)
{
    int n = arr.size();
    vector<vector<int>> res;

    for (int i = 0; i < (1 << n); i++)
    {
        vector<int> subset;
        for (int j = 0; j < n; j++)
        {
            if ((i & (1 << j)) != 0)
            {
                subset.push_back(arr[j]);
            }
        }

        res.push_back(subset);
    }

    return res;
}

int main()
{
    cout << "Subsets of Array using Recursion: " << endl;
    vector<int> arr1 = {1, 2, 3};
    vector<vector<int>> res1 = subsetsRec(arr1);
    for (int i = 0; i < res1.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < res1[i].size(); j++)
        {
            cout << res1[i][j];
            if (j != res1[i].size() - 1)
                cout << ", ";
        }
        cout << "]" << ",";
    }

    cout << "\nSubsets of Array using Bit Manipulation: " << endl;
    vector<int> arr2 = {2, 4, 6};
    vector<vector<int>> res2 = subsetsBit(arr2);
    for (int i = 0; i < res2.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < res2[i].size(); j++)
        {
            cout << res2[i][j];
            if (j != res2[i].size() - 1)
                cout << ", ";
        }
        cout << "]" << ",";
    }

    return 0;
}