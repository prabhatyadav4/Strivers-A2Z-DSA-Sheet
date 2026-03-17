/*
Maximum Nesting Depth of Parenthesis

Problem Statement: Given a valid parentheses string s, return the nesting depth of s. 
The nesting depth is the maximum number of nested parentheses.

Examples
Example 1:
Input:
 s = "(1+(2*3)+((8)/4))+1"
Output:
 3
Explanation:
 Digit 8 is inside of 3 nested parentheses in the string.

Example 2:
Input:
 s = "(1)+((2))+(((3)))"
Output:
 3
Explanation:
 Digit 3 is inside of 3 nested parentheses in the string.
*/

#include <iostream>
#include <stack>
using namespace std;

class Solution {
    public:

    int BruteMaxDepth(string s){
        stack<char> st;
        int result = 0;

        for(char ch : s){
            if(ch == '('){
                st.push(ch);
            }
            else if(ch == ')'){
                st.pop();
            }

            result = max(result, (int)st.size());
        }

        return result;
    }

    int OptimalMaxDepth(string s){
        int openBrackets = 0;
        int result = 0; 

        for(char ch : s){
            if(ch == '('){
                openBrackets++;
            }
            else if(ch == ')'){
                openBrackets--;
            }

            result = max(result, openBrackets);
        }

        return result;
    }
};

int main() {
    Solution obj;

    string s = "(1+(2*3)+((8)/4))+1";

    int result1 = obj.BruteMaxDepth(s);
    cout << "BRUTE: Max Depth -> " << result1 << endl;

    int result2 = obj.OptimalMaxDepth(s);
    cout << "OPTIMAL: Max Depth -> " << result2 << endl;

    return 0;
}