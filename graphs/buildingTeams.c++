// There are n pupils in Uolevi's class, and m friendships between them. Your task is to divide the pupils into two teams in such a way that no two pupils in a team are friends. You can freely choose the sizes of the teams.
// Input
// The first input line has two integers n and m: the number of pupils and friendships. The pupils are numbered 1,2,\dots,n.
// Then, there are m lines describing the friendships. Each line has two integers a and b: pupils a and b are friends.
// Every friendship is between two different pupils. You can assume that there is at most one friendship between any two pupils.
// Output
// Print an example of how to build the teams. For each pupil, print "1" or "2" depending on to which team the pupil will be assigned. You can print any valid team.
// If there are no solutions, print "IMPOSSIBLE".
// Constraints

// 1 \le n \le 10^5
// 1 \le m \le 2 \cdot 10^5
// 1 \le a,b \le n

// Example
// Input:
// 5 3
// 1 2
// 1 3
// 4 5

// Output:
// 1 2 2 1 2

// This is a classic problem of checking if a graph is bipartite.
// We can use BFS to traverse the graph and assign teams (colors) to the nodes. 
// If we find a conflict in team assignment, we can conclude that it's impossible to build the teams as required.

#include <bits/stdc++.h>
using namespace std;

vector<int> buildingTeams(vector<vector<int>>& graph) {
	int n = graph.size()-1;
	vector<int> team(n+1,0);

	for(int i=1; i<=n; i++) {
		if(team[i] == 0) {
			queue<int> toVisit;
			toVisit.push(i);
			team[i] = 1;

			while(!toVisit.empty()) {
				int node = toVisit.front();
				toVisit.pop();

				for(auto neighbours: graph[node]) {
					if(team[neighbours] == 0) {
						team[neighbours] = 3 - team[node];
						toVisit.push(neighbours);
					} else if(team[neighbours] == team[node]) {
						cout << "IMPOSSIBLE";
						exit(0);
					}
				}
			}
		}
	}
	return team;
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
		graph[b].push_back(a);
	}

	vector<int> ans = buildingTeams(graph);

	for(int i=1; i<ans.size(); i++) {
		cout<<ans[i]<<" ";
	}


	return 0;
}