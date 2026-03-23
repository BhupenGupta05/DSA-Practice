// Kahn's Algorithm for Topological Sorting

#include <bits/stdc++.h>
using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
{
    int n = numCourses;
    vector<vector<int>> graph(n);
    vector<int> indegree(n, 0);

    for (auto pair : prerequisites)
    {
        int pre = pair[1];
        int next = pair[0];
        graph[pre].push_back(next);
    }

    for (int u = 0; u < n; u++)
    {
        for (auto v : graph[u])
        {
            indegree[v]++;
        }
    }

    queue<int> q;
    for (int u = 0; u < n; u++)
    {
        if (indegree[u] == 0)
        {
            q.push(u);
        }
    }

    vector<int> res;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        res.push_back(node);

        for (int neighbour : graph[node])
        {
            indegree[neighbour]--;
            if (indegree[neighbour] == 0)
            {
                q.push(neighbour);
            }
        }
    }

    if (res.size() != numCourses)
        return {};
    return res;
}