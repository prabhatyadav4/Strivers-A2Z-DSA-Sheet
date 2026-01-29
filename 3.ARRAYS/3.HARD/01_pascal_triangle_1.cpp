/*
Pascal's Triangle I

Given two integers r and c, return the value at the rth row and cth column (1-indexed) in a Pascal's Triangle.

In Pascal's triangle:

The first row contains a single element 1.

Each row has one more element than the previous row.

Every row starts and ends with 1.

For all interior elements (i.e., not at the ends), the value at position (r, c) is computed as the sum of the two elements directly above it from the previous row:

Pascal[r][c]=Pascal[r−1][c−1]+Pascal[r−1][c]
where indexing is 1-based

Example 1

Input: r = 4, c = 2

Output: 3

Explanation:

The Pascal's Triangle is as follows:

1

1 1

1 2 1

1 3 3 1

....

Thus, value at row 4 and column 2 = 3

Example 2
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int pascalTriangleI(int r, int c) {
        // Convert to 0-based indexing
        int n = r - 1;
        int k = c - 1;

        long long res = 1;

        for (int i = 0; i < k; i++) {
            res = res * (n - i);
            res = res / (i + 1);
        }

        return (int)res;
    }
};

int main() {
    Solution obj;

    int r, c;
    cout << "Enter row: ";
    cin >> r;
    cout << "Enter column: ";
    cin >> c;

    int ans = obj.pascalTriangleI(r, c);
    cout << "Value at row " << r << " and column " << c << " is: " << ans << endl;

    return 0;
}