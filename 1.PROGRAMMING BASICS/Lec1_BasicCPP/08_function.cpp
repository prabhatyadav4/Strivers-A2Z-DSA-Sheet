#include <iostream>
using namespace std;

// Void and Parameterized Function
// Function that takes a string parameter and prints a greeting
void PrintName(string name){
    cout << "Hey " << name << endl;
}

int main(){
    string name;
    cout << "Enter the name: ";
    cin >> name;
    PrintName(name);

    string name2;
    cout << "Enter another name: ";
    cin >> name2;
    PrintName(name2);

    return 0;
}

// Function that returns the sum of two numbers
int add(int num1, int num2){
    int num3 = num1 + num2;
    return num3;
}

int main(){
    int num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    int res = add(num1, num2);
    cout << "The sum of two numbers are: " << res;

    return 0;
}

// Inbuilt Function - min()
int main(){
    int num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    int minimum = min(num1, num2); // Built-in function to find minimum
    cout << "The minimum number is: " << minimum;

    return 0;
}

// Pass by Value - changes don't affect original variable
void doSomething(int num){
    cout << num << endl;
    num += 5;
    cout << num << endl;
    num += 5;
    cout << num << endl;
}

int main(){
    int num = 10;
    doSomething(num); // num remains 10 after function call
    cout << num;
    return 0;
}

// Pass by Reference - changes affect original variable
void doSomething(string &s){
    s[0] = 'T'; // Modifies original string
    cout << s << endl;
}

int main(){
    string s = "Xwitter";
    doSomething(s);
    cout << s;

    return 0;
}

// Array Pass by Reference - arrays always pass by reference
void doSomething(int arr[], int n){
    arr[0] += 100; // Modifies original array
    cout << "Value inside function: " << arr[0] << endl;
}

int main(){
    int n = 5;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    doSomething(arr,n);
    cout << "Value inside main: " << arr[0] << endl; // Change is reflected here

    return 0;
}