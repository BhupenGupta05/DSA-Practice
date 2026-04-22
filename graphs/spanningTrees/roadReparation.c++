// There are n cities and m roads between them. Unfortunately, the condition of the roads is so poor that they cannot be used. Your task is to repair some of the roads so that there will be a decent route between any two cities.
// For each road, you know its reparation cost, and you should find a solution where the total cost is as small as possible.
// Input
// The first input line has two integers n and m: the number of cities and roads. The cities are numbered 1,2,\dots,n.
// Then, there are m lines describing the roads. Each line has three integers a, b and c: there is a road between cities a and b, and its reparation cost is c. All roads are two-way roads.
// Every road is between two different cities, and there is at most one road between two cities.
// Output
// Print one integer: the minimum total reparation cost. However, if there are no solutions, print "IMPOSSIBLE".
// Constraints

// 1 \le n \le 10^5
// 1 \le m \le 2 \cdot 10^5
// 1 \le a,b \le n
// 1 \le c \le 10^9

// Example
// Input:
// 5 6
// 1 2 3
// 2 3 5
// 2 4 2
// 3 4 8
// 5 1 7
// 5 4 4

// Output:
// 14

#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    long long u, v, w;
};

int parent[100005], sz[100005];

long long find(long long x)
{
    if (x == parent[x])
        return x;
    return parent[x] = find(parent[x]);
}

bool same(long long a, long long b)
{
    return find(a) == find(b);
}

void unite(long long a, long long b)
{
    a = find(a);
    b = find(b);

    if (a == b)
        return;
    if (sz[a] < sz[b])
        swap(a, b);
    sz[a] += sz[b];
    parent[b] = a;
}

int main()
{
    long long n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (auto &e : edges)
    {
        cin >> e.u >> e.v >> e.w;
    }

    sort(edges.begin(), edges.end(), [](auto &a, auto &b)
         { return a.w < b.w; });

    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        sz[i] = 1;
    }

    long long mst_wt = 0;
    long long edges_added = 0;

    for (auto &e : edges)
    {
        if (!same(e.u, e.v))
        {
            unite(e.u, e.v);
            mst_wt += e.w;
            edges_added++;
        }
        if (edges_added == n - 1)
            break;
    }

    if (edges_added != n - 1)
    {
        cout << "IMPOSSIBLE\n";
    }
    else
    {
        cout << mst_wt << "\n";
    }

    return 0;
}