/*
836. Print all primes till N

You are given an integer n.

Print all the prime numbers till n (including n).

A prime number is a number that has only two divisor's 1 and the number itself.

Example 1:
Input : n = 7

Output : [2, 3, 5, 7]

Explanation : The number 2 has only two divisors 1 and 2.

The number 3 has only two divisors 1 and 3.

The number 5 has only two divisors 1 and 5.

The number 7 has only two divisors 1 and 7.

Example 2:
Input : n = 2

Output : [2]

Explanation : There is only one number 2 that is a prime till 2.
*/

#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int num)
{
    int count = 0;

    for (int i = 1; i <= num; i++)
    {
        if (num % i == 0)
        {
            count++;
        }
    }

    return count == 2;
}

vector<int> BrutePrintPrimes(int n)
{
    vector<int> ans;

    for (int i = 2; i <= n; i++)
    {
        if (isPrime(i))
        {
            ans.push_back(i);
        }
    }

    return ans;
}

bool isPrimeRoot(int num)
{
    if (num <= 1)
    {
        return false;
    }

    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }

    return true;
}

vector<int> BetterPrintPrimes(int n)
{
    vector<int> ans;

    for (int i = 2; i <= n; i++)
    {
        if (isPrimeRoot(i))
        {
            ans.push_back(i);
        }
    }

    return ans;
}

vector<int> OptimalPrintPrimes(int n)
{
    vector<bool> isPrime(n + 1, true);

    isPrime[0] = false;

    if (n >= 1)
    {
        isPrime[1] = false;
    }

    for (int i = 2; i * i <= n; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    vector<int> ans;

    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i])
        {
            ans.push_back(i);
        }
    }

    return ans;
}

void printVector(const vector<int> &nums)
{
    cout << "[";
    for (int i = 0; i < nums.size(); i++)
    {
        if (i > 0)
        {
            cout << ", ";
        }
        cout << nums[i];
    }
    cout << "]" << endl;
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<int> brute = BrutePrintPrimes(n);
    vector<int> better = BetterPrintPrimes(n);
    vector<int> optimal = OptimalPrintPrimes(n);

    cout << "Brute Force: ";
    printVector(brute);

    cout << "Better Approach: ";
    printVector(better);

    cout << "Optimal Approach: ";
    printVector(optimal);

    return 0;
}