/*
135. Candy

There are n children standing in a line.

Each child is assigned a rating value given in the integer array ratings.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute the candies to the children.

Example 1:
Input: ratings = [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.

Example 2:
Input: ratings = [1,2,2]
Output: 4
Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
The third child gets 1 candy because it satisfies the above two conditions.


Constraints:
1 <= n == ratings.length <= 5 * 104
0 <= ratings[i] <= 5 * 104
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int BruteCandy(vector<int> &ratings)
{
    int n = ratings.size();

    if (n == 0)
    {
        return 0;
    }

    vector<int> left(n, 1);
    vector<int> right(n, 1);

    for (int i = 1; i < n; i++)
    {
        if (ratings[i] > ratings[i - 1])
        {
            left[i] = left[i - 1] + 1;
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        if (ratings[i] > ratings[i + 1])
        {
            right[i] = right[i + 1] + 1;
        }
    }

    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += max(left[i], right[i]);
    }

    return sum;
}

int BetterCandy(vector<int> &ratings)
{
    int n = ratings.size();

    if (n == 0)
    {
        return 0;
    }

    vector<int> left(n, 1);

    for (int i = 1; i < n; i++)
    {
        if (ratings[i] > ratings[i - 1])
        {
            left[i] = left[i - 1] + 1;
        }
    }

    int right = 1;
    int sum = left[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        if (ratings[i] > ratings[i + 1])
        {
            right++;
        }
        else
        {
            right = 1;
        }

        sum += max(left[i], right);
    }

    return sum;
}

int OptimalCandy(vector<int> &ratings)
{
    int n = ratings.size();

    if (n == 0)
    {
        return 0;
    }

    int sum = 1;
    int i = 1;

    while (i < n)
    {
        if (ratings[i] == ratings[i - 1])
        {
            sum += 1;
            i++;
            continue;
        }

        int peak = 1;

        while (i < n && ratings[i] > ratings[i - 1])
        {
            peak++;
            sum += peak;
            i++;
        }

        int down = 1;

        while (i < n && ratings[i] < ratings[i - 1])
        {
            sum += down;
            down++;
            i++;
        }

        if (down > peak)
        {
            sum += down - peak;
        }
    }

    return sum;
}

int main()
{
    vector<int> ratings = {1, 2, 3, 2, 1};

    int ans1 = BruteCandy(ratings);
    cout << "BRUTE: The minimum number of candies are: " << ans1 << endl;

    int ans2 = BetterCandy(ratings);
    cout << "BETTER: The minimum number of candies are: " << ans2 << endl;

    int ans3 = OptimalCandy(ratings);
    cout << "OPTIMAL: The minimum number of candies are: " << ans3 << endl;

    return 0;
}