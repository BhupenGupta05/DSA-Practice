// You are given a tree consisting of n nodes.
// Your task is to determine for each node the sum of the distances from the node to all other nodes.
// Input
// The first input line contains an integer n: the number of nodes. The nodes are numbered 1,2,\ldots,n.
// Then there are n-1 lines describing the edges. Each line contains two integers a and b: there is an edge between nodes a and b.
// Output
// Print n integers: for each node 1,2,\ldots,n, the sum of the distances.
// Constraints

// 1 \le n \le 2 \cdot 10^5
// 1 \le a,b \le n

// Example
// Input:
// 5
// 1 2
// 1 3
// 3 4
// 3 5

// Output:
// 6 9 5 8 8

// This involves a common technique in tree problems called "rerooting". 
// The idea is to first calculate the sum of distances from an arbitrary root (in this case, node 1) to all other nodes using a depth-first search (DFS). 
// Then, we can "reroot" the tree at each child node and update the sum of distances accordingly. This allows us to compute the answer for all nodes efficiently in O(n) time after an initial O(n) DFS.

#include <bits/stdc++.h>
using namespace std;

vector<int> subtree_sumPaths;
vector<int> subtree_size;
vector<vector<int>> tree;
vector<int> ans;

void dfs1(int node, int parent) {
	subtree_size[node] = 1;
	subtree_sumPaths[node] = 0;

	for(auto child: tree[node]) {
		if(child == parent) continue;

		dfs1(child,node);

		subtree_size[node] += subtree_size[child];
		subtree_sumPaths[node] += subtree_sumPaths[child] + subtree_size[child];
	}
}

void reroot(int from, int to) {
    subtree_sumPaths[from] -= subtree_sumPaths[to] + subtree_size[to];
    
    subtree_size[from] -= subtree_size[to];
    
     subtree_sumPaths[to] += subtree_sumPaths[from] + subtree_size[from];
     subtree_size[to] += subtree_size[from];
}

void dfs2(int node, int parent, vector<int>& ans) {
    ans[node] = subtree_sumPaths[node];
    
    	for(auto child: tree[node]) {
		if(child == parent) continue;

		reroot(node,child);
		
		dfs2(child,node,ans);
		
		reroot(child,node);
	}
}

int main()
{
	int n;
	cin>>n;
	
	tree.resize(n+1);
	ans.resize(n+1);
	subtree_size.resize(n+1);
	subtree_sumPaths.resize(n+1);

	for(int i=0; i<n-1; i++) {
		int a,b;
		cin>>a>>b;

		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	dfs1(1,-1);
	dfs2(1,-1,ans);

	for(int i=1; i<=n; i++) {
		cout<<ans[i]<<" ";
	}

	return 0;
}