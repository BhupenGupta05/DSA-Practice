#include<bits/stdc++.h>

using namespace std;

void helper(vector<vector<int>>& matrix, int i, int j,
            vector<string>& res, string& path, set<pair<int,int>>& seen) {
	int m = matrix.size();
	int n = matrix[0].size();

    //If the current cell is out of bounds, return
	if(i < 0 || i >= m || j < 0 || j >= n) return;

    //To avoid cycles, if the current cell has already been visited, return
	if(seen.count({i,j})) return;

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
	} else {
		helper(matrix, i-1, j, res, path, seen);
		helper(matrix, i+1, j, res, path, seen);
		helper(matrix, i, j-1, res, path, seen);
		helper(matrix, i, j+1, res, path, seen);
	}

    //Backtrack: Remove the current cell from the path and mark it as unvisited before returning to explore other paths.
	path.resize(oldLen);
	seen.erase({i,j});
}

vector<string> allPaths(vector<vector<int>>& matrix) {
	vector<string> res;
	string path = "";
	set<pair<int,int>> seen;
	helper(matrix, 0, 0, res, path, seen);
	return res;
}