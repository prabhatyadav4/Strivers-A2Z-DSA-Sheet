/*
M-Coloring Problem

You are given an undirected graph consisting of V vertices and E edges represented by a list edges[][], along with an integer m.
Your task is to determine whether it is possible to color the graph using at most m different colors such that no two adjacent vertices share the same color.
Return true if the graph can be colored with at most m colors, otherwise return false.

Note: The graph is indexed with 0-based indexing.

Examples:
Input: V = 4, edges[][] = [[0, 1], [1, 3], [2, 3], [3, 0], [0, 2]], m = 3
Output: true
Explanation: It is possible to color the given graph using 3 colors, for example, one of the possible ways vertices can be colored as follows:
Vertex 0: Color 1
Vertex 1: Color 2
Vertex 2: Color 2
Vertex 3: Color 3

Input: V = 3, edges[][] = [[0, 1], [1, 2], [0, 2]], m = 2
Output: false
Explanation: It is not possible to color the given graph using only 2 colors because vertices 0, 1, and 2 form a triangle.

Constraints:
1 ≤ V ≤ 10
1 ≤ E = edges.size() ≤ (V*(V-1))/2
0 ≤ edges[i][j] ≤ V-1
1 ≤ m ≤ V
*/

#include <iostream>
#include <vector>
using namespace std;

bool goodColor(vector<int> adj[], vector<int> col)
{
    for (int i = 0; i < col.size(); i++)
    {
        for (auto it : adj[i])
        {
            if (i != it && col[i] == col[it])
                return false;
        }
    }

    return true;
}

bool generateColor(int i, vector<int> &col, int m, vector<int> adj[])
{
    if (i >= col.size())
    {
        if (goodColor(adj, col))
            return true;

        return false;
    }

    for (int j = 0; j < m; j++)
    {
        col[i] = j;
        if (generateColor(i + 1, col, m, adj))
            return true;
        col[i] = -1;
    }

    return false;
}

bool BruteGraphColoring(int v, vector<vector<int>> &edges, int m)
{
    vector<int> adj[v];

    for (auto it : edges)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    vector<int> color(v, -1);
    return generateColor(0, color, m, adj);
}

bool isSafe(int vertex, int col, vector<int> adj[], vector<int> &color)
{
    for (auto it : adj[vertex])
    {
        if (color[it] != -1 && col == color[it])
        {
            return false;
        }
    }

    return true;
}

bool canColor(int vertex, int m, vector<int> adj[], vector<int> &color)
{
    if (vertex == color.size())
    {
        return true;
    }

    for (int i = 0; i < m; i++)
    {
        if (isSafe(vertex, i, adj, color))
        {
            color[vertex] = i;
            if (canColor(vertex + 1, m, adj, color))
            {
                return true;
            }
            color[vertex] = -1;
        }
    }

    return false;
}

bool OptimalGraphColoring(int v, vector<vector<int>> &edges, int m)
{
    vector<int> adj[v];

    for (auto it : edges)
    {
        adj[it[0]].push_back((it[1]));
        adj[it[1]].push_back((it[0]));
    }

    vector<int> color(v, -1);
    return canColor(0, m, adj, color);
}

int main()
{
    int V = 4;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {0, 3}, {1, 3}, {2, 3}};
    int m = 3;

    cout << (BruteGraphColoring(V, edges, m) ? "true" : "false") << endl;
    cout << (OptimalGraphColoring(V, edges, m) ? "true" : "false") << endl;

    return 0;
}