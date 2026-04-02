#include <bits/stdc++.h>
using namespace std;

vector<int> dist;

vector<int> nearestShops(vector<vector<int>>& graph, vector<int>& shops) {
	queue<int> toVisit;

	for(auto sh: shops) {
		dist[sh] = 0;
		toVisit.push(sh);
	}

	while(!toVisit.empty()) {
		int curr = toVisit.front();
		toVisit.pop();

		for(auto neighbour: graph[curr]) {
			if(dist[neighbour] == -1) {
			    dist[neighbour] = dist[curr]+1;
			    toVisit.push(neighbour);
			}
		}
	}
	
	for(auto sh: shops) {
	    int best = INT_MAX;
	    for(auto neighbour: graph[sh]) {
	        if(dist[neighbour] == 0) {
	            best = min(best,dist[sh]+1);
	        }
	    }
	    dist[sh] = best == INT_MAX ? -1 : best;
	}
	return dist;
}

int main()
{
	int n,m,k;
	cin>>n>>m>>k;

	vector<int> shops(k);
	vector<vector<int>> graph(n+1);

	dist.assign(n+1,-1);

	for(int i=0; i<k; i++) {
		cin>>shops[i];
	}


	for(int i=0; i<m; i++) {
		int a,b;
		cin>>a>>b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	vector<int> ans = nearestShops(graph,shops);

	for(int i=1; i<ans.size(); i++) {
		cout<<ans[i]<<" ";
	}

	return 0;
}