/*
119. Pascal's Triangle II

Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

Example 1:

Input: rowIndex = 3
Output: [1,3,3,1]
Example 2:

Input: rowIndex = 0
Output: [1]
Example 3:

Input: rowIndex = 1
Output: [1,1]
 
Constraints:

0 <= rowIndex <= 33
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row;
        long long ans = 1;
        row.push_back(1);

        for(int i = 1; i <= rowIndex; i++){
            ans = ans * (rowIndex - i + 1);
            ans = ans / i;
            row.push_back(ans);
        }

        return row;
    }
};

int main() {
    Solution obj;

    int rowIndex;
    cout << "Enter rowIndex: ";
    cin >> rowIndex;

    vector<int> result = obj.getRow(rowIndex);

    cout << "Pascal's Triangle Row " << rowIndex << ": ";
    for(int val : result){
        cout << val << " ";
    }

    return 0;
}