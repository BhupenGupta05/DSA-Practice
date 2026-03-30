// Given a binary tree of size  n, a node, and a positive integer k., Your task is to complete the function kthAncestor(), the function should return the kth ancestor of the given node in the binary tree. If there does not exist any such ancestor then return -1.
// Note:
// 1. It is guaranteed that the node exists in the tree.
// 2. All the nodes of the tree have distinct values.

#include <bits/stdc++.h>
using namespace std;

const int LOG = 20;
int n;

vector<vector<int>> tree;
vector<vector<int>> up;


void dfs(int node, int parent) {

	up[node][0] = parent;

	for(int j=1; j<LOG; j++) {
		if(up[node][j-1] != -1) {
			up[node][j] = up[up[node][j-1]][j-1];
		}
	}

	for(int child: tree[node]) {
		if(child != parent) {
			dfs(child,node);
		}
	}
}



int kthAncestor(int k, int node) {
	for(int i=0; i<LOG; i++) {
		if(k & (1 << i)) {       // << -> 1*(2^i); >> -> 1/(2^i)
			node = up[node][i];
			if(node == -1) return -1;
		}
	}
	return node;
}

int main()
{
	cin>>n;

	tree.resize(n+1);
	up.assign(n+1, vector<int>(LOG, -1));

	for(int i=0; i<n-1; i++) {
		int u, v;
		cin >> u >> v;

		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	dfs(1, -1);

	int node = 8, k = 2;
	cout << kthAncestor(k, node);

	return 0;
}