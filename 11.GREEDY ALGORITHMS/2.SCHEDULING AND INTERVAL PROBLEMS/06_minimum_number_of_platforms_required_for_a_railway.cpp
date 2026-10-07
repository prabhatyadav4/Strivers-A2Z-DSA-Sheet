/*
150. Minimum number of platforms required for a railway

Given the arrival and departure times of all trains reaching a particular railway station, determine the minimum number of platforms required so that no train is kept waiting. Consider all trains arrive and depart on the same day.

In any particular instance, the same platform cannot be used for both the departure of one train and the arrival of another train, necessitating the use of different platforms in such cases.

Note: Time intervals are in the minutes , Leading zeros for minutes less than 1000 are optional (e.g., 0900 is the same as 900).

Example 1:
Input : Arrival = [900, 940, 950, 1100, 1500, 1800] , Departure = [910, 1200, 1120, 1130, 1900, 2000]

Output : 3

Explanation : The first , second , fifth number train can use the platform 1.

The third and sixth train can use the platform 2.
The fourth train will use platform 3.
So total we need 3 different platforms for the railway station so that no train is kept waiting.

Example 2:
Input : Arrival = [900, 1100, 1235] , Departure = [1000, 1200, 1240]

Output : 1

Explanation : All the three trains can use the platform 1.

So we required only 1 platform.

Constraints:
1 <= N <= 105
0000 <= Arrival[i] <= Departure[i] <= 2359
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int BruteFindPlatform(vector<int> &arr, vector<int> &dep)
{
    int n = arr.size();

    int minimumPlatform = 0;

    for (int i = 0; i < n; i++)
    {
        int presentTrain = 0;

        for (int j = 0; j < n; j++)
        {
            if (arr[j] <= arr[i] && dep[j] >= arr[i])
            {
                presentTrain++;
            }
        }

        minimumPlatform = max(minimumPlatform, presentTrain);
    }

    return minimumPlatform;
}

int OptimalFindPlatform(vector<int> &arr, vector<int> &dep)
{
    int n = arr.size();

    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int arrIndex = 0;
    int depIndex = 0;
    int currentPlatform = 0;
    int answer = 0;

    while (arrIndex < n && depIndex < n)
    {
        if (arr[arrIndex] <= dep[depIndex])
        {
            currentPlatform++;
            answer = max(answer, currentPlatform);
            arrIndex++;
        }
        else
        {
            currentPlatform--;
            depIndex++;
        }
    }

    return answer;
}

int main()
{
    vector<int> arr = {900, 940, 950, 1100, 1500, 1800};
    vector<int> dep = {910, 1200, 1120, 1130, 1900, 2000};

    int ans1 = BruteFindPlatform(arr, dep);
    cout << "BRUTE: The minimum number of platform required are: " << ans1 << endl;

    int ans2 = OptimalFindPlatform(arr, dep);
    cout << "OPTIMAL: The minimum number of platform required are: " << ans2 << endl;

    return 0;
}