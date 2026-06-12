/*
Rat in a Maze

Given a binary matrix maze[][] of size n × n containing values 0 and 1, find all possible paths for a rat to travel from the source cell (0, 0) to the destination cell (n - 1, n - 1).
The rat can move in four directions: up(U), down(D), left(L), and right(R).

    1 represents an open cell through which the rat can move.
    0 represents a blocked cell that cannot be traversed.

The rat can move only through open cells and cannot visit the same cell more than once in a path.
Return all valid paths as strings consisting of 'U', 'D', 'L', and 'R', representing the sequence of moves taken by the rat.

Note: Return the paths in lexicographically increasing order. If no valid path exists, return an empty list.

Examples:

Input: maze[][] = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}}
Output: ["DDRDRR", "DRDDRR"]
Explanation: There are two valid paths from the source cell (0, 0) to the destination cell (3, 3).

Input: maze[][] = [[1, 0], [1, 0]]
Output: []
Explanation: No path exists as the destination cell (1, 1) is blocked.

Constraints:
2 ≤ n ≤ 5
0 ≤ maze[i][j] ≤ 1
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isSafe(int row, int col, int n)
{
    return row >= 0 && row < n && col >= 0 && col < n;
}

void solve(int row, int col, vector<vector<int>> &maze, string &path, vector<string> &result)
{
    int n = maze.size();

    if (!isSafe(row, col, n) || maze[row][col] == 0)
    {
        return;
    }

    if (row == n - 1 && col == n - 1)
    {
        result.push_back(path);
        return;
    }

    maze[row][col] = 0;

    path.push_back('U');
    solve(row - 1, col, maze, path, result);
    path.pop_back();

    path.push_back('D');
    solve(row + 1, col, maze, path, result);
    path.pop_back();

    path.push_back('L');
    solve(row, col - 1, maze, path, result);
    path.pop_back();

    path.push_back('R');
    solve(row, col + 1, maze, path, result);
    path.pop_back();

    maze[row][col] = 1;
}

vector<string> ratInMaze(vector<vector<int>> &maze, int n)
{
    vector<string> result;
    string path = "";

    if (maze[0][0] == 1 && maze[n - 1][n - 1] == 1)
    {
        solve(0, 0, maze, path, result);
    }

    sort(result.begin(), result.end());

    return result;
}

int main()
{
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}};

    int n = maze.size();

    vector<string> result = ratInMaze(maze, n);

    for (auto p : result)
    {
        cout << p << " ";
    }

    return 0;
}