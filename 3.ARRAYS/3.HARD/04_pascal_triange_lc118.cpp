/*
118. Pascal's Triangle

Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
Example 2:

Input: numRows = 1
Output: [[1]]
 
Constraints:

1 <= numRows <= 30
*/

#include <iostream>
#include <vector>
using namespace std;


vector<vector<int>> generate(int numRows) {
    vector<vector<int>> triangle;

    for(int i = 0; i < numRows; i++){
        vector<int> row(i + 1, 1);  // first & last are 1

        for(int j = 1; j < i; j++){
            row[j] = triangle[i-1][j-1] + triangle[i-1][j];
        }

        triangle.push_back(row);
    }

    return triangle;
}

int main() {

    int n;
    cout << "Enter the number of rows: ";
    cin >> n;   

    vector<vector<int>> result = generate(n);

    cout << "The Pascal Triangle is: " << endl;
    for(auto &row : result){
        for(auto &val : row){
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}