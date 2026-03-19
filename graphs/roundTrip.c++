// Byteland has n cities and m roads between them. Your task is to design a round trip that begins in a city, goes through two or more other cities, and finally returns to the starting city. Every intermediate city on the route has to be distinct.
// Input
// The first input line has two integers n and m: the number of cities and roads. The cities are numbered 1,2,\dots,n.
// Then, there are m lines describing the roads. Each line has two integers a and b: there is a road between those cities.
// Every road is between two different cities, and there is at most one road between any two cities.
// Output
// First print an integer k: the number of cities on the route. Then print k cities in the order they will be visited. You can print any valid solution.
// If there are no solutions, print "IMPOSSIBLE".
// Constraints

// 1 \le n \le 10^5
// 1 \le m \le 2 \cdot 10^5
// 1 \le a,b \le n

// Example
// Input:
// 5 6
// 1 3
// 1 2
// 5 3
// 1 5
// 2 4
// 4 5

// Output:
// 4
// 3 5 1 3

#include <bits/stdc++.h>
using namespace std;

vector<int> cycle;

bool cycleDetection(vector<vector<int>>& graph,
                    int node, int par,
                    vector<int>& parent,vector<bool>& visited) {
	visited[node] = true;

	for(auto neighbour: graph[node]) {
		if(neighbour == par) continue;
		if(visited[neighbour]) {
			int curr = node;
			cycle.push_back(neighbour);

			while(curr != neighbour) {
				cycle.push_back(curr);
				curr = parent[curr];
			}
			cycle.push_back(neighbour);
			return true;
		}
		parent[neighbour] = node;
		if(cycleDetection(graph,neighbour,node,parent,visited)) return true;
	}
	return false;
}

pair<int,vector<int>> roundTrip(vector<vector<int>>& graph) {
	int n = graph.size()-1;
	cycle.clear();

	vector<int> parent(n+1,-1);
	vector<bool> visited(n+1, false);

	for(int i=1; i<=n; i++) {
		if(!visited[i]) {
			if(cycleDetection(graph,i,-1,parent,visited)) {
				return {cycle.size(), cycle};
			}
		}
	}
	return {-1,{}};

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
		graph[b].push_back(a);
	}

	auto [len,ans] = roundTrip(graph);
	
	if(len == -1) cout<<"IMPOSSIBLE";
	else {
	    cout<<len<<"\n";
	    
	    for(auto x: ans) {
	        cout<<x<<" ";
	    }
	}




	return 0;
}