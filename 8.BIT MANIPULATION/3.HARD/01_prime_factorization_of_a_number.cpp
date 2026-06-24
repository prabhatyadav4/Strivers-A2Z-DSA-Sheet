/*
Prime factorisation of a Number

You are given an integer array queries of length n.

Return the prime factorization of each number in array queries in sorted order.


Example 1

Input : queries = [2, 3, 4, 5, 6]

Output : [ [2], [3], [2, 2], [5], [2, 3] ]

Explanation : The values 2, 3, 5 are itself prime numbers.

The prime factorization of 4 will be --> 2 * 2.

The prime factorization of 6 will be --> 2 * 3.

Example 2

Input : queries = [7, 12, 18]

Output : [ [7], [2, 2, 3], [2, 3, 3] ]

Explanation : The value 7 itself is a prime number.

The prime factorization of 12 will be --> 2 * 2 * 3.

The prime factorization of 18 will be --> 2 * 3 * 3.


Constraints:
1 <= n <= 105
2 <= queries[i] <= 2*105
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> factorize(int n)
{
    vector<int> factors;

    for (int i = 2; i <= n; i++)
    {
        while (n % i == 0)
        {
            factors.push_back(i);
            n /= i;
        }
    }

    return factors;
}

vector<vector<int>> BrutePrimeFactors(vector<int> &queries)
{
    vector<vector<int>> ans;

    for (int num : queries)
    {
        ans.push_back(factorize(num));
    }

    return ans;
}

vector<int> solve(int n)
{
    vector<int> factors;

    for (int i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            factors.push_back(i);
            n /= i;
        }
    }

    if (n > 1)
    {
        factors.push_back(n);
    }

    return factors;
}

vector<vector<int>> OptimalPrimeFactors(vector<int> &queries)
{
    vector<vector<int>> ans;

    for (int num : queries)
    {
        ans.push_back(solve(num));
    }

    return ans;
}

int main()
{

    vector<int> queries = {2, 3, 4, 5, 6};

    vector<vector<int>> ans1 = BrutePrimeFactors(queries);

    cout << "BRUTE: Prime factors of queries are:\n";

    for (auto &factors : ans1)
    {
        cout << "[";
        for (int i = 0; i < factors.size(); i++)
        {
            cout << factors[i];

            if (i != factors.size() - 1)
                cout << ", ";
        }
        cout << "]\n";
    }

    cout << "\n";

    vector<vector<int>> ans2 = OptimalPrimeFactors(queries);

    cout << "OPTIMAL: Prime factors of queries are:\n";

    for (auto &factors : ans2)
    {
        cout << "[";
        for (int i = 0; i < factors.size(); i++)
        {
            cout << factors[i];

            if (i != factors.size() - 1)
                cout << ", ";
        }
        cout << "]\n";
    }

    return 0;
}