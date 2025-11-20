#include <iostream>
using namespace std;

// While Loop
int main(){
    int i = 1;
    // Print "Striver" 5 times while i <= 5
    while (i <=5){
        cout << "Striver" << i << endl;
        i = i + 1;
    }
    cout << i << endl;  // Output: 6
    return 0;
}

// Do While Loop
int main(){
    int i = 1;
    // Execute loop body first, then check condition
    do{
        cout << "Striver" << i << endl;
        i = i + 1;
    }while(i <= 5);
    cout << i << endl;  // Output: 6
    return 0;
}