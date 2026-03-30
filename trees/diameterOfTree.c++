// Find the diameter of a tree. 
// The diameter of a tree is the longest path between any two nodes in the tree.

#include <bits/stdc++.h>
using namespace std;

vector<int> subtree;
vector<vector<int>> tree;

int diameter = 0;

// Approach 1: DFS
int dfs(int node, int parent) {
	int maxHeight1=0, maxHeight2=0;

	for(int child: tree[node]) {
		if(child == parent) continue;

		int h = dfs(child,node);

		if(h > maxHeight1) {
			maxHeight2 = maxHeight1;
			maxHeight1 = h;
		} else if(h > maxHeight2) {
			maxHeight2 = h;
		}
	}
	diameter = max(diameter,maxHeight1+maxHeight2);

	return 1 + maxHeight1;
}

// Approach 2: Using 2 DFS
// Find the farthest node from any arbitrary node (say 1) using DFS. Let this node be x.
// Then, find the farthest node from x using DFS. The distance to this farthest
// node will be the diameter of the tree.
pair<int,int> dfs(int node, int parent, int dist) {
	pair<int,int> res = {dist,node};

	for(auto child: tree[node]) {
		if(child == parent) continue;

		auto temp = dfs(child,node,dist+1);
		if(temp.first > res.first) {
			res = temp;
		}
	}
	return res;
}

// Approach 3: Using 2 BFS
// Similar to approach 2, but using BFS instead of DFS. 
// BFS will give the distance of all nodes from the starting node, so we can easily find the farthest node and its distance.
pair<int,int> bfs(int start, int n) {
	queue<int> q;

	vector<int> dist(n+1,-1);
	dist[start] = 0;
	q.push(start);
	
	int farthest = start;

	while(!q.empty()) {
		int node = q.front();
		q.pop();

		for(auto child: tree[node]) {
		    if(dist[child] == -1) {
		        dist[child] = dist[node]+1;
		        q.push(child);
		        
		        if(dist[child] > dist[farthest]) {
		            farthest = child;
		        }
		    }

		}
	}
	return {dist[farthest],farthest};
}

int main()
{
	int n;
	cin>>n;

	tree.resize(n+1);
	subtree.assign(n+1,0);

	for(int i=0; i<n-1; i++) {
		int a,b;
		cin>>a>>b;

		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	
	auto p1 = bfs(1,n);
	
	cout<<p1.first<<" "<<p1.second<<endl;
	
	auto p2 = bfs(p1.second,n);
	
	cout<<p2.first<<" ";

// 	auto p1 = dfs(1,-1,0);

// 	auto p2 = dfs(p1.second,-1,0);

// 	cout<<p2.first<<" ";

// 	for(int i=1; i<=n; i++) {
// 	    cout<<subtree[i]-1<<" ";
// 	}

	return 0;
}