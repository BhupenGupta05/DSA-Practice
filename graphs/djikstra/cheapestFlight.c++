// Your task is to find a minimum-price flight route from Syrjälä to Metsälä. You have one discount coupon, using which you can halve the price of any single flight during the route. However, you can only use the coupon once.
// When you use the discount coupon for a flight whose price is x, its price becomes \lfloor x/2 \rfloor (it is rounded down to an integer).
// Input
// The first input line has two integers n and m: the number of cities and flight connections. The cities are numbered 1,2,\ldots,n. City 1 is Syrjälä, and city n is Metsälä.
// After this there are m lines describing the flights. Each line has three integers a, b, and c: a flight begins at city a, ends at city b, and its price is c. Each flight is unidirectional.
// You can assume that it is always possible to get from Syrjälä to Metsälä.
// Output
// Print one integer: the price of the cheapest route from Syrjälä to Metsälä.
// Constraints

// 2 \le n \le 10^5
// 1 \le m \le 2 \cdot 10^5
// 1 \le a,b \le n
// 1 \le c \le 10^9

// Example
// Input:
// 3 4
// 1 2 3
// 2 3 1
// 1 3 7
// 2 1 5

// Output:
// 2

// Here, we used one more parameter, which is used state of the coupon. We can think of the graph as having two layers: layer 0 where we haven't used the coupon, and layer 1 where we have used the coupon. 
// When we use the coupon on an edge in layer 0, we jump to layer 1. We can run Dijkstra's algorithm on this layered graph to find the cheapest route from (1,0) to (n,0) or (n,1).
// Layer 0 and 1 are stacked on top of each other, and we have edges between them. The distance array is 2D, where distance[node][0] is the cheapest price to reach node without using the coupon, and distance[node][1] is the cheapest price to reach node after using the coupon.
// We can use the coupon, but once we use it and go to layer 1, we cannot go back to layer 0.


#include <bits/stdc++.h>
using namespace std;

long long cheapestFlight(vector<vector<pair<int,int>>>& graph) {
	int n = graph.size()-1;
	vector<vector<long long>> distance(n+1, vector<long long> (2, LLONG_MAX));

// 	tuple{cost, node, coupon_used}
	priority_queue<tuple<long long,int,int>,
	               vector<tuple<long long,int,int>>,
	               greater<tuple<long long,int,int>>> pq;
	pq.push({0,1,0});
	distance[1][0] = 0;

	while(!pq.empty()) {
		auto [cost, node, used] = pq.top();
		pq.pop();

		if(cost > distance[node][used]) continue;

		for(auto [wt,neighbour]: graph[node]) {

			// Option 1: Don't use coupon; remain in layer 0
			long long newCost = wt + distance[node][used];
			if(newCost < distance[neighbour][used]) {
				distance[neighbour][used] = newCost;
				pq.push({newCost,neighbour,used});
			}

			// Option 2: Use coupon on this edge and jump to layer 1
			if(used == 0) {
				long long newCost2 = wt/2 + distance[node][0];
				if(newCost2 < distance[neighbour][1]) {
					distance[neighbour][1] = newCost2;
					pq.push({newCost2,neighbour,1});
				}

			}
		}
	}
	return min(distance[n][0], distance[n][1]);

}


int main()
{
	int n,m;
	cin>>n>>m;

	vector<vector<pair<int,int>>> graph(n+1);


	for(int i=0; i<m; i++) {
		int a,b,c;
		cin>>a>>b>>c;

		graph[a].push_back({c,b});
	}

	cout << cheapestFlight(graph) << "\n";

	return 0;
}