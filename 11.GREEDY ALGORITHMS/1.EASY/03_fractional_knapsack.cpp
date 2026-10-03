/*
174. Fractional Knapsack

You have n items; the i-th item has value val[i] and weight wt[i].

A knapsack can carry at most capacity units of weight.

You may take any fraction of an item (i.e. split items).

Return the maximum total value that can be placed in the knapsack, rounded to exactly 6 decimal places.

Example 1:
Input: val = [60,100,120], wt = [10,20,30], capacity = 50

Output: 240.000000

Explanation:

 • Take item 0 (w=10, v=60)

 • Take item 1 (w=20, v=100)

 • Take 2⁄3 of item 2 (w=20, v=80)

Total value = 60 + 100 + 80 = 240

Example 2:
Input: val = [60,100], wt = [10,20], capacity = 50

Output: 160.000000

Explanation: Both items fit entirely (total weight 30 ≤ 50).

Constraints:
1 ≤ n = val.length = wt.length ≤ 105
1 ≤ capacity ≤ 109
1 ≤ val[i], wt[i] ≤ 10 000
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

bool compare(const vector<int> &a, const vector<int> &b)
{
    double a1 = (1.0 * a[0]) / a[1];
    double b1 = (1.0 * b[0]) / b[1];

    return a1 > b1;
}

double fractionalKnapsack(vector<int> &val, vector<int> &wt, int capacity)
{
    int n = val.size(); 

    vector<vector<int>> items(n, vector<int>(2));

    for (int i = 0; i < n; i++)
    {
        items[i][0] = val[i];
        items[i][1] = wt[i];
    }

    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;
    int remainingCapacity = capacity;

    for (const auto &item : items)
    {
        int value = item[0];
        int weight = item[1];

        if (weight <= remainingCapacity)
        {
            totalValue += value;
            remainingCapacity -= weight;
        }
        else
        {
            totalValue += (1.0 * value / weight) * remainingCapacity;
            break;
        }
    }

    return totalValue;
}

int main()
{
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int capacity = 50;

    cout << fixed << setprecision(6);
    cout << "The maximum value the knapsack can hold is: " << fractionalKnapsack(val, wt, capacity) << endl;

    return 0;
}