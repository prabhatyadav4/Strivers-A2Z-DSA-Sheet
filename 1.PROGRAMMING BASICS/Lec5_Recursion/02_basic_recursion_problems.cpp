#include <iostream>
using namespace std;

// Function to print a name 'n' times using recursion

void printNames(int i, int n){
    if(i > n){
        return;
    }
    cout << "Prabhat ";
    printNames(i+1, n);
}

int main(){
    int n;
    cout << "Enter the no. of times: ";
    cin >> n; // Read the number of times from user
    printNames(1, n); // Call the recursive function

    return 0;
}

// Function to print numbers linearly from 1 to 'n' using recursion

void printNumber(int i, int n){
    if(i > n){
        return;
    }
    cout << i << " ";
    printNumber(i+1, n);
}

int main(){
    int n;
    cout << "Enter the no. of times: ";
    cin >> n; // Read the number from user
    printNumber(1, n); // Call the recursive function

    return 0;
}

// Function to print numbers linearly from 'N' to 1 using recursion
void PrintRevNum(int n){
    if(n < 1){
        return;
    }
    cout << n << " ";
    PrintRevNum(n-1);
}

int main(){
    int n;
    cout << "Enter the no. of times: ";
    cin >> n; // Read the number from user
    PrintRevNum(n); // Call the recursive function

    return 0;
}

// Alternative function to print numbers linearly from 'N' to 1 using recursion

void PrintRevNum(int i, int n){ 
    if(i < 1){ 
        return;
    }
    cout << i << " "; 
    PrintRevNum(i-1, n); 
}

int main(){
    int n;
    cout << "Enter the no. of times: ";
    cin >> n; // Read the number from user
    PrintRevNum(n,n); // Call the recursive function
    return 0;
}

// Function to print numbers linearly from 1 to 'N' using backtracking recursion

void PrintNumBack(int i, int n){
    if(i < 1){
        return;
    }
    PrintNumBack(i-1, n);
    cout << i << " ";
}

int main(){
    int n;
    cout << "Enter the no. of times: ";
    cin >> n; // Read the number from user
    PrintNumBack(n,n); // Call the recursive function

    return 0;
}

// Function to print numbers linearly from 'N' to 1 using backtracking recursion

void PrintNumRevBack(int i, int n){
    if(i > n){
        return;
    }
    PrintNumRevBack(i+1, n);
    cout << i << " ";
}

int main(){
    int n;
    cout << "Enter the no. of times: ";
    cin >> n;
    PrintNumRevBack(1, n);

    return 0;
}