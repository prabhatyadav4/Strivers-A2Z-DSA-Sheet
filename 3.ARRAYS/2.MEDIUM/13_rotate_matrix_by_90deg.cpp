/*
Rotate matrix by 90 degrees

Given an N * N 2D integer matrix, rotate the matrix by 90 degrees clockwise.

The rotation must be done in place, meaning the input 2D matrix must be modified directly.


Example 1

Input: matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]

Output: matrix = [[7, 4, 1], [8, 5, 2], [9, 6, 3]]


Example 2

Input: matrix = [[0, 1, 1, 2], [2, 0, 3, 1], [4, 5, 0, 5], [5, 6, 7, 0]]

Output: matrix = [[5, 4, 2, 0], [6, 5, 0, 1], [7, 0, 3, 1], [0, 5, 1, 2]]
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void BruteRotateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> ans(m, vector<int>(n,0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                ans[j][n - 1 - i] = matrix[i][j];
            }
        }

        matrix = ans;
    }

    void OptimalRotateMatrix(vector<vector<int>>& matrix){
        int n = matrix.size();

        // Transpose
        for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Reverse (for 90deg clockwise)
        for(int i = 0; i < n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }

        // // Reverse (for 90deg anti-clockwise)
        // for(int j = 0; j < n; j++){
        // int top = 0;
        // int bottom = n-1;
        // while(top < bottom){
        //     swap(matrix[top][j], matrix[bottom][j]);
        //     top++;
        //     bottom--;
        // }

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

int main() {
    Solution obj;

    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<vector<int>> mat1 = matrix;
    vector<vector<int>> mat2 = matrix;

    int m = matrix.size();
    int n = matrix[0].size();

    obj.BruteRotateMatrix(mat1);
    cout << "The Rotated Matrix (Brute) is: " << endl;
    obj.printMatrix(mat1, m, n);

    obj.OptimalRotateMatrix(mat2);
    cout << "\nThe Rotated Matrix (Optimal) is: " << endl;
    obj.printMatrix(mat2, m, n);

    return 0;
}