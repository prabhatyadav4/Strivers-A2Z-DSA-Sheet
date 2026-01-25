/*
Set Matrix Zeroes

Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0. You must do it in place.

Example 1

Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]

Output: [[1,0,1],[0,0,0],[1,0,1]]

Explanation:

Element at position (1,1) is 0, so set entire row 1 and column 1 to 0.

Example 2

Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]

Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

Explanation:

There are two zeroes: (0,0) and (0,3).

Row 0 → all elements become 0
Column 0 and column 3 → all elements become 0
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void setZeroesBrute(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        // Step 1: Mark rows and columns
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    // Mark row
                    for (int k = 0; k < n; k++)
                    {
                        if (matrix[i][k] != 0)
                            matrix[i][k] = -1;
                    }
                    // Mark column
                    for (int k = 0; k < m; k++)
                    {
                        if (matrix[k][j] != 0)
                            matrix[k][j] = -1;
                    }
                }
            }
        }

        // Step 2: Convert -1 to 0
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == -1)
                    matrix[i][j] = 0;
            }
        }
    }

    void setZeroesBetter(vector<vector<int>> &matrix){
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> row(m, 0);
        vector<int> col(n, 0);

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(row[i] == 1 || col[j] == 1){
                    matrix[i][j] = 0;
                }
            }
        }
    }

    void printMatrix(vector<vector<int>> &matrix, int m, int n){
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

};

int main()
{
    Solution obj;

    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };

    vector<vector<int>> mat1 = matrix;
    vector<vector<int>> mat2 = matrix;
    vector<vector<int>> mat3 = matrix;

    int m = matrix.size();
    int n = matrix[0].size();

    obj.setZeroesBrute(mat1);
    cout << "The Zeroes Matrix (Brute) is: " << endl;
    obj.printMatrix(mat1, m, n);

    obj.setZeroesBetter(mat2);
    cout << "\nThe Zeroes Matrix (Better) is: " << endl;
    obj.printMatrix(mat2, m, n);

    obj.setZeroesOptimal(mat3);
    cout << "\nThe Zeroes Matrix (Optimal) is: " << endl;
    obj.printMatrix(mat3, m, n);

    return 0;
}