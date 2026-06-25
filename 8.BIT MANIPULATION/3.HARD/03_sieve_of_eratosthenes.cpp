/*
204. Count Primes

Given an integer n, return the number of prime numbers that are strictly less than n.

Example 1:
Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

Example 2:
Input: n = 0
Output: 0

Example 3:
Input: n = 1
Output: 0


Constraints:
0 <= n <= 5 * 106
*/

#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int n)
{
    if (n < 2)
    {
        return false;
    }

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

int BruteCountPrimes(int n)
{
    int count = 0;

    for (int i = 2; i <= n; i++)
    {
        if (isPrime(i))
        {
            count++;
        }
    }

    return count;
}

// Sieve of Eratosthenes

int OptimalCountPrimes(int n)
{
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (long long i = 2; i * i <= n; i++)
    {
        if (isPrime[i])
        {
            for (long long j = i * i; j <= n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    int count = 0;

    for (int i = 0; i <= n; i++)
    {
        if (isPrime[i])
        {
            count++;
        }
    }

    return count;
}

int main()
{
    int n = 50;

    cout << "BRUTE: The number of prime numbers till n are: " << BruteCountPrimes(n);
    cout << "\nOPTIMAL: The number of prime numbers till n are: " << OptimalCountPrimes(n);

    return 0;
}