/*
N-Queen Problem

The n-queens puzzle is the problem of placing n queens on a (n × n) chessboard such that no two queens can attack each other.
Note that two queens attack each other if they are placed on the same row, the same column, or the same diagonal.

Given an integer n, find all distinct solutions to the n-queens puzzle.
You can return your answer in any order but each solution should represent a distinct board configuration of the queen placements, where the solutions are represented as permutations of [1, 2, 3, ..., n].

In this representation, the number in the ith position denotes the column in which the queen is placed in the ith row.
For eg. below figure represents a chessboard [2, 4, 1, 3].


Examples:

Input: n = 1
Output: [1]
Explaination: Only one queen can be placed in the single cell available.

Input: n = 4
Output: [[2, 4, 1, 3], [3, 1, 4, 2]]
Explaination: There are 2 possible solutions for n = 4.

Input: n = 3
Output: []
Explaination: There are no possible solutions for n = 3.

Constraints:
1 ≤ n ≤ 10
*/

#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>> &board, int row, int col)
{
    // Check top
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 1)
        {
            return false;
        }
    }

    // Check diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }

    // Check antidiagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < board.size(); i--, j++)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }

    return true;
}

void solve(int n, int row, vector<vector<int>> &board, vector<vector<int>> &result)
{
    if (row == n)
    {
        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 1)
                {
                    ans.push_back(j + 1);
                    break;
                }
            }
        }

        result.push_back(ans);

        return;
    }
    for (int col = 0; col < n; col++)
    {
        if (isSafe(board, row, col))
        {
            board[row][col] = 1;
            solve(n, row + 1, board, result);
            board[row][col] = 0;
        }
    }
}

vector<vector<int>> nQueens(int n)
{
    vector<vector<int>> result;
    vector<vector<int>> board(n, vector<int>(n, 0));
    int row = 0;

    solve(n, row, board, result);

    return result;
}

int main()
{
    int n = 4;

    vector<vector<int>> res = nQueens(n);

    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}