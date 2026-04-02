// You are given a tree consisting of n nodes.
// Your task is to process q queries of the form: what is the distance between nodes a and b?
// Input
// The first input line contains two integers n and q: the number of nodes and queries. The nodes are numbered 1,2,\ldots,n.
// Then there are n-1 lines describing the edges. Each line contains two integers a and b: there is an edge between nodes a and b.
// Finally, there are q lines describing the queries. Each line contains two integer a and b: what is the distance between nodes a and b?
// Output
// Print q integers: the answer to each query.
// Constraints

// 1 \le n, q \le 2 \cdot 10^5
// 1 \le a,b \le n

// Example
// Input:
// 5 3
// 1 2
// 1 3
// 3 4
// 3 5
// 1 3
// 2 5
// 1 4

// Output:
// 1
// 3
// 2

// There is a formula to calculate the distance between two nodes a and b in a tree using their lowest common ancestor (LCA):
// distance(a, b) = depth[a] + depth[b] - 2 * depth[LCA(a, b)]
// We do binary lifting to find LCA and depth using DFS.

#include <bits/stdc++.h>
using namespace std;

const int LOG = 20;

vector<vector<int>> tree;
vector<vector<int>> up;
vector<int> depth;

void dfs(int node, int parent, int d) {
	up[node][0] = parent;
	depth[node] = d;

	for(int i=1; i<LOG; i++) {
		if(up[node][i-1] != -1) {
			up[node][i] = up[up[node][i-1]][i-1];
		}
	}

	for(auto child: tree[node]) {
		if(child != parent) {
			dfs(child,node,d+1);
		}
	}
}

int lca(int a, int b) {
	if(depth[a] < depth[b]) swap(a,b);

	int diff = depth[a] - depth[b];

	for(int j=LOG-1; j>=0; j--) {
		if(diff & (1 << j)) {
			a = up[a][j];
		}
	}

	if(a == b) return a;

	for(int j=LOG-1; j>=0; j--) {
		if(up[a][j] != up[b][j]) {
			a = up[a][j];
			b = up[b][j];
		}
	}

	return up[a][0];
}

int main()
{
	int n,q;
	cin>>n>>q;

	tree.resize(n+1);
	up.assign(n+1, vector<int>(LOG, -1));
	depth.assign(n+1,0);

	for(int i=0; i<n-1; i++) {
		int a,b;
		cin>>a>>b;

		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	dfs(1,-1,0);
	
	for(int i=0; i<q; i++) {
	    int a,b;
	    cin>>a>>b;
	    int L = lca(a,b);
		cout<<depth[a]+depth[b]-2*depth[L]<<" ";
	}

	return 0;
}