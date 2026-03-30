//Count nodes in subtree

#include <bits/stdc++.h>
using namespace std;

vector<int> subtree;
vector<vector<int>> tree;

void dfs(int curr, int parent) {
    subtree[curr] = 1;
    for(auto node: tree[curr]) {
        if(node == parent) continue;
        dfs(node,curr);
        subtree[curr] += subtree[node];
    }
}

int main()
{
    int n;
	cin>>n;
	
	tree.resize(n+1);
	subtree.assign(n+1,0);
	
	for(int i=2; i<=n; i++) {
		int m;
		cin>>m;
		
		tree[m].push_back(i);
	}
	
	dfs(1,-1);
	
	for(int i=1; i<=n; i++) {
	    cout<<subtree[i]-1<<" ";
	}

	return 0;
}