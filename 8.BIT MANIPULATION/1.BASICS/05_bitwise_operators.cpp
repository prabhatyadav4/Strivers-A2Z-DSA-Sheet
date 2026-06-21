/*
Bitwise Operators

AND Operator (&)

If both corresponding bits are 1, the resulting bit is 1; otherwise, it is 0.

13: 1101
 7: 0111
&  : 0101 → 5

OR Operator (|)

If either corresponding bit is 1, the resulting bit is 1.

13: 1101
 7: 0111
|  : 1111 → 15

XOR Operator (^)

If bits differ, the result is 1; if the same, result is 0.

13: 1101
 7: 0111
^  : 1010 → 10

NOT Operator (~)

Flips all bits of the number.

 5: 0000 0101
~5: 1111 1010 → -6 (in two's complement)

Shift Operators

Right Shift (>>): Shifts bits to the right, fills left with 0s.

13 >> 1 = 0110 → 6

Left Shift (<<): Shifts bits to the left, fills right with 0s.

13 << 1 = 11010 → 26
*/

#include <iostream>
using namespace std;

int main()
{
    int a = 13, b = 7;

    // AND Operator (&) -> all true = true, 1 false = false
    cout << "AND (&): " << a << " & " << b << " = " << (a & b) << endl;

    // OR Operator (|) -> one true = true, all false = false
    cout << "OR (|): " << a << " | " << b << " = " << (a | b) << endl;

    // XOR Operator (^) -> no. of 1's -> odd -> 1, no. of 1's -> even -> 0
    cout << "XOR (^): " << a << " ^ " << b << " = " << (a ^ b) << endl;

    // NOT Operator (~)
    int x = 5;
    cout << "NOT (~): ~" << x << " = " << (~x) << endl;

    // Right Shift (>>) -> x  >> k  = x / 2^k
    cout << "Right Shift (>>): " << a << " >> 1 = " << (a >> 1) << endl;

    // Left Shift (<<) -> x  >> k  = x * 2^k
    cout << "Left Shift (<<): " << a << " << 1 = " << (a << 1) << endl;

    return 0;
}