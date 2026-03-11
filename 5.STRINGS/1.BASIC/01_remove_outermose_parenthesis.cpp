/*
Remove Outermost Parentheses

Problem Statement: A valid parentheses string is defined by the following rules:
It is the empty string "".
If A is a valid parentheses string, then so is "(" + A + ")".
If A and B are valid parentheses strings, then A + B is also valid.

A primitive valid parentheses string is a non-empty valid string that cannot be split into two or more non-empty valid parentheses strings.

Given a valid parentheses string s, your task is to remove the outermost parentheses from every primitive component of s and return the resulting string.

Examples

Example 1:
Input:
 s = "((()))"
Output:
 "(())"
Explanation:
 The input string is a single primitive: "((()))".  
Removing the outermost layer yields: "(())".

Example 2:
Input:
 s = "()(()())(())"
Output:
 "(()())()"
Explanation:
 Primitive decomposition: "()" + "(()())" + "(())"  
After removing outermost parentheses: "" + "()()" + "()"
Final result: "(()())()".
*/

#include <iostream>
#include <stack>
using namespace std;

class Solution{
    public:

    string BruteRemoveOuterParenthesis(string s){
        string result = "";
        stack<char>  st;

        for(char ch : s){
            if(ch == ')')   st.pop();    
            if(!st.empty()) result += ch;   
            if(ch == '(')   st.push(ch);     
        }

        return result;
    }

    string OptimalRemoveOuterParenthesis(string s){
        string result = "";
        int depth = 0;

        for(char ch : s){
            if(ch == '('){
                if(depth > 0){
                    result += ch;
                }
                depth++;
            }
            else if(ch == ')'){
                depth--;
                if(depth > 0){
                    result += ch;
                }
            }
        }

        return result;
    }
};

int main() {
    Solution obj;

    string s = "(()())(())";  
    
    string result1 = obj.BruteRemoveOuterParenthesis(s);
    cout << "Brute: The result is: " << result1 << endl;
    
    string result2 = obj.OptimalRemoveOuterParenthesis(s);
    cout << "Optimal: The result is: " << result2 << endl;

    return 0;
}