// Byteland has n cities and m flight connections. Your task is to design a round trip that begins in a city, goes through one or more other cities, and finally returns to the starting city. Every intermediate city on the route has to be distinct.
// Input
// The first input line has two integers n and m: the number of cities and flights. The cities are numbered 1,2,\dots,n.
// Then, there are m lines describing the flights. Each line has two integers a and b: there is a flight connection from city a to city b. All connections are one-way flights from a city to another city.
// Output
// First print an integer k: the number of cities on the route. Then print k cities in the order they will be visited. You can print any valid solution.
// If there are no solutions, print "IMPOSSIBLE".
// Constraints

// 1 \le n \le 10^5
// 1 \le m \le 2 \cdot 10^5
// 1 \le a,b \le n

// Example
// Input:
// 4 5
// 1 3
// 2 1
// 2 4
// 3 2
// 3 4

// Output:
// 4
// 2 1 3 2


#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<vector<int>>& graph,
         vector<int>& res, vector<int>& state,
         bool& hasCycle, int& start, int& end) {
	state[node] = 1;
	res.push_back(node);

	for(auto neighbour: graph[node]) {
		if(state[neighbour] == 2) continue;
		else if(state[neighbour] == 1) {
			start = neighbour;
			end = node;
			return true;
		} else {
			if(dfs(neighbour,graph,res,state,hasCycle,start,end)) return true;
		}
	}
	res.pop_back();
	state[node] = 2;
	return false;

}

vector<int> roundTrip(vector<vector<int>>& graph) {
	int n = graph.size()-1;
	vector<int> state(n+1, 0);
	vector<int> res;
	bool hasCycle = false;
	int start = -1, end = -1;

	for(int i=1; i<=n; i++) {
		if(state[i] == 0) {
			res.clear();
			if(dfs(i,graph,res,state,hasCycle,start,end)) break;
		}
	}

	vector<int> cycle;
	bool found = false;
	for(int node: res) {
		if(node == start) found = true;
		if(found) cycle.push_back(node);
	}
	cycle.push_back(start);

	return cycle;
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


	vector<int> cycleNodes = roundTrip(graph);

	if(cycleNodes.empty()) {
		cout << "IMPOSSIBLE";
	} else {
		cout <<cycleNodes.size() << "\n";
		for(int node : cycleNodes) cout << node << " ";
	}

	return 0;
}