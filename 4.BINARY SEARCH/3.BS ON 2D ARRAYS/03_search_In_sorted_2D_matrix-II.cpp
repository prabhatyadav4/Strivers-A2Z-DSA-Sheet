/*
Search in a row and column-wise sorted matrix

Problem Statement: You have been given a 2-D array 'mat' of size 'N x M' where 'N' and 'M' denote the number of rows and columns, respectively. 
The elements of each row and each column are sorted in non-decreasing order. 
But, the first element of a row is not necessarily greater than the last element of the previous row (if it exists). 
You are given an integer ‘target’, and your task is to find if it exists in the given 'mat' or not.

Examples
Example 1:
Matrix=
1   4   7   11
2   5   8   12
3   6   9   16
10 13  14  17
Target: 9
Output: Found at (2,2) (0-indexed)


Example 2:
Matrix=
5   10  15
6   12  18
8   16  20
Target: 7
Output: Not Found
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:

    bool BruteSearchElementII(vector<vector<int>> &matrix, int target){
        int n = matrix.size();
        int m = matrix[0].size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == target){
                    return true;
                }
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

    bool BetterSearchElementII(vector<vector<int>> &matrix, int target){
        int n = matrix.size();
        int m = matrix[0].size();

        for(int i = 0; i < n; i++){
            if (binarySearch(matrix[i], target)) {
                return true;
            }
        }

        return false;
    }

    bool OptimalSearchElementII(vector<vector<int>> &matrix, int target){
        int n = matrix.size();
        int m = matrix[0].size();

        int row = 0;
        int col = m - 1;

        while(row < n && col >= 0){
            if(matrix[row][col] == target){
                return true;
            }
            else if(matrix[row][col] < target){
                row++;
            }
            else{
                col--;
            }
        }

        return false;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> matrix =  {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };

    int target = 8;

    bool result1 = obj.BruteSearchElementII(matrix, target);
    if(result1) cout << "Brute: The target " << target <<" exists." << endl;
    else cout << "Brute: The target " << target <<" doesn't exists." << endl;

    bool result2 = obj.BetterSearchElementII(matrix, target);
    if(result2) cout << "Better: The target " << target <<" exists." << endl;
    else cout << "Better: The target " << target <<" doesn't exists." << endl;

    bool result3 = obj.OptimalSearchElementII(matrix, target);
    if(result3) cout << "Optimal: The target " << target <<" exists." << endl;
    else cout << "Optimal: The target " << target <<" doesn't exists." << endl;

    return 0;
}