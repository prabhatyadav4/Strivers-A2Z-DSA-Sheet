/*
Minimum number of bracket reversals needed to make an expression balanced

Problem Statement: Given a string s consisting of only opening and closing brackets '(' and ')', find out the minimum number of reversals required to convert the string into a balanced expression.

If it is not possible to make the brackets balanced, return -1. A reversal means changing '(' to ')' or vice-versa.

Examples
Input : s = ")(())((("
Output : 3
Explanation :  One way to balance is: "((())())". There is no balanced sequence that can be formed in lesser reversals.
Input : s = "(()((()(())(("
Output : -1
Explanation : There's no way we can balance this sequence of braces.
*/

#include <iostream>
using namespace std;

class Solution {
    public:

    int minReversalsToBalance(string s) {
        int openBrackets = 0;
        int closeBrackets = 0;

        for(auto ch : s){
            if(ch == '('){
                openBrackets++;
            }
            else{
                if(openBrackets > 0){
                    openBrackets--;
                }
                else{
                    closeBrackets++;
                }
            }
        }

        if((openBrackets + closeBrackets) % 2 != 0)     return -1;

        return ((openBrackets + 1) / 2 + (closeBrackets + 1) / 2);
    }
};

int main() {
    Solution obj;

    string s = ")(())(((";

    cout << "Minimum reversals required: " << obj.minReversalsToBalance(s) << endl;

    return 0;
}