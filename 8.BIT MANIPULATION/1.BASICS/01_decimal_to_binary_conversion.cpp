/*
Decimal to Binary Conversion

By repeatedly dividing a number by 2 and recording the result, decimal values can be transformed into binary.

Example: Converting 13 to its binary equivalent:

            Start with the decimal number 13.
            Divide the number by 2 and record the remainder.
            Repeat the division with the quotient until the number becomes 0.

13 / 2 = 6 remainder 1
6 / 2 = 3 remainder 0
3 / 2 = 1 remainder 1
1 / 2 = 0 remainder 1

To obtain the binary equivalent of 13, read the remainders from bottom to top: 1101.

So, the binary equivalent of 13 is 1101.
*/

// TC -> O(log2N)     SC -> O(log2N)

#include <iostream>
#include <algorithm>
using namespace std;

string decimalToBinary(int n)
{
    string res = "";

    while (n > 0)
    {

        if (n % 2 == 1)
        {
            res += '1';
        }
        else
        {
            res += '0';
        }

        n = n / 2;
    }

    reverse(res.begin(), res.end());

    return res;
}

int main()
{
    int n = 13;

    cout << "The binary equivalent of n is: " << decimalToBinary(n);

    return 0;
}