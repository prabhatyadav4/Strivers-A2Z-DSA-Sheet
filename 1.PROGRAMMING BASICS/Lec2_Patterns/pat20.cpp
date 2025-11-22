#include <iostream>
using namespace std;

/*

Example Output for n = 4:

*      *
**    **
***  ***
********
***  ***
**    **
*      *

*/

// Prints a mirrored hourglass star pattern
void pattern20(int n)
{
    int spaces = 2 * n - 2; // initial spaces between star groups

    for (int i = 1; i <= 2 * n - 1; i++)
    {
        int stars = (i <= n) ? i : 2 * n - i; // stars increase then decrease

        // left stars
        for (int j = 1; j <= stars; j++)
            cout << "*";

        // middle spaces
        for (int j = 1; j <= spaces; j++)
            cout << " ";

        // right stars
        for (int j = 1; j <= stars; j++)
            cout << "*";

        cout << endl;

        // adjust spaces each row
        if (i < n)
            spaces -= 2;
        else
            spaces += 2;
    }
}

int main() {
    int n;
    cout << "Enter the size of pattern: ";
    cin >> n;          // read size
    pattern20(n);      // print pattern
    return 0;
}