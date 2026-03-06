/*
Search in a sorted 2D matrix

Problem Statement: You have been given a 2-D array 'mat' of size 'N x M' where 'N' and 'M' denote the number of rows and columns, respectively. 
The elements of each row are sorted in non-decreasing order. Moreover, the first element of a row is greater than the last element of the previous row (if it exists). 
You are given an integer ‘target’, and your task is to find if it exists in the given 'mat' or not.

Examples
Input :mat = [ [1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12] ], target = 8
Output :True.
Explanation :The target = 8 exists in the 'mat' at index (1, 3).

Input :mat = [ [1, 2, 4], [6, 7, 8], [9, 10, 34] ], target = 78
Output :false.
Explanation :The target = 78 does not exist in the 'mat'. Therefore in the output, we see 'false'.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
    
    bool BruteSearchMatrix(vector<vector<int>> &matrix, int target){
        int n = matrix.size();
        int m = matrix[0].size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == target)  return true;
            }
        }   

        return false;
    }

    bool binarySearch(vector<int> &matrix, int target){
        int n = matrix.size();
        int low = 0, high = n - 1;
        
        while(low <= high){
            int mid = low + (high - low) / 2;

            if(matrix[mid] == target){
                return true;
            }
            else if(matrix[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return false;
    }

    bool BetterSearchMatrix(vector<vector<int>> &matrix, int target){
        int n = matrix.size();
        int m = matrix[0].size();

        for(int i = 0; i < n; i++){
            if(matrix[i][0] <= target && target <= matrix[i][m - 1]){
                return binarySearch(matrix[i], target);
            }
        }

        return false;
    }

    bool OptimalSearchMatrix(vector<vector<int>> &matrix, int target){
        int n = matrix.size();
        int m = matrix[0].size();

        int low = 0, high = (n * m) - 1;

        while(low <= high){
            int mid = low + (high - low) / 2;
            int row = mid / m;
            int col = mid % m;

            if(matrix[row][col] == target){
                return true;
            }
            else if(matrix[row][col] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return false;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    int target = 8;

    bool result1 = obj.BruteSearchMatrix(matrix, target);
    if(result1) cout << "Brute: The target " << target <<" exists." << endl;
    else cout << "Brute: The target " << target <<" doesn't exists." << endl;

    bool result2 = obj.BetterSearchMatrix(matrix, target);
    if(result2) cout << "Better: The target " << target <<" exists." << endl;
    else cout << "Better: The target " << target <<" doesn't exists." << endl;

    bool result3 = obj.OptimalSearchMatrix(matrix, target);
    if(result3) cout << "Optimal: The target " << target <<" exists." << endl;
    else cout << "Optimal: The target " << target <<" doesn't exists." << endl;

    return 0;
}