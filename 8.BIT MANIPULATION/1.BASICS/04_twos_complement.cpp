/*
Two's Complement

The two's complement is obtained by taking the one's complement of a number and adding 1.

Example: The two's complement of 13 (binary 1101):

One's Complement : 0010
Add 1            : 0011
*/

#include <iostream>
using namespace std;

string twosComplement(string binary)
{

    // One's Complement
    for (char &bit : binary)
    {
        bit = (bit == '0') ? '1' : '0';
    }

    int carry = 1;

    for (int i = binary.length() - 1; i >= 0 && carry; i--)
    {
        if (binary[i] == '0')
        {
            binary[i] = '1';
            carry = 0;
        }
        else
        {
            binary[i] = '0';
        }
    }

    if (carry)
    {
        binary = '1' + binary;
    }

    return binary;
}

int main()
{
    string binary = "1101";

    cout << "The two's complement of 13 (binary 1101) is: " << twosComplement(binary);

    return 0;
}