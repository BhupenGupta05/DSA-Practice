// You are given a map of a labyrinth, and your task is to find a path from start to end. You can walk left, right, up and down.
// Input
// The first input line has two integers n and m: the height and width of the map.
// Then there are n lines of m characters describing the labyrinth. Each character is . (floor), # (wall), A (start), or B (end). There is exactly one A and one B in the input.
// Output
// First print "YES", if there is a path, and "NO" otherwise.
// If there is a path, print the length of the shortest such path and its description as a string consisting of characters L (left), R (right), U (up), and D (down). You can print any valid solution.
// Constraints

// 1 \le n,m \le 1000

// Example
// Input:
// 5 8
// ########
// #.A#...#
// #.##.#B#
// #......#
// ########

// Output:
// YES
// 9
// LDDRRRRRU

// We can solve this using BFS. First we find A, then apply the algo from there.
// We store (row,col,dist) for each cell in the queue. 
// We also store the parent of each cell and the move we took to get there. 
// When we reach B, we can reconstruct the path from B to A using the parent and move arrays
// The path will be in reverse order, so we reverse it before returning.

#include <bits/stdc++.h>
using namespace std;

pair<int,string> shortestPathLabyrinth(vector<vector<char>>& map) {
	int m = map.size();
	int n = map[0].size();
	int pathLen = -1;

	string path = "";
	vector<vector<pair<int,int>>> parent(m, vector<pair<int,int>>(n));
	vector<vector<char>> move(m,vector<char>(n));
	vector<vector<bool>> visited(m, vector<bool>(n,false));
	int startR;
	int startC;

    // Find A
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			if(map[i][j] == 'A') {
				startR = i;
				startC = j;
			}
		}
	}

	queue<tuple<int,int,int>> toVisit;
	toVisit.push({startR,startC,0});
	visited[startR][startC] = true;

	while(!toVisit.empty()) {
		auto[currR,currC,dist] = toVisit.front();
		toVisit.pop();

        // If we reached the end
		if(map[currR][currC] == 'B') {
			pathLen = dist;
			startR = currR;
			startC = currC;
			break;
		}


        // Explore neighbors
		if(currR-1 >= 0 && map[currR-1][currC] != '#' && !visited[currR-1][currC]) {
			parent[currR-1][currC] = {currR,currC};
			move[currR-1][currC] = 'U';
			toVisit.push({currR-1,currC,dist+1});
			visited[currR-1][currC] = true;

		}
		if(currC-1 >= 0 && map[currR][currC-1] != '#' && !visited[currR][currC-1]) {
			parent[currR][currC-1] = {currR,currC};
			move[currR][currC-1] = 'L';
			toVisit.push({currR,currC-1,dist+1});
			visited[currR][currC-1] = true;
		}
		if(currR+1 < m && map[currR+1][currC] != '#' && !visited[currR+1][currC]) {
			parent[currR+1][currC] = {currR,currC};
			move[currR+1][currC] = 'D';
			toVisit.push({currR+1,currC,dist+1});
			visited[currR+1][currC] = true;
		}
		if(currC+1 < n && map[currR][currC+1] != '#' && !visited[currR][currC+1]) {
			parent[currR][currC+1] = {currR,currC};
			move[currR][currC+1] = 'R';
			toVisit.push({currR,currC+1,dist+1});
			visited[currR][currC+1] = true;
		}
	}

    // Path reconstruction
	while(map[startR][startC] != 'A') {
		path.push_back(move[startR][startC]);

		auto[pr,pc] = parent[startR][startC];
		startR = pr;
		startC = pc;
	}

	reverse(path.begin(),path.end());
	return {pathLen,path};
}

int main()
{
	vector<vector<char>> map = {
		{'#','#','#','#','#','#','#','#'},
		{'#','.','A','#','.','.','.','#'},
		{'#','.','#','#','.','#','B','#'},
		{'#','.','.','.','.','.','.','#'},
		{'#','#','#','#','#','#','#','#'},
	};

	auto [len,path] = shortestPathLabyrinth(map);

	if(len == -1) cout<<"NO";
	else {
		cout<<"YES\n";
		cout<<len<<"\n";
		cout<<path<<"\n";
	}



	return 0;
}