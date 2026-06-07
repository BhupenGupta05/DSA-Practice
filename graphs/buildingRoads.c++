// Byteland has n cities, and m roads between them. The goal is to construct new roads so that there is a route between any two cities.
// Your task is to find out the minimum number of roads required, and also determine which roads should be built.
// Input
// The first input line has two integers n and m: the number of cities and roads. The cities are numbered 1,2,\dots,n.
// After that, there are m lines describing the roads. Each line has two integers a and b: there is a road between those cities.
// A road always connects two different cities, and there is at most one road between any two cities.
// Output
// First print an integer k: the number of required roads.
// Then, print k lines that describe the new roads. You can print any valid solution.
// Constraints

// 1 \le n \le 10^5
// 1 \le m \le 2 \cdot 10^5
// 1 \le a,b \le n

// Example
// Input:
// 4 2
// 1 2
// 3 4

// Output:
// 1
// 2 3

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

void dfs(int node) {
    visited[node] = true;
    for(auto neighbour: graph[node]) {
        if(!visited[neighbour]) {
            dfs(neighbour);
        }
    }
}


int main() {
    int n, m;
    cin >> n >> m;

    graph.resize(n+1);
    visited.assign(n+1,false);
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> reps;
    
    for(int i=1; i<=n; i++) {
        if(!visited[i]) {
            reps.push_back(i);
            dfs(i);
        }
    }
    
    cout << reps.size() - 1 << endl;

    for (int i = 1; i < reps.size(); i++) {
        cout << reps[i - 1] << " " << reps[i] << endl;
    }
    return 0;
}