/*
Find all possible paths from top to bottom

Given a n x m matrix mat[][]. Your task is to find and return all possible paths from the top-left cell (0, 0) to the bottom-right cell (n-1, m-1).

From each cell, you can move only in the following two directions:

Right → (i, j+1)

Down → (i+1, j)

Return all possible paths, where each path is represented as a list of matrix elements encountered along the path.

Examples:
Input: mat[][] = [[1, 2, 3],
                [4, 5, 6]]
Output: [[1, 4, 5, 6],
        [1, 2, 5, 6],
        [1, 2, 3, 6]]
Explanation: We can see that there are 3
paths from the cell (0,0) to (1,2).

Input: mat[][] = [[1, 2],
                [3, 4]]
Output: [[1, 2, 4],
        [1, 3, 4]]
Explanation: There are 2 possible paths from cell (0, 0) to (1, 1).

Constraints:
1 <= n, m <= 10
1 <= mat[i][j] <= n*m
n * m < 20
*/

#include <iostream>
#include <vector>
using namespace std;

void solve(int i, int j,
           int n, int m,
           vector<vector<int>> &mat,
           vector<int> &path,
           vector<vector<int>> &ans)
{

    // Add current cell to path
    path.push_back(mat[i][j]);

    // Destination reached
    if (i == n - 1 && j == m - 1)
    {

        ans.push_back(path);

        // Backtrack
        path.pop_back();
        return;
    }

    // Move Down
    if (i + 1 < n)
    {
        solve(i + 1, j, n, m, mat, path, ans);
    }

    // Move Right
    if (j + 1 < m)
    {
        solve(i, j + 1, n, m, mat, path, ans);
    }

    // Backtrack
    path.pop_back();
}

vector<vector<int>> findAllPossiblePaths(int n,
                                         int m,
                                         vector<vector<int>> &mat)
{

    vector<vector<int>> ans;
    vector<int> path;

    solve(0, 0, n, m, mat, path, ans);

    return ans;
}

int main()
{

    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    int n = mat.size();
    int m = mat[0].size();

    vector<vector<int>> paths =
        findAllPossiblePaths(n, m, mat);

    cout << "All Possible Paths:\n";

    for (auto &path : paths)
    {

        cout << "[ ";

        for (int val : path)
        {
            cout << val << " ";
        }

        cout << "]\n";
    }

    return 0;
}