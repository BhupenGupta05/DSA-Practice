#include<bits/stdc++.h>

using namespace std;

int allPaths(vector<vector<int>>& matrix) {
	int m = matrix.size();
	int n = matrix[0].size();

    // Directions for moving up, down, left, right
	vector<pair<int,int>> dirs = {
		{1,0},
		{0,1},
		{-1,0},
		{0,-1}
	};

    // Min Heap to store effort, row, col
	priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>,
	               greater<tuple<int,int,int>>> pq;
	pq.push({0,0,0});

    //Effort table to store min effort to reach each cell
	vector<vector<int>> effort(m, vector<int> (n, INT_MAX));
	effort[0][0] = 0;

	while(!pq.empty()) {
		auto[val,r,c] = pq.top();
		pq.pop();

        // If we have reached the end cell, return the val
		if(r == m-1 && c == n-1) {
			return val;
		}

        //Look in all 4 directions and calculate the effort to reach the neighboring cells
		for(auto[dr,dc]: dirs) {
			int nr = r+dr;
			int nc = c+dc;

			if(nr >= m || nr < 0 || nc >= n || nc < 0) continue;

			int diff = abs(matrix[r][c] - matrix[nr][nc]);
			int newEffort = max(val, diff);

			if(newEffort < effort[nr][nc]) {
				effort[nr][nc] = newEffort;
				pq.push({newEffort,nr,nc});
			}
		}
	}
	return effort[m-1][n-1];
}

int main() {
	vector<vector<int>> matrix = {{1,2,2},{3,8,2},{5,3,5}};
	int ans = allPaths(matrix);

	cout<<ans;
	return 0;
}