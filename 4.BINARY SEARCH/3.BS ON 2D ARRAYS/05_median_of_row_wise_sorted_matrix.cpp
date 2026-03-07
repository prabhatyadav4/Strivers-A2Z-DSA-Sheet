/*
Median of Row Wise Sorted Matrix

Problem Statement:
Given a row-wise sorted matrix of size M*N, where M is no. of rows and N is no. of columns, find the median in the given matrix.
Note: M*N is odd.

Examples
Input: M = 3, N = 3, matrix[][] =

1 4 9 
2 5 6
3 8 7
Output: 5
Explanation: 
If we find the linear sorted array, the array becomes 1 2 3 4 5 6 7 8 9. Therefore, median = 5

Input: M = 3, N = 3, matrix[][] =

1 3 8 
2 3 4
1 2 5
Output: 3
Explanation: 
If we find the linear sorted array, the array becomes 1 1 2 2 3 3 4 5 7 8. Therefore, median = 3.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
    public:

    int BruteFindMedian(vector<vector<int>> &matrix){
        vector<int> elements;
        
        for(auto &row : matrix){
            for(auto val : row){
                elements.push_back(val);
            }
        }

        sort(elements.begin(), elements.end());

        return elements[elements.size() / 2];
    }

    int countLessEqual(vector<int> &row, int mid){
        return upper_bound(row.begin(), row.end(), mid) - row.begin();
    }

    int OptimalFindMedian(vector<vector<int>> &matrix){
        int rows = matrix.size();
        int cols = matrix[0].size();

        int low = matrix[0][0];
        int high = matrix[0][cols - 1];

        for(int i = 1; i < rows; i++){
            low = min(low, matrix[i][0]);
            high = max(high, matrix[i][cols - 1]);
        }

        while(low < high){
            int mid = low + (high - low) / 2;

            int count = 0;

            for(int i = 0; i < rows; i++){
                count += countLessEqual(matrix[i], mid);
            }

            if(count < (rows * cols + 1) / 2){
                low = mid + 1;
            }

            else{
                high = mid;
            }
        }

        return low;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> matrix = {
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}
    };

    int result1 = obj.BruteFindMedian(matrix);
    cout << "Brute: The median is: " << result1 << endl;

    int result2 = obj.OptimalFindMedian(matrix);
    cout << "Optimal: The median is: " << result2 << endl;

    return 0;
}