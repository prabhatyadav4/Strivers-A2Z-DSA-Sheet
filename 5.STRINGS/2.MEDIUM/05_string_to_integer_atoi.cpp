/*
Recursive Implementation of atoi()

Problem Statement: Implement the function myAtoi(s) which converts the given string s to a 32-bit signed integer (similar to the C/C++ atoi function).

Steps to Implement: 1. First, ignore any leading whitespace characters ' ' until the first non-whitespace character is found.
2. Check the next character to determine the sign. If it’s a '-', the number should be negative. If it’s a '+', the number should be positive. If neither is found, assume the number is positive.
3. Read the digits and convert them into a number. Stop reading once a non-digit character is encountered or the end of the string is reached. Leading zeros should be ignored during conversion.
4. The result should be clamped within the 32-bit signed integer range: [-2147483648, 2147483647]. If the computed number is outside this range, return -2147483648 if the number is less than -2147483648, or return 2147483647 if the number is greater than 2147483647.
5. Finally, return the computed number after applying all the above steps.

Examples
Example 1:
Input:
 s = " -12345"  
Output:
 -12345  
Explanation: 
Ignore leading whitespaces.  
The sign '-' is encountered, indicating the number is negative.  
Digits 12345 are read and converted to -12345.

Example 2:
Input:
 s = "4193 with words"  
Output:
 4193  
Explanation:
Read the digits 4193 and stop when encountering the first non-digit character (w).
*/

#include<iostream>
using namespace std;

class Solution {
    public:

    const int INT_MIN_VALUE = -2147483648;
    const int INT_MAX_VALUE = 2147483647;

    int helper(const string &s, int i, long long num, int sign){
        if(i >= s.size() || !isdigit(s[i])){
            return (int)(sign * num);
        }

        num = num * 10 + (s[i] - '0');

        if(sign * num <= INT_MIN_VALUE) return INT_MIN_VALUE;
        if(sign * num >= INT_MAX_VALUE) return INT_MAX_VALUE;

        return helper(s, i + 1, num, sign);
    }

    int myAtoI(string s){
        int i = 0;
        while(i < s.size() && s[i] == ' ')  i++;

        int sign = 1;
        if(i < s.size() && (s[i] == '+' || s[i] == '-')){
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        return helper(s, i, 0, sign);
    }
};

int main() {
    Solution obj;

    string s = " -042";
    cout << "The number is: " << obj.myAtoI(s) << endl;

    return 0;
}