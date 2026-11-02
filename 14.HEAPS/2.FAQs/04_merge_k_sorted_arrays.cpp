/*
Merge k Sorted Arrays

Given a 2D matrix mat[][] of size n x m. Each row in the matrix is sorted in non-decreasing order, merge all the rows and return a single sorted array that contains all the elements of the matrix.

Examples :

Input: mat[][] = [[1, 3, 5, 7], [2, 4, 6, 8], [0, 9, 10, 11]]
Output: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]
Explanation: Merging all elements from the 3 sorted arrays and sorting them results in: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11].

Input: mat[][] = [[1, 2, 3, 4], [2, 2, 3, 4], [5, 5, 6, 6], [7, 8, 9, 9]]
Output: [1, 2, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 8, 9, 9]
Explanation: Merging all elements from the 4 sorted arrays and sorting them results in:[1, 2, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 8, 9, 9]

Constraints:
1 ≤ n * m ≤ 105
0 ≤ mat[i][j] ≤ 106
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> BruteMergeKArrays(vector<vector<int>> &mat)
{
    vector<int> ans;

    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[i].size(); j++)
        {
            ans.push_back(mat[i][j]);
        }
    }

    sort(ans.begin(), ans.end());

    return ans;
}

vector<int> OptimalMergeKArrays(vector<vector<int>> &mat)
{
    int n = mat.size();
    vector<int> ans;

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

    for (int i = 0; i < n; i++)
    {
        if (!mat[i].empty())
        {
            pq.push({mat[i][0], i, 0});
        }
    }

    while (!pq.empty())
    {
        auto curr = pq.top();
        pq.pop();

        int val = curr[0];
        int row = curr[1];
        int col = curr[2];

        ans.push_back(val);

        if (col + 1 < mat[row].size())
        {
            pq.push({mat[row][col + 1], row, col + 1});
        }
    }

    return ans;
}

int main()
{
    vector<vector<int>> mat = {
        {1, 3, 5, 7},
        {2, 4, 6, 8},
        {0, 9, 10, 11}};

    vector<int> bruteResult = BruteMergeKArrays(mat);
    vector<int> optimalResult = OptimalMergeKArrays(mat);

    cout << "Brute: ";
    for (int value : bruteResult)
    {
        cout << value << " ";
    }
    cout << '\n';

    cout << "Optimal: ";
    for (int value : optimalResult)
    {
        cout << value << " ";
    }
    cout << '\n';

    return 0;
}