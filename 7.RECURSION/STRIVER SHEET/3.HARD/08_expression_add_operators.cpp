/*
282. Expression Add Operators

Given a string num that contains only digits and an integer target, return all possibilities to insert the binary operators '+', '-', and/or '*' between the digits of num so that the resultant expression evaluates to the target value.

Note that operands in the returned expressions should not contain leading zeros.

Note that a number can contain multiple digits.

Example 1:
Input: num = "123", target = 6
Output: ["1*2*3","1+2+3"]
Explanation: Both "1*2*3" and "1+2+3" evaluate to 6.

Example 2:
Input: num = "232", target = 8
Output: ["2*3+2","2+3*2"]
Explanation: Both "2*3+2" and "2+3*2" evaluate to 8.

Example 3:
Input: num = "3456237490", target = 9191
Output: []
Explanation: There are no expressions that can be created from "3456237490" to evaluate to 9191.


Constraints:
1 <= num.length <= 10
num consists of only digits.
-231 <= target <= 231 - 1
*/

#include <iostream>
#include <vector>
using namespace std;

void dfs(string &num, int target, int start, long long current_val, long long last_operand, string expression, vector<string> &result)
{
    if (start == num.size())
    {
        if (current_val == target)
        {
            result.push_back(expression);
        }

        return;
    }

    for (int i = start; i < num.size(); i++)
    {
        if (i > start && num[start] == '0')
        {
            return;
        }

        string current_num = num.substr(start, i - start + 1);
        int current_num_val = stoll(current_num);

        if (start == 0)
        {
            dfs(num, target, i + 1, current_num_val, current_num_val, current_num, result);
        }
        else
        {
            // Addition
            dfs(num, target, i + 1, current_val + current_num_val, current_num_val, expression + "+" + current_num, result);
            // Subtraction
            dfs(num, target, i + 1, current_val - current_num_val, -current_num_val, expression + "-" + current_num, result);
            // Multiplication
            dfs(num, target, i + 1, current_val - last_operand + last_operand * current_num_val, last_operand * current_num_val, expression + "*" + current_num, result);
        }
    }
}

vector<string> addOperators(string num, int target)
{
    vector<string> result;

    dfs(num, target, 0, 0, 0, "", result);

    return result;
}

int main()
{
    string num = "123";
    int target = 6;

    vector<string> result = addOperators(num, target);

    for (const string &expr : result)
    {
        cout << expr << " ";
    }
    return 0;
}