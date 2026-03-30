// You are given a tree consisting of n nodes.
// Your task is to determine for each node the maximum distance to another node.
// Input
// The first input line contains an integer n: the number of nodes. The nodes are numbered 1,2,\ldots,n.
// Then there are n-1 lines describing the edges. Each line contains two integers a and b: there is an edge between nodes a and b.
// Output
// Print n integers: for each node 1,2,\ldots,n, the maximum distance to another node.
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
// 2 3 2 3 3

#include <bits/stdc++.h>
using namespace std;

vector<int> distA;
vector<int> distB;
vector<vector<int>> tree;

void bfs(int node, vector<int>& dist) {
	dist[node] = 0;
	queue<int> q;
	q.push(node);

	while(!q.empty()) {
		int curr = q.front();
		q.pop();

		for(auto child: tree[curr]) {
			if(dist[child] == -1) {
				dist[child] = dist[curr]+1;
				q.push(child);
			}
		}
	}
}

int main()
{
	int n;
	cin>>n;

	tree.resize(n+1);

	for(int i=0; i<n-1; i++) {
		int a,b;
		cin>>a>>b;

		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	distA.assign(n+1,-1);
	bfs(1,distA);
	int A = max_element(distA.begin(), distA.end()) - distA.begin();

	distA.assign(n+1,-1);
	bfs(A,distA);
	int B = max_element(distA.begin(), distA.end()) - distA.begin();

	distB.assign(n+1,-1);
	bfs(B,distB);

	for(int i=1; i<=n; i++) {
		cout<<max(distA[i],distB[i])<<" ";
	}


	return 0;
}