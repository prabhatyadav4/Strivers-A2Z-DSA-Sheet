/*
The Celebrity Problem

A celebrity is a person who is known to all but does not know anyone at a party. A party is being organized by some people.
A square matrix mat[][] of size n*n is used to represent people at the party such that if an element of row i and column j is set to 1 it means ith person knows jth person.
You need to return the index of the celebrity in the party, if the celebrity does not exist, return -1.

Note: Follow 0-based indexing.

Examples:

Input: mat[][] = [[1, 1, 0],
                [0, 1, 0],
                [0, 1, 1]]
Output: 1

Explanation: 0th and 2nd person both know 1st person and 1st person does not know anyone. Therefore, 1 is the celebrity person.

Input: mat[][] = [[1, 1],
                [1, 1]]
Output: -1
Explanation: Since both the people at the party know each other. Hence none of them is a celebrity person.

Input: mat[][] = [[1]]
Output: 0

Constraints:
1 ≤ mat.size() ≤ 1000
0 ≤ mat[i][j] ≤ 1
mat[i][i] = 1
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int BruteCelebrity(vector<vector<int>> &mat)
{
    int n = mat.size();

    for (int i = 0; i < n; i++)
    {
        bool knowsNobody = true;
        bool knownByEveryone = true;

        for (int j = 0; j < n; j++)
        {
            if (i != j && mat[i][j] == 1)
            {
                knowsNobody = false;
                break;
            }
        }

        if (knowsNobody)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != j && mat[j][i] == 0)
                {
                    knownByEveryone = false;
                    break;
                }
            }
        }

        if (knowsNobody && knownByEveryone)
        {
            return i;
        }
    }

    return -1;
}

// Time:  O(N²) Space: O(1)

int BetterCelebrity(vector<vector<int>> &mat)
{
    int n = mat.size();
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        st.push(i);
    }

    while (st.size() > 1)
    {
        int A = st.top();
        st.pop();

        int B = st.top();
        st.pop();

        if (mat[A][B] == 1)
        {
            st.push(B);
        }
        else
        {
            st.push(A);
        }
    }

    int candidate = st.top();

    for (int j = 0; j < n; j++)
    {
        if (j != candidate && mat[candidate][j] == 1)
        {
            return -1;
        }
    }

    for (int j = 0; j < n; j++)
    {
        if (j != candidate && mat[j][candidate] == 0)
        {
            return -1;
        }
    }

    return candidate;
}

// Time:  O(N)  Space: O(N)

int OptimalCelebrity(vector<vector<int>> &mat)
{
    int n = mat.size();

    int top = 0;
    int bottom = n - 1;

    while (top < bottom)
    {
        if (mat[top][bottom] == 1)
        {
            top++;
        }
        else
        {
            bottom--;
        }
    }

    int candidate = top;

    for (int j = 0; j < n; j++)
    {
        if (j != candidate && mat[candidate][j] == 1)
        {
            return -1;
        }
    }

    for (int j = 0; j < n; j++)
    {
        if (j != candidate && mat[j][candidate] == 0)
        {
            return -1;
        }
    }

    return candidate;
}

// Time:  O(N)  Space: O(1)

int main()
{
    vector<vector<int>> mat = {{1, 1, 0},
                               {0, 1, 0},
                               {0, 1, 1}};

    cout << "BRUTE: " << BruteCelebrity(mat) << " is the celebrity\n";

    cout << "BETTER: " << BetterCelebrity(mat) << " is the celebrity\n";

    cout << "OPTIMAL: " << OptimalCelebrity(mat) << " is the celebrity";

    return 0;
} 