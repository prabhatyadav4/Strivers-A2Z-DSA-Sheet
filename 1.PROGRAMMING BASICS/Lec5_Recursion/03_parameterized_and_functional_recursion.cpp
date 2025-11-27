#include <iostream>
using namespace std;

// I. Sum of first N number

// 1. Parameterized way
void psum(int i, int sum){
    if(i < 1){
        cout << sum;
        return;
    }
    psum(i-1, sum+i);
}

int main(){
    int n;
    cout << "Enter the number: ";
    cin >> n;
    psum(n, 0);

    return 0;
}

// 2. Functional way
int fsum(int n){
    if(n == 0){
        return 0;
    }
    return (n + fsum(n-1));
}

int main(){
    int n;
    cout << "Enter the number: ";
    cin >> n;
    cout << fsum(n);

    return 0;
}

// II. Factorial of N number

int ffact(int n){
    if(n == 0){
        return 1;
    }
    return (n*ffact(n-1));
}

int main(){
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << ffact(n);

    return 0;
}