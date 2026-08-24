/*
85. Maximal Rectangle

Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

Example 1:
Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.

Example 2:
Input: matrix = [["0"]]
Output: 0

Example 3:
Input: matrix = [["1"]]
Output: 1


Constraints:
rows == matrix.length
cols == matrix[i].length
1 <= rows, cols <= 200
matrix[i][j] is '0' or '1'.
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    stack<int> st;
    int ans = 0;

    for (int i = 0; i <= n; i++)
    {
        int currentHeight = (i == n ? 0 : heights[i]);

        while (!st.empty() && heights[st.top()] > currentHeight)
        {
            int height = heights[st.top()];
            st.pop();

            int width;

            if (st.empty())
            {
                width = i;
            }
            else
            {
                width = i - st.top() - 1;
            }

            ans = max(ans, height * width);
        }

        st.push(i);
    }

    return ans;
}

int maximalRectangle(vector<vector<char>> &matrix)
{
    if (matrix.empty())
    {
        return 0;
    }

    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<int> heights(cols, 0);

    int ans = 0;

    for (int i = 0; i < rows; i++)
    {

        for (int j = 0; j < cols; j++)
        {

            if (matrix[i][j] == '1')
            {
                heights[j]++;
            }
            else
            {
                heights[j] = 0;
            }
        }

        ans = max(ans, largestRectangleArea(heights));
    }

    return ans;
}

int main()
{
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}};

    cout << maximalRectangle(matrix) << endl;

    return 0;
}