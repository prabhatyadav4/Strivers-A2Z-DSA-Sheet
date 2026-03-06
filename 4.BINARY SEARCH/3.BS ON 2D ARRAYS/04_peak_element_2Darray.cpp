/*
Find Peak Element (2D Matrix)

Problem Statement: Given a 0-indexed n x m matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the array [i, j]. 
A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbours to the left, right, top, and bottom.
Assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.

Note: As there can be many peak values, 1 is given as output if the returned index is a peak number, otherwise 0.

Examples
Example 1:
Input:
 mat = [[5, 10, 8], [4, 25, 7], [3, 9, 6]]
Output:
 [1, 1]
Explanation:
 The value at index [1, 1] is 25, which is a peak because all its neighbors (10, 7, 4, 9) are smaller.

Example 2:
Input:
 mat = [[1, 2, 3], [6, 5, 4], [7, 8, 9]]
Output:
 [2, 2]
Explanation:
 The value at index [2, 2] is 9, which is a peak as it is greater than its neighbors (8, 4).
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
    int maxElement(vector<vector<int>> &mat, int col){
        int n = mat.size();
        int max_value = INT_MIN;
        int index = -1;

        for(int i = 0; i < n; i++){
            if(mat[i][col] > max_value){
                max_value = mat[i][col];
                index = i;
            }
        }

        return index;
    }

    vector<int> findPeakGrid(vector<vector<int>> &mat){
        int n = mat.size();
        int m = mat[0].size();

        int low = 0, high = m - 1;
        
        while(low <= high){
            int mid = low + (high - low) / 2;
            
            int row = maxElement(mat, mid);
            int left = mid - 1 >= 0 ? mat[row][mid - 1] : INT_MIN;
            int right = mid + 1 < m ? mat[row][mid + 1] : INT_MIN;
            
            if(mat[row][mid] > left && mat[row][mid] > right){
                return {row, mid};
            }
            else if(mat[row][mid] > left){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        
        return {-1, -1};
    }
};

int main() {
    Solution obj;

    vector<vector<int>> matrix = {
          {4, 2, 5, 1, 4, 5},
          {2, 9, 3, 2, 3, 2},
          {1, 7, 6, 0, 1, 3},
          {3, 6, 2, 3, 7, 2}
    };
    
    vector<int> peak = obj.findPeakGrid(matrix);
    cout << "The row of peak element is " << peak[0]
        << " and column of the peak element is " << peak[1] << endl;

    return 0;
}