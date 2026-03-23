// You are given a directed graph, and your task is to find out if it contains a negative cycle, and also give an example of such a cycle.
// Input
// The first input line has two integers n and m: the number of nodes and edges. The nodes are numbered 1,2,\ldots,n.
// After this, the input has m lines describing the edges. Each line has three integers a, b, and c: there is an edge from node a to node b whose length is c.
// Output
// If the graph contains a negative cycle, print first "YES", and then the nodes in the cycle in their correct order. If there are several negative cycles, you can print any of them. If there are no negative cycles, print "NO".
// Constraints

// 1 \le n \le 2500
// 1 \le m \le 5000
// 1 \le a,b \le n
// -10^9 \le c \le 10^9

// Example
// Input:
// 4 5
// 1 2 1
// 2 4 1
// 3 1 1
// 4 1 -3
// 4 3 -2

// Output:
// YES
// 1 2 4 1

#include <bits/stdc++.h>
using namespace std;

vector<int> cycleFinding(int n, vector<tuple<int,int,long long>>& edges) {
	const long long INF = LLONG_MAX / 2;
	vector<long long> distance(n+1, INF);
	vector<int> pred(n + 1, -1);
	distance[1] = 0;

	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			for(auto [a,b,x]: edges) {
				if(distance[a] == INF) continue;
				if(distance[a] + x < distance[b]) {
					distance[b] = distance[a] + x;
					pred[b] = a;
				}
			}
		}
	}

	int last = -1;
	for(int i=1; i<=n; i++) {
		for(auto [a,b,x]: edges) {
			if(distance[a] == INF) continue;
			if(distance[a] + x < distance[b]) {
				distance[b] = distance[a] + x;
				pred[b] = a;
				last = b;
			}
		}
	}

	if (last == -1) return {};

	int cycleNode = last;
	for(int i=0; i<n; i++) {
		cycleNode = pred[cycleNode];
	}

	vector<int> cycle;
	int curr = cycleNode;
	while(true) {
		cycle.push_back(curr);
		curr = pred[curr];
		if(curr == cycleNode) break;
	}
	cycle.push_back(cycleNode);
	reverse(cycle.begin(), cycle.end());
	return cycle;
}


int main()
{
	int n,m;
	cin>>n>>m;

	vector<tuple<int,int, long long>> edges(m);


	for(int i=0; i<m; i++) {
		int a,b;
		long long c;
		cin>>a>>b>>c;

		edges[i] = {a,b,c};
	}

	vector<int> ans = cycleFinding(n,edges);

	if (ans.empty()) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
		for (int v : ans) cout << v << " ";
		cout << "\n";
	}

	return 0;
}