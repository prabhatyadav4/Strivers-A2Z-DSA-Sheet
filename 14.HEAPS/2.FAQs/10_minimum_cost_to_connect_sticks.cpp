/*
352. Minimum Cost to Connect Sticks

You have some sticks with positive integer lengths. You can connect any two sticks together to form a longer stick by paying a cost equal to the sum of their lengths.
You must connect all the sticks into one single stick.

Return the minimum cost of connecting all the sticks.

Example 1:
Input: sticks = [2, 4, 3]

Output: 14

Explanation:

Connect sticks 2 and 3 → cost = 2 + 3 = 5 (sticks = [5, 4]),

Connect sticks 4 and 5 → cost = 4 + 5 = 9 (sticks = [9]),

Total cost = 5 + 9 = 14

Example 2:
Input: sticks = [1, 8, 3, 5]

Output: 30

Explanation:

Connect 1 and 3 → cost = 1 + 3 = 4 (sticks = [4, 8, 5]),

Connect 4 and 5 → cost = 4 + 5 = 9 (sticks = [9, 8]),

Connect 8 and 9 → cost = 8 + 9 = 17 (sticks = [17]),

Total cost = 4 + 9 + 17 = 30

Constraints:
1 <= sticks.length <= 104
1 <= stcks[i] <= 104
*/

#include <iostream>
#include <queue>
using namespace std;

int minCost(vector<int> &sticks)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int num : sticks)
    {
        pq.push(num);
    }

    int cost = 0;

    while (pq.size() > 1)
    {
        int min1 = pq.top();
        pq.pop();

        int min2 = pq.top();
        pq.pop();

        cost += (min1 + min2);

        pq.push(min1 + min2);
    }

    return cost;
}

int main()
{
    vector<int> sticks = {1, 8, 3, 5};

    cout << "The minimum cost of connecting all the sticks is: " << minCost(sticks) << endl;

    return 0;
}