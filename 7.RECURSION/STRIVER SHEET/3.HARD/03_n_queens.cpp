/*
51. N-Queens

The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.


Example 1:
Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above

Example 2:
Input: n = 1
Output: [["Q"]]


Constraints:
1 <= n <= 9
*/

#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<string> &board, int row, int col)
{
    // Look Upward
    for (int i = row - 1; i >= 0; i--)
    {
        if (board[i][col] == 'Q')
        {
            return false;
        }
    }

    // Look Diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }

    // Look Anti-Diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < board.size(); i--, j++)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }

    return true;
}

void solve(int n, vector<string> &board, int row, vector<vector<string>> &result)
{
    if (row == n)
    {
        result.push_back(board);
        return;
    }

    for (int col = 0; col < n; col++)
    {
        if (isValid(board, row, col))
        {
            board[row][col] = 'Q';
            solve(n, board, row + 1, result);
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> result;
    vector<string> board(n, string(n, '.')); //
    int row = 0;

    solve(n, board, row, result);

    return result;
}

int main()
{
    int n = 4;
    vector<vector<string>> res = solveNQueens(n);

    for (auto &board : res)
    {
        for (auto &row : board)
        {
            cout << row << "\n";
        }
        cout << "\n";
    }

    return 0;
}