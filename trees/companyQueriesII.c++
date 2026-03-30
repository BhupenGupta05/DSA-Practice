// A company has n employees, who form a tree hierarchy where each employee has a boss, except for the general director.
// Your task is to process q queries of the form: who is the lowest common boss of employees a and b in the hierarchy?
// Input
// The first input line has two integers n and q: the number of employees and queries. The employees are numbered 1,2,\dots,n, and employee 1 is the general director.
// The next line has n-1 integers e_2,e_3,\dots,e_n: for each employee 2,3,\dots,n their boss.
// Finally, there are q lines describing the queries. Each line has two integers a and b: who is the lowest common boss of employees a and b?
// Output
// Print the answer for each query.
// Constraints

// 1 \le n,q \le 2 \cdot 10^5
// 1 \le e_i \le i-1
// 1 \le a,b \le n

// Example
// Input:
// 5 3
// 1 1 3 3
// 4 5
// 2 5
// 1 4

// Output:
// 3
// 1
// 1



// Approach 1: BFS and Parent Array

// Find LCA of two nodes in a tree using BFS and parent array. 
// This is a simpler approach than binary lifting, but it has a time complexity of O(n) per query, which may not be efficient for large trees and many queries.
// The binary lifting method can answer LCA queries in O(log n) time after O(n log n) preprocessing time.

#include <bits/stdc++.h>
using namespace std;

const int LOG = 20;

vector<vector<int>> tree;
vector<int> parent;
vector<int> depth;

void bfs(int node) {
	queue<int> q;
	q.push(node);
	parent[node] = -1;
	depth[node] = 0;

	while(!q.empty()) {
		int curr = q.front();
		q.pop();

		for(auto child: tree[curr]) {
			parent[child] = curr;
			depth[child] = depth[curr] + 1;
			q.push(child);
		}
	}

}

int LCA(int u, int v) {
	while(depth[u] > depth[v]) {
		u = parent[u];
	}

	while(depth[v] > depth[u]) {
		v = parent[v];
	}
	
	while(u != v) {
	    u = parent[u];
	    v = parent[v];
	}
	return u;
}

int main()
{
	int n,q;
	cin>>n>>q;

	tree.resize(n+1);
	parent.assign(n+1,-1);
	depth.assign(n+1,0);

	for(int i=2; i<=n; i++) {
		int x;
		cin>>x;

		tree[x].push_back(i);
	}
	
	bfs(1);

	for(int i=0; i<q; i++) {
		int a,b;
		cin>>a>>b;
		cout << LCA(a,b) << "\n";
	}


	return 0;
}


// Approach 2: Binary Lifting
// This method preprocesses the tree to allow for efficient LCA queries. 


#include <bits/stdc++.h>
using namespace std;

const int LOG = 20;

vector<vector<int>> tree;
vector<vector<int>> up;
vector<int> depth;

void dfs(int node, int parent, int d) {
	up[node][0] = parent;
	depth[node] = d;

	for(int j=1; j<LOG; j++) {
		if(up[node][j-1] != -1) {
			up[node][j] = up[up[node][j-1]][j-1];
		}
	}

	for(int child: tree[node]) {
		if(child != parent) {
			dfs(child,node,d+1);
		}
	}

}

int LCA(int u, int v) {
    // We want u to be bigger, so we swap
	if(depth[u] < depth[v]) swap(u, v);

	int diff = depth[u] - depth[v];
	
	// Till one of the nodes is at same level, we jump by 2,4,8... steps
	for(int j=LOG-1; j>=0; j--) {
		if(diff & (1 << j)) {
			u = up[u][j];
		}
	}
	
	// 	If both nodes are same, return any of the node
	if(u == v) return u;
	
	// After both nodes are at same level, make them jump by same unit
	for(int j=LOG-1; j>=0; j--) {
		if(up[u][j] != up[v][j]) {
			u = up[u][j];
			v = up[v][j];
		}
	}

	return up[u][0];
}

int main()
{
	int n,q;
	cin>>n>>q;

	tree.resize(n+1);
	up.assign(n+1, vector<int>(LOG, -1));
	depth.assign(n+1,0);

	for(int i=2; i<=n; i++) {
		int x;
		cin>>x;

		tree[x].push_back(i);
	}

	dfs(1,-1,0);

	for(int i=0; i<q; i++) {
		int a,b;
		cin>>a>>b;
		cout << LCA(a,b) << "\n";
	}


	return 0;
}