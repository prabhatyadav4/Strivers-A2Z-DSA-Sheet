/*
Remove the Last Set Bit (Rightmost Set Bit)

num = num & (num - 1);
*/

#include <iostream>
using namespace std;

int main()
{
    int num = 13;

    num = num & (num - 1);

    cout << num;

    return 0;
}