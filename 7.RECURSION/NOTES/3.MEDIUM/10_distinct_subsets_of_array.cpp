/*
Distinct Subsets

You are given an array arr[] of positive integers (which may contain duplicates), your task is to find all the unique or distinct subsets of the array.

Note: You can return the subsets in any order, the driver code will print them in sorted order.

Examples:
Input: arr[] = [1, 5, 6]
Output: [[], [1], [1, 5], [1, 5, 6], [1, 6], [5], [5, 6], [6]]
Explanation: The number of all the possible subsets will be 2n.
Now the unique subsets are [], [1], [1, 5], [1, 5, 6], [1, 6], [5], [5, 6], [6].

Input: arr[] = [1, 2, 2]
Output: [[], [1], [1, 2], [1, 2, 2], [2], [2, 2]]
Explanation: The number of all the possible subsets will be 2n.
Now the unique subsets are [], [1], [1, 2], [1, 2, 2], [2], [2, 2].

Constraints
1 ≤ arr.size() ≤ 15
1 ≤ arr[i] ≤  105
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
    int index = i + 1;
    while (index < arr.size() && arr[index] == arr[index - 1])
        index++;
    solve(index, arr, res, subset);
}

vector<vector<int>> distinctSubsets(vector<int> &arr)
{
    vector<int> subset;
    vector<vector<int>> res;

    solve(0, arr, res, subset);

    return res;
}

int main()
{
    cout << "Distince Subsets of Array are: " << endl;
    vector<int> arr = {1, 2, 2};
    vector<vector<int>> res = distinctSubsets(arr);
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