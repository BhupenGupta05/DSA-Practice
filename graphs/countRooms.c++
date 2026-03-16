// You are given a map of a building, and your task is to count the number of its rooms. The size of the map is n \times m squares, and each square is either floor or wall. You can walk left, right, up, and down through the floor squares.
// Input
// The first input line has two integers n and m: the height and width of the map.
// Then there are n lines of m characters describing the map. Each character is either . (floor) or # (wall).
// Output
// Print one integer: the number of rooms.
// Constraints

// 1 \le n,m \le 1000

// Example
// Input:
// 5 8
// ########
// #..#...#
// ####.#.#
// #..#...#
// ########

// Output:
// 3

#include <bits/stdc++.h>
using namespace std;

int countRooms(vector<vector<char>>& map) {
	int m = map.size();
	int n = map[0].size();

	vector<vector<bool>> visited(m, vector<bool>(n,false));
	int rooms = 0;

	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			if(map[i][j] == '.' && !visited[i][j]) {
				rooms++;

				queue<pair<int,int>> toVisit;
				visited[i][j] = true;
				toVisit.push({i,j});

				while(!toVisit.empty()) {
					auto[currR,currC] = toVisit.front();
					toVisit.pop();

					if(currR-1 >= 0 && map[currR-1][currC] == '.' && !visited[currR-1][currC]) {
						toVisit.push({currR-1,currC});
						visited[currR-1][currC] = true;
					}
					if(currC-1 >= 0 && map[currR][currC-1] == '.' && !visited[currR][currC-1]) {
						toVisit.push({currR,currC-1});
						visited[currR][currC-1] = true;
					}
					if(currR+1 < m && map[currR+1][currC] == '.' && !visited[currR+1][currC]) {
						toVisit.push({currR+1,currC});
						visited[currR+1][currC] = true;
					}
					if(currC+1 < n && map[currR][currC+1] == '.' && !visited[currR][currC+1]) {
						toVisit.push({currR,currC+1});
						visited[currR][currC+1] = true;
					}
				}
			}
		}
	}
	return rooms;
}

int main()
{
	vector<vector<char>> map = {
		{'#','#','#','#','#','#','#','#'},
		{'#','.','.','#','.','.','.','#'},
		{'#','#','#','#','.','#','.','#'},
		{'#','.','.','#','.','.','.','#'},
		{'#','#','#','#','#','#','#','#'},
	};

	cout<<countRooms(map);

	return 0;
}