/*
Recursive Implementation of atoi()

8. String to Integer (atoi)

Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.

The algorithm for myAtoi(string s) is as follows:
Whitespace: Ignore any leading whitespace (" ").
Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity if neither present.
Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then round the integer to remain in the range. Specifically, integers less than -231 should be rounded to -231, and integers greater than 231 - 1 should be rounded to 231 - 1.
Return the integer as the final result.


Example 1:
Input: s = "42"
Output: 42
Explanation:
The underlined characters are what is read in and the caret is the current reader position.
Step 1: "42" (no characters read because there is no leading whitespace)
         ^
Step 2: "42" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "42" ("42" is read in)
           ^

Example 2:
Input: s = " -042"
Output: -42
Explanation:
Step 1: "   -042" (leading whitespace is read and ignored)
            ^
Step 2: "   -042" ('-' is read, so the result should be negative)
             ^
Step 3: "   -042" ("042" is read in, leading zeros ignored in the result)
               ^

Example 3:
Input: s = "1337c0d3"
Output: 1337
Explanation:
Step 1: "1337c0d3" (no characters read because there is no leading whitespace)
         ^
Step 2: "1337c0d3" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "1337c0d3" ("1337" is read in; reading stops because the next character is a non-digit)
             ^

Example 4:
Input: s = "0-1"
Output: 0
Explanation:
Step 1: "0-1" (no characters read because there is no leading whitespace)
         ^
Step 2: "0-1" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "0-1" ("0" is read in; reading stops because the next character is a non-digit)
          ^

Example 5:
Input: s = "words and 987"
Output: 0
Explanation:
Reading stops at the first non-digit character 'w'.


Constraints:
0 <= s.length <= 200
s consists of English letters (lower-case and upper-case), digits (0-9), ' ', '+', '-', and '.'.
*/

#include <iostream>
#include <cctype> // for isdigit()
using namespace std;

// Constants for 32-bit integer range
const int INT_MIN_VAL = -2147483648;
const int INT_MAX_VAL = 2147483647;

/*
Recursive helper function

Parameters:
s    -> input string
i    -> current index
num  -> number formed so far
sign -> +1 or -1
*/
int helper(string &s, int i, long long num, int sign)
{
    // Base Case:
    // Stop recursion if:
    // 1. End of string reached
    // 2. Current character is NOT a digit
    if (i >= s.size() || !isdigit(s[i]))
    {
        return (int)(sign * num);
    }

    // Convert current digit character into integer
    // Example: '5' - '0' = 5
    num = num * 10 + (s[i] - '0');

    // Handle overflow for negative numbers
    if (num * sign <= INT_MIN_VAL)
        return INT_MIN_VAL;

    // Handle overflow for positive numbers
    if (num * sign >= INT_MAX_VAL)
        return INT_MAX_VAL;

    // Recursive call for next character
    return helper(s, i + 1, num, sign);
}

/*
Main atoi() function
*/
int myAtoI(string s)
{
    int i = 0;

    // Step 1: Skip leading whitespaces
    while (i < s.size() && s[i] == ' ')
        i++;

    // Step 2: Determine sign
    int sign = 1;

    if (i < s.size() && (s[i] == '+' || s[i] == '-'))
    {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }

    // Step 3: Call recursive helper
    return helper(s, i, 0, sign);
}

int main()
{
    string s = "  -12345";

    cout << "String to Integer is: " << myAtoI(s);

    return 0;
}