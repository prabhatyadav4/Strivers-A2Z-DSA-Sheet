/*
79. Word Search

Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring.
The same letter cell may not be used more than once.

Example 1:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true

Example 2:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true

Example 3:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false


Constraints:
m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.
*/

#include <iostream>
#include <vector>
using namespace std;

int rows, cols;
int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool dfs(vector<vector<char>> &board, string &words, int i, int j, int idx)
{
    if (idx == words.length())
    {
        return true;
    }

    if (i < 0 || j < 0 || i >= rows || j >= cols || board[i][j] != words[idx] || board[i][j] == '$')
    {
        return false;
    }

    char temp = board[i][j];
    board[i][j] = '$';

    for (auto &d : dirs)
    {
        if (dfs(board, words, i + d[0], j + d[1], idx + 1))
        {
            board[i][j] = temp;
            return true;
        }
    }

    board[i][j] = temp;
    return false;
}

bool wordSearch(vector<vector<char>> &board, string word)
{
    rows = board.size();
    cols = board[0].size();

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (board[i][j] == word[0] && dfs(board, word, i, j, 0))
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}};
    cout << boolalpha << wordSearch(board, "ABCCED") << endl; // true
    cout << boolalpha << wordSearch(board, "SEE") << endl;    // true
    cout << boolalpha << wordSearch(board, "ABCB") << endl;   // false
}