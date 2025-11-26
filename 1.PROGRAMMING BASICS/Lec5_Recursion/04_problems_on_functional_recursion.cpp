#include <iostream>
using namespace std;

// Reverse an array using recursion (two-pointer approach)
void f1(int arr[], int l, int r){
    if (l >= r) {
        return;
    }

    swap(arr[l], arr[r]);

    f1(arr, l + 1, r - 1);
}

int main() {
    int arr[5] = {1, 5, 9, 8, 4};
    f1(arr, 0, 4);

    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

// Reverse an array using recursion (one-pointer approach)
void f2(int arr[], int i, int n){
    if(i >= n/2){
        return;
    }
    swap(arr[i], arr[n-i-1]);
    f2(arr, i+1, n);
}

int main(){
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the element of the array: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    f2(arr, 0, n);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}

// Palindrome Check of a string
bool checkPalindrome(int i, string &s){
    int n = s.size();
    if(i >= n/2) return true;
    if(s[i] != s[n-i-1]) return false;
    return checkPalindrome(i+1, s);
}

int main(){
    string s;
    cout << "Enter a string: ";
    cin >> s;
    if(checkPalindrome(0, s))
        cout << "true";
    else
        cout << "false";

    return 0;
}