#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> allPaths;
void dfs(int node, int end, vector<vector<int>>& graph,
         vector<bool>& visited, vector<int>& path) {

	visited[node] = true;
	path.push_back(node);

    // if the current node is last node, we add it to the allpaths vector
    // and explore its neighbours.
	if(node == end) {
		allPaths.push_back(path);
	}
	for(int neighbour: graph[node]) {
		if(!visited[neighbour]) {
			dfs(neighbour,end,graph,visited,path);
		}
	}


    // remove the current node from path and unmark it
	path.pop_back();
	visited[node] = false;

}

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> graph(n + 1);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	int start = 1, end = 4;

	vector<bool> visited(n + 1, false);
	vector<int> path;

	dfs(start, end, graph, visited, path);

	for(auto route: allPaths) {
		for(auto x: route) {
			cout<<x<<" ";
		}
		cout<<endl;
	}

	return 0;
}