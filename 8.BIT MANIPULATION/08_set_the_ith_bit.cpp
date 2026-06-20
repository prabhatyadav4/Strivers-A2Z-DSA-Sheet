/*
Setting the i-th Bit

num | (1 << i)
*/

#include <iostream>
using namespace std;

int main()
{
    int num = 13;
    int i = 2;

    num = num | (1 << i);

    cout << num;

    return 0;
}