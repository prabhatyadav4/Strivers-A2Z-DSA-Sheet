#include <iostream>
using namespace std;

/*
Example 1:
Infinite Recursion (NO BASE CONDITION)
Calling f1() will cause stack overflow.
We will NOT call this in main().
*/
void f1() {
    cout << 1;
    f1(); // infinite recursion (NO base case)
}

/*
Example 2:
Proper Recursion WITH Base Condition
This will print: 0 1 2 3
*/
int cnt = 0;  // global counter

void f2() {
    if (cnt == 4) {   // Base condition to stop recursion
        return;
    }

    cout << cnt;
    cnt++;
    f2();   // recursive call
}

int main() {

    // DO NOT CALL f1() → It causes infinite recursion and crashes
    // f1();  

    // SAFE recursive function
    f2();

    return 0;
}