// Find number of nodes present in each of the subtrees

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> tree;
vector<int> res;

int subordinates(int node) {
    int size = 1;
	
	for(auto child: tree[node]) {
	    size += subordinates(child);
	}
	
	res[node] = size-1;
	return size;
}

int main()
{
    int n;
	cin>>n;
	
	tree.resize(n+1);
	res.assign(n+1,0);
	
	for(int i=2; i<=n; i++) {
		int m;
		cin>>m;
		
		tree[m].push_back(i);
	}
	
	subordinates(1);
	
	for(int i=1; i<=n; i++) {
	    cout<<res[i]<<" ";
	}

	return 0;
}