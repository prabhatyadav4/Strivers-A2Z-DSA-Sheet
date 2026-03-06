/*
Find the row with maximum number of 1's


Problem Statement: You have been given a non-empty grid ‘mat’ with 'n' rows and 'm' columns consisting of only 0s and 1s. All the rows are sorted in ascending order. Your task is to find the index of the row with the maximum number of ones. 

Note: If two rows have the same number of ones, consider the one with a smaller index. If there's no row with at least 1 zero, return -1

Examples

Example 1:
Input Format: n = 3, m = 3, 
mat[] = 
1 1 1
0 0 1
0 0 0
Result: 0
Explanation: The row with the maximum number of ones is 0 (0 - indexed).

Example 2:
Input Format: n = 2, m = 2 , 
mat[] = 
0 0
0 0
Result: -1
Explanation:  The matrix does not contain any 1. So, -1 is the answer.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
    public:

    int BruteRowWithMax1s(vector<vector<int>> &matrix, int n, int m){
        int cnt_max = 0;
        int index = -1;

        for(int i = 0; i < n; i++){
            int cnt_ones = 0;
            for(int j = 0; j < m; j++){
                cnt_ones += matrix[i][j];
            }
            if(cnt_ones > cnt_max){
                cnt_max = cnt_ones;
                index = i;
            }
        }   
    
        return index;
    }

    int lowerBound(vector<int> &arr, int n, int x){
        int low = 0, high = n - 1;
        int ans = n;

        while(low <= high){
            int mid = low + (high - low) / 2;
            if(arr[mid] >= x){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return ans;
    }

    int OptimalRowWithMax1s(vector<vector<int>> &matrix, int n, int m){
        int cnt_max = 0;
        int index = -1;

        for(int i = 0; i < n; i++){
            int cnt_ones = m - lowerBound(matrix[i], m, 1);
            if(cnt_ones > cnt_max){
                cnt_max = cnt_ones;
                index = i;
            }
        }

        return index;
    }

    // STL solution for LeetCode 2643: Row With Maximum Ones.
    vector<int> LC2643_maxOne(vector<vector<int>>& mat) {
        int n = mat.size();
        int cnt_max = 0;
        int index = 0;

        for(int i = 0; i < n; i++){
            int cnt_ones = count(mat[i].begin(), mat[i].end(), 1);
            if(cnt_ones > cnt_max){
                cnt_max = cnt_ones;
                index = i;
            }
        }

        return {index, cnt_max};
    }
};

int main() {
    Solution obj;

    vector<vector<int>> matrix = {{1, 1, 1}, {0, 0, 1}, {0, 0, 0}};
    int n = 3, m = 3;

    int result1 = obj.BruteRowWithMax1s(matrix, n, m);
    cout << "Brute: The row with maximum no. of 1's is: " << result1 << endl;

    int result2 = obj.OptimalRowWithMax1s(matrix, n, m);
    cout << "Optimal: The row with maximum no. of 1's is: " << result2 << endl;

    vector<int> result3 = obj.LC2643_maxOne(matrix);
    cout << "Optimal: The row with maximum no. of 1's is: " ;
    for(auto i : result3){
        cout << i << " ";
    }

    return 0;
}