/*

*/

#include <iostream>
#include <vector>
using namespace std;

vector<long long> nextLargerElement(vector<long long> arr, int n)
{
    vector<long long> ans(n, -1);

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                ans[i] = arr[j];
                break;
            }
        }
    }

    return ans;
}

int main()
{
    vector<long long> arr = {1, 3, 2, 4};
    int n = 4;

    vector<long long> ans = nextLargerElement(arr, n);

    cout << "The next larger elements are: ";
    for (int res : ans)
    {
        cout << res << " ";
    }
    cout << endl;

    return 0;
}