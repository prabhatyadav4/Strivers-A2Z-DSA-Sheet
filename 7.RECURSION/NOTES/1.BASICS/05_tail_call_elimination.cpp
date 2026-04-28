/*
// Non-tail-recursive factorial function

#include <iostream>
using namespace std;

int fact(int n)
{
    if (n <= 0)
        return 1;

    // Recursive call is not the last operation
    return n * fact(n - 1);
}

int main()
{
    // Testing the factorial function
    cout << fact(5);
    return 0;
}

// Tail Recursive of factorial function

#include <iostream>
using namespace std;

int factTC(int n, int accumulator) {
    if(n <= 1) return accumulator;
    
    return factTC(n-1, n * accumulator);
}

int fact(int n) {
    return factTC(n, 1);
}

int main() {
    int n = 5;
    cout << "The factorial of n is: " << fact(n);
    
    return 0;
}
*/

// Tail Call Elimination

#include <iostream>
using namespace std;

int fact(int n) {
    int result = 1;
    while(n >= 1) {
        result = result * n;
        n--;
    }

    return result;
}

int main() {
    int n = 5;
    cout << "The factorial of n is: " << fact(n);

    return 0;
}