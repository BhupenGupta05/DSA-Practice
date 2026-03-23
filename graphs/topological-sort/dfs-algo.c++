#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>>& graph,
         vector<int>& state, vector<int>& res, bool& hasCycle) {
	state[node] = 1;

	for(auto neighbour: graph[node]) {
		if(state[neighbour] == 1) {
			hasCycle = true;
			return;
		}
		else if(state[neighbour] == 0) {
			dfs(neighbour,graph,state,res,hasCycle);
		}
	}
	state[node] = 2;
	res.push_back(node);
}

vector<int> topoStates(int numCourses, vector<vector<int>>& prerequisites) {
	int n = numCourses;
	vector<vector<int>> graph(n);

	for (auto pair : prerequisites) {
		int pre = pair[1];
		int next = pair[0];
		graph[pre].push_back(next);
	}

	vector<int> state(n,0);
	vector<int> res;
	bool hasCycle = false;
	
	for(int i=0; i<n; i++) {
	    if(state[i] == 0) {
	        dfs(i,graph,state,res,hasCycle);
	    }
	}
	
	if(hasCycle == true) return {};
	reverse(res.begin(), res.end());
	return res;
}
