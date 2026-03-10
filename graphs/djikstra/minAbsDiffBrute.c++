#include<bits/stdc++.h>

using namespace std;

int ans = INT_MAX;
void helper(vector<vector<int>>& matrix, int i, int j,
            vector<string>& res, string& path, set<pair<int,int>>& seen,
            int prev, int currMaxAbsDiff) {
	int m = matrix.size();
	int n = matrix[0].size();

    //If the current cell is out of bounds, return
	if(i < 0 || i >= m || j < 0 || j >= n) return;

    //To avoid cycles, if the current cell has already been visited, return
	if(seen.count({i,j})) return;
	
    //Calculate absolute diff
	int diff = abs(matrix[i][j] - prev);
	currMaxAbsDiff = max(currMaxAbsDiff, diff);

    //Mark the current cell as visited
	seen.insert({i,j});

    //While backtracking, we need to undo changes if the path is not valid.
    //So, to do that, we need to store the old length of the path before adding the current cell's value to it.

	int oldLen = path.size();
	if(path.empty()) {
	    path += to_string(matrix[i][j]);
	} else {
	    path += "->" + to_string(matrix[i][j]);
	}
	

    //If we have reached the destination cell, we can add the current path to the result vector. 
    //Otherwise, we need to explore the neighboring cells (up, down, left, right) recursively.
	if(i == m-1 && j == n-1) {
		res.push_back(path);
        ans = min(ans, currMaxAbsDiff); //Return min of all abs diff of all paths
	} else {
		helper(matrix, i-1, j, res, path, seen, matrix[i][j], currMaxAbsDiff);
		helper(matrix, i+1, j, res, path, seen, matrix[i][j], currMaxAbsDiff);
		helper(matrix, i, j-1, res, path, seen, matrix[i][j], currMaxAbsDiff);
		helper(matrix, i, j+1, res, path, seen, matrix[i][j], currMaxAbsDiff);
	}

    //Backtrack: Remove the current cell from the path and mark it as unvisited before returning to explore other paths.
	path.resize(oldLen);
	seen.erase({i,j});
}

int allPaths(vector<vector<int>>& matrix) {
	vector<string> res;
	string path = "";
	set<pair<int,int>> seen;
	helper(matrix, 0, 0, res, path, seen, matrix[0][0], 0);
	return ans;
}
