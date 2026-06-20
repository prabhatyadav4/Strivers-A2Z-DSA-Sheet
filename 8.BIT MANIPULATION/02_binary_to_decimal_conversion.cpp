/*
Binary to Decimal Conversion:

Converting a binary number back to its decimal equivalent involves a reverse process.

Example: Converting 1101 to its decimal equivalent:

        Start from the rightmost bit (least significant bit).
        Each bit is multiplied by 2 raised to the power of its position index.

1 * 2^0 = 1
0 * 2^1 = 0
1 * 2^2 = 4
1 * 2^3 = 8

Sum = 1 + 0 + 4 + 8 = 13.

Hence, the decimal equivalent of the binary number 1101 is 13.
*/

// TC -> O(N)       SC -> O(1)

#include <iostream>
#include <string>
using namespace std;

int binaryToDecimal(string binary)
{
    int len = binary.length();
    int num = 0;
    int power = 1;

    for (int i = len - 1; i >= 0; i--)
    {
        if (binary[i] == '1')
        {
            num += power;
        }

        power *= 2;
    }

    return num;
}

int main()
{
    string binary = "1011";

    cout << "The decimal equivalent of the binary number 1101 is " << binaryToDecimal(binary);

    return 0;
}