// There are n cities and m flight connections between them. Your task is to determine the length of the shortest route from Syrjälä to every city.
// Input
// The first input line has two integers n and m: the number of cities and flight connections. The cities are numbered 1,2,\dots,n, and city 1 is Syrjälä.
// After that, there are m lines describing the flight connections. Each line has three integers a, b and c: a flight begins at city a, ends at city b, and its length is c. Each flight is a one-way flight.
// You can assume that it is possible to travel from Syrjälä to all other cities.
// Output
// Print n integers: the shortest route lengths from Syrjälä to cities 1,2,\dots,n.
// Constraints

// 1 \le n \le 10^5
// 1 \le m \le 2 \cdot 10^5
// 1 \le a,b \le n
// 1 \le c \le 10^9

// Example
// Input:
// 3 4
// 1 2 6
// 1 3 2
// 3 2 3
// 1 3 4

// Output:
// 0 5 2

#include <bits/stdc++.h>
using namespace std;

vector<int> shortestRoute(vector<vector<pair<int,int>>>& graph) {
	int n = graph.size()-1;
	vector<int> distance(n+1,INT_MAX);
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	pq.push({0,1});
	distance[1] = 0;

	while(!pq.empty()) {
		auto [currDist, node] = pq.top();
		pq.pop();

		if(currDist > distance[node]) continue;

		for(auto [wt,neighbour]: graph[node]) {
			int newDistance = wt + distance[node];
			if(newDistance < distance[neighbour]) {
				distance[neighbour] = newDistance;
				pq.push({newDistance,neighbour});
			}
		}
	}

	return distance;

}

int main()
{
	int n,m;
	cin>>n>>m;

	vector<vector<pair<int,int>>> graph(n+1);


	for(int i=0; i<m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({c, b});
	}

	vector<int> ans = shortestRoute(graph);


	for(int i=1; i<ans.size(); i++) {
		cout<<ans[i]<<" ";
	}




	return 0;
}