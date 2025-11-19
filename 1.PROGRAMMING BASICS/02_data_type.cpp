#include <iostream>
using namespace std;

int main(){
    // Integer variable
    int x = 10;
    cout << x << endl;
    
    // Long integer variable
    long y = 1000000000;
    cout << y << endl;
    
    // Long long integer variable for large numbers
    long long z = 100000000000000000;
    cout << z << endl;

    // Float variable (single precision)
    float a = 8.9;
    cout << a << endl;
    
    // Double variable (double precision)
    double b = 8.8444444444555;
    cout << b << endl;

    // String variables
    string s1;
    string s2;
    cin >> s1 >> s2;
    cout << s1 << " " << s2 << endl;

    // Read entire line including spaces
    string str;
    getline(cin, str);
    cout << str << endl;

    // Character variable
    char ch = 'g';
    cout << ch << endl;

    return 0;
}