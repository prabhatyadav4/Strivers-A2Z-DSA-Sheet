/*
Generate Binary Strings Without Consecutive 1s

Given an integer n, return all binary strings of length n that do not contain consecutive 1s. Return the result in lexicographically increasing order.

A binary string is a string consisting only of characters '0' and '1'.

Example 1
Input: n = 3
Output: ["000", "001", "010", "100", "101"]
Explanation: All strings are of length 3 and do not contain consecutive 1s.

Example 2
Input: n = 2
Output: ["00", "01", "10"]

Constraints
1 <= n <= 20
*/

#include <iostream>
#include <vector>
using namespace std;

void helper(string &s, int i, vector<string> &res) {
    int n = s.size();

    if(i == n) {
        res.push_back(s);
        return;
    }

    s[i] = '0';
    helper(s, i + 1, res);

    if(i == 0 || s[i - 1] != '1') {
        s[i] = '1';
        helper(s, i + 1, res);
    }
}

vector<string> binaryString(int n) {
    string s(n, '0');
    vector<string> res;

    helper(s, 0, res);

    return res;
}

int main() {
    int n = 3;

    cout << "All strings are of length 3 and do not contain consecutive 1s are: ";
    vector<string> ans = binaryString(n);
    for(auto it: ans) {
        cout << it << " ";
    }

    return 0;
}