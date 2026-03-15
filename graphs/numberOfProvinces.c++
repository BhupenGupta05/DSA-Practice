// There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

// A province is a group of directly or indirectly connected cities and no other cities outside of the group.

// You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

// Return the total number of provinces.

// NOTE - This is nothing but a simple graph problem where we have to count
// the number of components.


#include <bits/stdc++.h>
using namespace std;

int findCircleNum(vector<vector<int>>& isConnected) {
	int n = isConnected.size();
	unordered_set<int> visited;
	queue<int> toVisit;
	int province = 0;

	for(int i=0; i<n; i++) {
		if(!visited.count(i)) {
			province++;
			toVisit.push(i);

			while(!toVisit.empty()) {
				int city = toVisit.front();
				toVisit.pop();

				visited.insert(city);

				for(int j=0; j<n; j++) {
				    if(isConnected[city][j] == 1 && !visited.count(j)) {
				        toVisit.push(j);
				    }
				}
			}
		}
	}
	return province;
}

int main()
{
	vector<vector<int>> isConnected = {{1,1,0},{1,1,0},{0,0,1}};
	
	cout<<findCircleNum(isConnected);

	return 0;
}