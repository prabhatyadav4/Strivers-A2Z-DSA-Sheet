/*
36. Valid Sudoku

Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.

Note:
A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.


Example 1:

Input: board =
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true

Example 2:

Input: board =
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.


Constraints:
board.length == 9
board[i].length == 9
board[i][j] is a digit 1-9 or '.'.
*/

#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

bool isValid(vector<vector<char>> &board, int sr, int er, int sc, int ec)
{
    unordered_set<char> st;

    for (int i = sr; i <= er; i++)
    {
        for (int j = sc; j <= ec; j++)
        {
            if (board[i][j] == '.')
                continue;

            if (st.find(board[i][j]) != st.end())
            {
                return false;
            }
            st.insert(board[i][j]);
        }
    }

    return true;
}

bool BruteIsValidSudoku(vector<vector<char>> &board)
{

    // Validate Row
    for (int row = 0; row < 9; row++)
    {
        unordered_set<char> st;

        for (int col = 0; col < 9; col++)
        {
            if (board[row][col] == '.')
                continue;

            if (st.find(board[row][col]) != st.end())
            {
                return false;
            }

            st.insert(board[row][col]);
        }
    }

    // Validate Column
    for (int col = 0; col < 9; col++)
    {
        unordered_set<char> st;

        for (int row = 0; row < 9; row++)
        {
            if (board[row][col] == '.')
                continue;

            if (st.find(board[row][col]) != st.end())
            {
                return false;
            }

            st.insert(board[row][col]);
        }
    }

    // Validate 3 X 3 board
    for (int sr = 0; sr < 9; sr += 3)
    {
        int er = sr + 2;

        for (int sc = 0; sc < 9; sc += 3)
        {
            int ec = sc + 2;

            if (!isValid(board, sr, er, sc, ec))
            {
                return false;
            }
        }
    }

    return true;
}

bool OptimalIsValidSudoku(vector<vector<char>> &board)
{
    unordered_set<string> st;

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {

            if (board[i][j] == '.')
                continue;

            string row = string(1, board[i][j]) + "_ROW_" + to_string(i);
            string col = string(1, board[i][j]) + "_COL_" + to_string(j);
            string box = string(1, board[i][j]) + "_BOX_" +
                         to_string(i / 3) + "_" + to_string(j / 3);

            if (st.find(row) != st.end() || st.find(col) != st.end() ||
                st.find(box) != st.end())
            {
                return false;
            }

            st.insert(row);
            st.insert(col);
            st.insert(box);
        }
    }

    return true;
}

int main()
{
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    cout << "Brute Force: "
         << (BruteIsValidSudoku(board) ? "Valid" : "Invalid")
         << endl;

    cout << "Optimal: "
         << (OptimalIsValidSudoku(board) ? "Valid" : "Invalid")
         << endl;

    return 0;
}