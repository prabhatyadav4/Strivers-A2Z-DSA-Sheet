/*
160. Job sequencing Problem

Given an 2D array Jobs of size Nx3, where Jobs[i][0] represents JobID , Jobs[i][1] represents Deadline , Jobs[i][2] represents Profit associated with that job. Each Job takes 1 unit of time to complete and only one job can be scheduled at a time.

The profit associated with a job is earned only if it is completed by its deadline. Find the number of jobs and maximum profit.

Example 1:
Input : Jobs = [ [1, 4, 20] , [2, 1, 10] , [3, 1, 40] , [4, 1, 30] ]

Output : 2 60

Explanation : Job with JobID 3 can be performed at time t=1 giving a profit of 40.

Job with JobID 1 can be performed at time t=2 giving a profit of 20.

No more jobs can be scheduled, So total Profit = 40 + 20 => 60.

Total number of jobs completed are two, JobID 1, JobID 3.

So answer is 2 60.

Example 2:
Input : Jobs = [ [1, 2, 100] , [2, 1, 19] , [3, 2, 27] , [4, 1, 25] , [5, 1, 15] ]

Output : 2 127

Explanation : Job with JobID 1 can be performed at time time t=1 giving a profit of 100.

Job with JobID 3 can be performed at time t=2 giving a profit of 27.

No more jobs can be scheduled, So total Profit = 100 + 27 => 127.

Total number of jobs completed are two, JobID 1, JobID 3.

So answer is 2 127.

Let’s go through a few more examples, step by step, to make it clearer.

Constraints:
1 <= N <= 104
1 <= Deadline <= N
1 <= Profit <= 500
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Brute Force      O(N log N + N × D)

vector<int> BruteJobScheduling(vector<vector<int>> &Jobs)
{
    int n = Jobs.size();

    sort(Jobs.begin(), Jobs.end(), [](const vector<int> &first, const vector<int> &second)
         {
        if (first[2] != second[2])
            return first[2] > second[2];

        return first[1] < second[1]; });

    int maxDeadline = 0;

    for (int i = 0; i < n; i++)
    {
        maxDeadline = max(maxDeadline, Jobs[i][1]);
    }

    vector<int> timeline(maxDeadline + 1, -1);

    int countJobs = 0;
    int totalProfit = 0;

    for (int i = 0; i < n; i++)
    {
        for (int slot = Jobs[i][1]; slot > 0; slot--)
        {
            if (timeline[slot] == -1)
            {
                timeline[slot] = Jobs[i][0];

                countJobs++;
                totalProfit += Jobs[i][2];

                break;
            }
        }
    }

    return {countJobs, totalProfit};
}

// Optimal (DSU)        O(N log N + N × α(D)) ≈ O(N log N)

struct Job
{
    int id;
    int deadline;
    int profit;
};

bool comp(Job first, Job second)
{
    if (first.profit != second.profit)
        return first.profit > second.profit;

    return first.deadline < second.deadline;
}

int find(int s, vector<int> &parent)
{
    if (s == parent[s])
    {
        return s;
    }

    return parent[s] = find(parent[s], parent);
}

vector<int> OptimalJobScheduling(vector<int> &deadline, vector<int> &profit)
{
    int n = deadline.size();

    vector<Job> Jobs;
    int maxDeadline = 0;

    for (int i = 0; i < n; i++)
    {
        Jobs.push_back({i + 1, deadline[i], profit[i]});
        maxDeadline = max(maxDeadline, deadline[i]);
    }

    sort(Jobs.begin(), Jobs.end(), comp);

    vector<int> parent(maxDeadline + 1);

    for (int i = 0; i <= maxDeadline; i++)
    {
        parent[i] = i;
    }

    int countJobs = 0;
    int totalProfit = 0;

    for (int i = 0; i < n; i++)
    {
        int availableSlot = find(Jobs[i].deadline, parent);

        if (availableSlot > 0)
        {
            countJobs++;
            totalProfit += Jobs[i].profit;

            parent[availableSlot] = find(availableSlot - 1, parent);
        }
    }

    return {countJobs, totalProfit};
}

int main()
{
    vector<vector<int>> Jobs =
        {
            {1, 4, 20},
            {2, 1, 10},
            {3, 1, 40},
            {4, 1, 30}
        };

    vector<int> deadline = {4, 1, 1, 1};
    vector<int> profit = {20, 10, 40, 30};

    vector<int> bruteResult = BruteJobScheduling(Jobs);

    cout << "Brute Force Approach:" << endl;
    cout << "Number of jobs: " << bruteResult[0] << endl;
    cout << "Maximum profit: " << bruteResult[1] << endl;

    vector<int> optimalResult = OptimalJobScheduling(deadline, profit);

    cout << endl;

    cout << "Optimal Approach:" << endl;
    cout << "Number of jobs: " << optimalResult[0] << endl;
    cout << "Maximum profit: " << optimalResult[1] << endl;

    return 0;
}