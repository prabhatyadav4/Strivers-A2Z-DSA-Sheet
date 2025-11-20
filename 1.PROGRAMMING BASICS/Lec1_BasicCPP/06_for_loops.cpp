#include <iostream>
using namespace std;

int main(){
    int i; // Declare loop variable
    // Loop from 1 to 5
    for (i = 1; i <= 5; i = i + 1){
        cout << "Striver" << i << endl; // Print "Striver" with current value
    }
    cout << i <<  endl; // Print final value of i (which is 6)
    return 0;
}
