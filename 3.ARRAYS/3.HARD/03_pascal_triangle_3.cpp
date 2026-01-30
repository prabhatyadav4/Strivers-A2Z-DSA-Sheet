/*
Pascal's Triangle

Problem statement

You are given an integer N. Your task is to return a 2-D ArrayList containing the pascal’s triangle till the row N.

A Pascal's triangle is a triangular array constructed by summing adjacent elements in preceding rows. Pascal's triangle contains the values of the binomial coefficient. For example in the figure below.


For example, given integer N= 4 then you have to print.

1  
1 1 
1 2 1 
1 3 3 1

Here for the third row, you will see that the second element is the summation of the above two-row elements i.e. 2=1+1, and similarly for row three 3 = 1+2 and 3 = 1+2.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 40
1 <= N <= 50

Time Limit: 1 sec
Sample Input 1 :
3
1
2
3
Sample Output 1 :
1
1 
1 1 
1 
1 1 
1 2 1 
*/

#include <iostream>
#include <vector>
using namespace std;

vector<long long> generate(int numRows) {
    long long ans = 1;
    vector<long long> ansRow;
    ansRow.push_back(1);

    for(int col = 1; col < numRows; col++){
        ans = ans * (numRows - col);
        ans = ans / col;
        ansRow.push_back(ans);
    }
    return ansRow;
}

vector<vector<long long>> printPascal(int n) {
    vector<vector<long long>> ans;

    for(int i = 1; i <= n; i++){
        ans.push_back(generate(i));
    }
    return ans;
}

int main() {
    int n;
    cout << "Enter the number of rows: ";
    cin >> n;   

    vector<vector<long long>> result = printPascal(n);

    cout << "The Pascal Triangle is: " << endl;
    for(auto &row : result){
        for(auto &val : row){
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}