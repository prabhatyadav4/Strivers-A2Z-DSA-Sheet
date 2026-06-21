/*
One's Complement

The one's complement of a binary number is obtained by flipping all the bits.

Example: The one's complement of 13 (binary 1101):

Binary of 13     : 0000 1101
One's Complement : 1111 0010
*/

#include <iostream>
using namespace std;

string onesComplement(string binary)
{
    for (int i = 0; i < binary.length(); i++)
    {
        if (binary[i] == '0')
        {
            binary[i] ='1';
        }
        else
        {
            binary[i] = '0';
        }
    }

    return binary;
}

int main()
{
    string binary = "1101";

    cout << "The one's complement of 13 (binary 1101): " << onesComplement(binary);

    return 0;
}