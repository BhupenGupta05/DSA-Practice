// You play a game consisting of n rooms and m tunnels. Your initial score is 0, and each tunnel increases your score by x where x may be both positive or negative. You may go through a tunnel several times.
// Your task is to walk from room 1 to room n. What is the maximum score you can get?
// Input
// The first input line has two integers n and m: the number of rooms and tunnels. The rooms are numbered 1,2,\dots,n.
// Then, there are m lines describing the tunnels. Each line has three integers a, b and x: the tunnel starts at room a, ends at room b, and it increases your score by x. All tunnels are one-way tunnels.
// You can assume that it is possible to get from room 1 to room n.
// Output
// Print one integer: the maximum score you can get. However, if you can get an arbitrarily large score, print -1.
// Constraints

// 1 \le n \le 2500
// 1 \le m \le 5000
// 1 \le a,b \le n
// -10^9 \le x \le 10^9

// Example
// Input:
// 4 5
// 1 2 3
// 2 4 -1
// 1 3 -2
// 3 4 7
// 1 4 4

// Output:
// 5

#include <bits/stdc++.h>
using namespace std;

long long highScore(int n, vector<tuple<int,int,long long>>& edges) {
    const long long NEG_INF = LLONG_MIN / 2;
	vector<long long> distance(n+1, NEG_INF);
	distance[1] = 0;
	
	for(int i=1; i<=n-1; i++) {
	    for(auto [a,b,x]: edges) {
	        if(distance[a] == NEG_INF) continue;
	        if(distance[a] + x > distance[b]) {
	            distance[b] = distance[a] + x;
	        }
	    }
	}
	
	// This is a modification of the standard Bellman-Ford algorithm to find positive cycles reachable from 1 and can reach n.
	// In the standard Bellman-Ford, we relax the edge one more time to see if it reduces or increases to check for a negative or positive cycle.
	// But here, we can't do that as it is possible that the cycle is in the irrelevant part of the graph and doesn't lead to n.
	// So, we mark those edges and the edges associated with the marked ones as infinite.
	// After that, we check if n is marked as infinite or not.
	vector<bool> infinite(n+1,false);
	for(int i=1; i<=n; i++) {
	    for(auto [a,b,x]: edges) {
	        if(distance[a] == NEG_INF) continue;
	        if(distance[a] + x > distance[b]) {
	            distance[b] = distance[a] + x;
	            infinite[b] = true;
	        }
	        if(infinite[a]) infinite[b] = true;
	    }
	}

	if(infinite[n]) return -1;   // positive cycle can reach n
    return distance[n];
}


int main()
{
	int n,m;
	cin>>n>>m;

	vector<tuple<int,int,long long>> edges(m);


	for(int i=0; i<m; i++) {
		int a,b;
		long long x;
		cin>>a>>b>>x;
		
		edges[i] = {a,b,x};
	}
	
	cout << highScore(n, edges) << "\n";
	
	return 0;
}