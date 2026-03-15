/*
Largest Odd Number in a String.

Problem Statement: Given a string s, representing a large integer, the task is to return the largest-valued odd integer (as a string) that is a substring of the given string s.
The number returned should not have leading zero's. But the given input string may have leading zero.

Examples

Example 1
Input:
 s = "5347"
Output:
 "5347"
Explanation:
 The odd numbers formed by the given string are → 5, 3, 53, 347, 5347. 
 The largest odd number without leading zeroes is 5347.

Example 2
Input:
 s = "0214638"
Output:
 "21463"
Explanation:
 The odd numbers formed by the string are → 1, 3, 21, 63, 463, 1463, 21463. 
 We can't use numbers starting with 0, so the largest valid odd number is 21463.
*/

#include <iostream>
using namespace std;

class Solution {
    public:
    string largestOddNumber(string num) {
        for(int i = num.length(); i >= 0; i--){
            if((num[i] - '0') % 2 == 1){
                return num.substr(0, i + 1);
            }
        }

        return "";
    }

    string largestOddNoLeading(string num) {
        int i = 0;
        while(i < num.size() - 1 && num[i] == '0'){
            i++;
        }
        num = num.substr(i);

        for(int i = num.size() - 1; i >= 0; i--){
            if((num[i] - '0') % 2 == 1){
                return num.substr(0, i + 1);
            }
        }

        return "";
    }
};

int main() {
    Solution obj;

    string s = "0123456";

    string result1 = obj.largestOddNumber(s);
    cout << "With leading zeros: " << result1 << endl;

    string result2 = obj.largestOddNoLeading(s);
    cout << "Without leading zeros: " << result2 << endl;

    return 0;
}