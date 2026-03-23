// A game has n levels, connected by m teleporters, and your task is to get from level 1 to level n. The game has been designed so that there are no directed cycles in the underlying graph. In how many ways can you complete the game?
// Input
// The first input line has two integers n and m: the number of levels and teleporters. The levels are numbered 1,2,\dots,n.
// After this, there are m lines describing the teleporters. Each line has two integers a and b: there is a teleporter from level a to level b.
// Output
// Print one integer: the number of ways you can complete the game. Since the result may be large, print it modulo 10^9+7.
// Constraints

// 1 \le n \le 10^5
// 1 \le m \le 2 \cdot 10^5
// 1 \le a,b \le n

// Example
// Input:
// 4 5
// 1 2
// 2 4
// 1 3
// 3 4
// 1 4

// Output:
// 3


#include <bits/stdc++.h>
using namespace std;

vector<int> topologicalOrder(vector<vector<int>>& graph) {
	int n = graph.size()-1;
	vector<int> indegree(n+1, 0);

	for (int u = 1; u <= n; u++) {
		for (auto v : graph[u]) {
			indegree[v]++;
		}
	}

	queue<int> q;
	for (int u = 1; u <= n; u++) {
		if (indegree[u] == 0) {
			q.push(u);
		}
	}

	vector<int> res;
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		res.push_back(node);

		for (int neighbour : graph[node]) {
			indegree[neighbour]--;
			if (indegree[neighbour] == 0) {
				q.push(neighbour);
			}
		}
	}

	if(res.size() != n) return {};
	return res;
}

long long gameRoutes(vector<vector<int>>& graph) {
	int n = graph.size()-1;
	vector<int> paths(n+1,0);
	paths[1] = 1;
	vector<int> order = topologicalOrder(graph);
	
	for(int node: order) {
	    for(auto neighbour: graph[node]) {
	        paths[neighbour] += paths[node];
	    }
	}
	return paths[n];
}

int main()
{
	int n,m;
	cin>>n>>m;

	vector<vector<int>> graph(n+1);

	for(int i=0; i<m; i++) {
		int a,b;
		cin>>a>>b;

		graph[a].push_back(b);
	}


	long long paths = gameRoutes(graph);
	cout<<paths;
	return 0;
}
