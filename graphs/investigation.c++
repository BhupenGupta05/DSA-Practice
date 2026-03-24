// You are going to travel from Syrjälä to Lehmälä by plane. You would like to find answers to the following questions:

// what is the minimum price of such a route?
// how many minimum-price routes are there? (modulo 10^9+7)
// what is the minimum number of flights in a minimum-price route?
// what is the maximum number of flights in a minimum-price route?

// Input
// The first input line contains two integers n and m: the number of cities and the number of flights. The cities are numbered 1,2,\ldots,n. City 1 is Syrjälä, and city n is Lehmälä.
// After this, there are m lines describing the flights. Each line has three integers a, b, and c: there is a flight from city a to city b with price c. All flights are one-way flights.
// You may assume that there is a route from Syrjälä to Lehmälä.
// Output
// Print four integers according to the problem statement.
// Constraints

// 1 \le n \le 10^5
// 1 \le m \le 2 \cdot 10^5
// 1 \le a,b \le n
// 1 \le c \le 10^9

// Example
// Input:
// 4 5
// 1 4 5
// 1 2 4
// 2 4 5
// 1 3 2
// 3 4 3

// Output:
// 5 2 1 2

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

vector<long long> investigation(vector<vector<pair<long long,int>>>& graph) {
	int n = graph.size()-1;
	vector<int> res;
	vector<long long> paths(n+1,0);
	vector<int> minF(n+1,0);
	vector<int> maxF(n+1,-1);
	vector<long long> cost(n+1,INT_MAX);
	cost[1] = 0;
	paths[1] = 1;
	minF[1] = 0;
	maxF[1] = 0;

	priority_queue<pair<long long,int>, vector<pair<long long,int>>, 
	greater<pair<long long,int>>> pq;
	pq.push({0,1});

	while(!pq.empty()) {
		auto [currCost,node] = pq.top();
		pq.pop();

		if(currCost > cost[node]) continue;

		for(auto [wt,neighbour]: graph[node]) {
			long long newCost = wt + cost[node];
			if(newCost < cost[neighbour]) {
				cost[neighbour] = newCost;
				paths[neighbour] = paths[node];
				minF[neighbour] = minF[node]+1;
				maxF[neighbour] = maxF[node]+1;
				pq.push({newCost,neighbour});
			} else if(newCost == cost[neighbour]) {
				paths[neighbour] = (paths[node] + paths[neighbour])%MOD;
				minF[neighbour] = min(minF[node]+1,minF[neighbour]);
				maxF[neighbour] = max(maxF[node]+1,maxF[neighbour]);
			}
		}
	}
	res.push_back(cost[n]);
	res.push_back(paths[n]);
	res.push_back(minF[n]);
	res.push_back(maxF[n]);
	return res;
}

int main()
{
	int n,m;
	cin>>n>>m;

	vector<vector<pair<long long,int>>> graph(n+1);

	for(int i=0; i<m; i++) {
		int a,b,c;
		cin>>a>>b>>c;

		graph[a].push_back({c,b});
	}


	vector<long long> ans = investigation(graph);
	for(long long x: ans) {
		cout<<x<<" ";
	}
	return 0;
}