// Minimum path elevation using optimal approach (Djikstra's algorithm)
// Time complexity: O(m*n*log(m*n))

#include<bits/stdc++.h>

using namespace std;

int allPaths(vector<vector<int>>& matrix) {
	int m = matrix.size();
	int n = matrix[0].size();

	vector<pair<int,int>> dirs = {
		{1,0},
		{0,1},
		{-1,0},
		{0,-1}
	};

	priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>,
	               greater<tuple<int,int,int>>> pq;
	pq.push({matrix[0][0],0,0});

	vector<vector<int>> elevation(m, vector<int> (n, INT_MAX));
	elevation[0][0] = matrix[0][0];

	while(!pq.empty()) {
		auto[val,r,c] = pq.top();
		pq.pop();

		if(r == m-1 && c == n-1) {
			return val;
		}

		for(auto[dr,dc]: dirs) {
			int nr = r+dr;
			int nc = c+dc;

			if(nr >= m || nr < 0 || nc >= n || nc < 0) continue;

			int maxElevation = max(val, matrix[nr][nc]);

			if(maxElevation < elevation[nr][nc]) {
				elevation[nr][nc] = maxElevation;
				pq.push({maxElevation,nr,nc});
			}
		}
	}
	return elevation[m-1][n-1];
}

int main() {
	vector<vector<int>> matrix = {{1,2,2},{3,8,2},{5,3,5}};
	int ans = allPaths(matrix);

	cout<<ans;
	return 0;
}