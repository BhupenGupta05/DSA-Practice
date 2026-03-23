// Uolevi has won a contest, and the prize is a free flight trip that can consist of one or more flights through cities. Of course, Uolevi wants to choose a trip that has as many cities as possible.
// Uolevi wants to fly from Syrjälä to Lehmälä so that he visits the maximum number of cities. You are given the list of possible flights, and you know that there are no directed cycles in the flight network.
// Input
// The first input line has two integers n and m: the number of cities and flights. The cities are numbered 1,2,\dots,n. City 1 is Syrjälä, and city n is Lehmälä.
// After this, there are m lines describing the flights. Each line has two integers a and b: there is a flight from city a to city b. Each flight is a one-way flight.
// Output
// First print the maximum number of cities on the route. After this, print the cities in the order they will be visited. You can print any valid solution.
// If there are no solutions, print "IMPOSSIBLE".
// Constraints

// 2 \le n \le 10^5
// 1 \le m \le 2 \cdot 10^5
// 1 \le a,b \le n

// Example
// Input:
// 5 5
// 1 2
// 2 5
// 1 3
// 3 4
// 4 5

// Output:
// 4
// 1 3 4 5

// There are multiple variations of this problem
// 1. Longest path in a DAG (Use max value)
// 2. Shortest path in a DAG (Use min value)
// 3. Number of paths in a DAG (Use += value)
// 4. Count max/min nodes in a path in a DAG (Use max/min value + 1)


#include <bits/stdc++.h>
using namespace std;

vector<int> topologicalOrder(int n, vector<vector<int>>& graph) {
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

pair<int, vector<int>> longestFlightRoute(int n, vector<vector<int>>& graph) {
	vector<int> order = topologicalOrder(n,graph);

	if(order.empty()) return {0, {}}; // Cycle exists

	vector<int> parent(n+1,-1);
	vector<int> res;
	vector<int> paths(n+1,0);
	paths[1] = 1;

	for(int node: order) {
		for(auto neighbour: graph[node]) {
			if(paths[neighbour] < paths[node]+1) {
				paths[neighbour] = paths[node] + 1;
				parent[neighbour] = node;
			}

		}
	}

	int curr = n;
	res.push_back(curr);
	while(curr != 1) {
		curr = parent[curr];
		res.push_back(curr);
	}

	reverse(res.begin(), res.end());
	return {paths[n],res};

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


	auto [cities,route] = longestFlightRoute(n,graph);

	for(int i=0; i<route.size(); i++) {
		cout<<route[i]<<" ";
	}


	return 0;
}