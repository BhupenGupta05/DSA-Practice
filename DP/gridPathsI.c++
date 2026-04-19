// Consider an n \times n grid whose squares may have traps. It is not allowed to move to a square with a trap.
// Your task is to calculate the number of paths from the upper-left square to the lower-right square. You can only move right or down.
// Input
// The first input line has an integer n: the size of the grid.
// After this, there are n lines that describe the grid. Each line has n characters: . denotes an empty cell, and * denotes a trap.
// Output
// Print the number of paths modulo 10^9+7.
// Constraints

// 1 \le n \le 1000

// Example
// Input:
// 4
// ....
// .*..
// ...*
// *...

// Output:
// 3

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int gridPath(int n, vector<string>& grid) {
    vector<vector<long long>> dp(n, vector<long long>(n, 0));
    
    if(grid[0][0] == '.') dp[0][0] = 1;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            
            if(grid[i][j] == '*') {
                dp[i][j] = 0;
            } else {
                if(i > 0) {
                    dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
                }
                if(j > 0) {
                    dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;
                }
            }
        }
    }
    
    return dp[n-1][n-1];
}


int main() {
    int n;
    cin >> n;
    
    vector<string> grid(n);
    for(int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    
    cout << gridPath(n, grid);
    return 0;
}