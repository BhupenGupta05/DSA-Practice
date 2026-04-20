// You are given an n \times n grid representing the map of a forest. Each square is either empty or contains a tree. The upper-left square has coordinates (1,1), and the lower-right square has coordinates (n,n).
// Your task is to process q queries of the form: how many trees are inside a given rectangle in the forest?
// Input
// The first input line has two integers n and q: the size of the forest and the number of queries.
// Then, there are n lines describing the forest. Each line has n characters: . is an empty square and * is a tree.
// Finally, there are q lines describing the queries. Each line has four integers y_1, x_1, y_2, x_2 corresponding to the corners of a rectangle.
// Output
// Print the number of trees inside each rectangle.
// Constraints

// 1 \le n \le 1000
// 1 \le q \le 2 \cdot 10^5
// 1 \le y_1 \le y_2 \le n
// 1 \le x_1 \le x_2 \le n

// Example
// Input:
// 4 3
// .*..
// *.**
// **..
// ****
// 2 2 3 4
// 3 1 3 1
// 1 1 2 2

// Output:
// 3
// 1
// 2

// We simply create a prefix sum matrix, where prefix[i][j] is the number of trees in the rectangle with corners (1,1) and (i,j). 
// We can compute this matrix in O(n^2) time. Then, we can answer each query in O(1) time using the formula: prefix[y2][x2] - prefix[y1-1][x2] - prefix[y2][x1-1] + prefix[y1-1][x1-1].
// What it does is it takes the total number of trees in the rectangle (1,1) to (y2,x2), then subtracts the trees in the rectangles above and to the left of the query rectangle, and finally adds back the trees in the rectangle that was subtracted twice.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,q;
    cin >> n>>q;
    
    vector<vector<int>> prefix(n+1,vector<int>(n+1,0));
    for(int i=1; i<=n; i++) {
        string s;
        cin>>s;
        for(int j=1; j<=n; j++) {
            int val = (s[j-1] == '*');
            prefix[i][j] = val+prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1];
        }
    }
    
    while(q--) {
        int y1,x1,y2,x2;
        cin>>y1>>x1>>y2>>x2;
        int ans = prefix[y2][x2]-prefix[y1-1][x2]-prefix[y2][x1-1]+prefix[y1-1][x1-1];
        cout<<ans<<"\n";
    }
    
    return 0;
}