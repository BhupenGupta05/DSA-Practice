#include <bits/stdc++.h>
using namespace std;

vector<long long> dist;

vector<long long> nearestShops(vector<vector<long long>>& graph, vector<long long>& shops) {
	queue<long long> toVisit;

	for(auto sh: shops) {
		dist[sh] = 0;
		toVisit.push(sh);
	}

	while(!toVisit.empty()) {
		long long curr = toVisit.front();
		toVisit.pop();

		for(auto neighbour: graph[curr]) {
			if(dist[neighbour] == -1) {
			    dist[neighbour] = dist[curr]+1;
			    toVisit.push(neighbour);
			}
		}
	}
	
	for(auto sh: shops) {
	    long long best = LLONG_MAX;
	    for(auto neighbour: graph[sh]) {
	        if(dist[neighbour] != -1) {
	            best = min(best,dist[neighbour]+1);
	        }
	    }
	    dist[sh] = best == LLONG_MAX ? -1 : best;
	}
	return dist;
}

int main()
{
	int n,m,k;
	cin>>n>>m>>k;

	vector<long long> shops(k);
	vector<vector<long long>> graph(n+1);

	dist.assign(n+1,-1);

	for(int i=0; i<k; i++) {
		cin>>shops[i];
	}


	for(int i=0; i<m; i++) {
		long long a,b;
		cin>>a>>b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	vector<long long> ans = nearestShops(graph,shops);

	for(int i=1; i<ans.size(); i++) {
		cout<<ans[i]<<" ";
	}

	return 0;
}