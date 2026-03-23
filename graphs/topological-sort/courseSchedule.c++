// You have to complete n courses. There are m requirements of the form "course a has to be completed before course b". Your task is to find an order in which you can complete the courses.
// Input
// The first input line has two integers n and m: the number of courses and requirements. The courses are numbered 1,2,\dots,n.
// After this, there are m lines describing the requirements. Each line has two integers a and b: course a has to be completed before course b.
// Output
// Print an order in which you can complete the courses. You can print any valid order that includes all the courses.
// If there are no solutions, print "IMPOSSIBLE".
// Constraints

// 1 \le n \le 10^5
// 1 \le m \le 2 \cdot 10^5
// 1 \le a,b \le n

// Example
// Input:
// 5 3
// 1 2
// 3 1
// 4 5

// Output:
// 3 4 1 5 2


#include <bits/stdc++.h>
using namespace std;

vector<int> findOrder(vector<vector<int>>& graph) {
	int n = graph.size()-1;
	vector<int> indegree(n+1, 0);

	for (int u = 1; u <= n; u++) {
		for (auto v : graph[u]) {
			indegree[v]++;
		}
	}

	queue<int> q;
	for (int u = 1; u <= n; u++) {
		if (indegree[u] == 0) {
			q.push(u);
		}
	}

	vector<int> res;
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		res.push_back(node);

		for (int neighbour : graph[node]) {
			indegree[neighbour]--;
			if (indegree[neighbour] == 0) {
				q.push(neighbour);
			}
		}
	}

	if(res.size() != n) return {};
	return res;
}

int main()
{
	int n,m;
	cin>>n>>m;

	vector<vector<int>> graph(n+1);

	for(int i=0; i<m; i++) {
		int a,b;
		cin>>a>>b;

		graph[a].push_back(b);
	}


	vector<int> order = findOrder(graph);

	if(order.empty()) cout<<"IMPOSSIBLE";
	else {
		for(auto x: order) {
			cout<<x<<" ";
		}
	}

	return 0;
}