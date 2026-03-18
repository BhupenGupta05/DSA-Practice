// Syrjälä's network has n computers and m connections. Your task is to find out if Uolevi can send a message to Maija, and if it is possible, what is the minimum number of computers on such a route.
// Input
// The first input line has two integers n and m: the number of computers and connections. The computers are numbered 1,2,\dots,n. Uolevi's computer is 1 and Maija's computer is n.
// Then, there are m lines describing the connections. Each line has two integers a and b: there is a connection between those computers.
// Every connection is between two different computers, and there is at most one connection between any two computers.
// Output
// If it is possible to send a message, first print k: the minimum number of computers on a valid route. After this, print an example of such a route. You can print any valid solution.
// If there are no routes, print "IMPOSSIBLE".
// Constraints

// 2 \le n \le 10^5
// 1 \le m \le 2 \cdot 10^5
// 1 \le a,b \le n

// Example
// Input:
// 5 5
// 1 2
// 1 3
// 1 4
// 2 3
// 5 4

// Output:
// 3
// 1 4 5

// It is same as finding if we can traverse from src to dest and finding the path for it by reconstruction


#include <bits/stdc++.h>
using namespace std;

pair<int,vector<int>> messageRoute(vector<vector<int>>& graph, int src) {
	int n = graph.size()-1;
	int pathLen = -1;
	vector<int> path;
	vector<int> parent(n+1, -1);

	vector<bool> visited(n+1, false);
	queue<pair<int,int>> toVisit;
	toVisit.push({0,src});
	visited[src] = true;


	while(!toVisit.empty()) {
		auto [dist,node] = toVisit.front();
		toVisit.pop();

		if(node == n) {
			pathLen = dist;
			break;
		}

		for(auto neighbours: graph[node]) {
			if(!visited[neighbours]) {
				visited[neighbours] = true;
				toVisit.push({dist+1,neighbours});
				parent[neighbours] = node;
			}
		}
	}
	
	if(pathLen == -1) return {-1, {}};

	int curr = n;
	while(curr != -1) {
		path.push_back(curr);
		curr = parent[curr];
	}

	reverse(path.begin(), path.end());
	return {path.size(),path};
}

int main()
{
	int n,m;
	cin>>n>>m;
	
	for(int i=0; i<m; i++) {
	    int a,b;
	    cin>>a>>b;
	    graph[a].push_back(b);
	    graph[b].push_back(a);
	}

	auto[computers,path] = messageRoute(graph,1);

	if(computers == -1) cout<<"IMPOSSIBLE";
	else {
		cout<<computers<<"\n";

		for(auto x: path) {
			cout<<x<<" ";
		}
	}


	return 0;
}