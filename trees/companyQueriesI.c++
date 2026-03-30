// A company has n employees, who form a tree hierarchy where each employee has a boss, except for the general director.
// Your task is to process q queries of the form: who is employee x's boss k levels higher up in the hierarchy?
// Input
// The first input line has two integers n and q: the number of employees and queries. The employees are numbered 1,2,\dots,n, and employee 1 is the general director.
// The next line has n-1 integers e_2,e_3,\dots,e_n: for each employee 2,3,\dots,n their boss.
// Finally, there are q lines describing the queries. Each line has two integers x and k: who is employee x's boss k levels higher up?
// Output
// Print the answer for each query. If such a boss does not exist, print -1.
// Constraints

// 1 \le n,q \le 2 \cdot 10^5
// 1 \le e_i \le i-1
// 1 \le x \le n
// 1 \le k \le n

// Example
// Input:
// 5 3
// 1 1 3 3
// 4 1
// 4 2
// 4 3

// Output:
// 3
// 1
// -1


#include <bits/stdc++.h>
using namespace std;

const int LOG = 20;

vector<vector<int>> tree;
vector<vector<int>> up;

void dfs(int node, int parent) {
    up[node][0] = parent;
    
    for(int j=1; j<LOG; j++) {
        if(up[node][j-1] != -1) {
            up[node][j] = up[up[node][j-1]][j-1];
        }
    }
    
    for(auto child: tree[node]) {
        if(child != parent) {
            dfs(child,node);
        }
    }
}

int kthAncestor(int node, int k) {
    for(int i=0; i<LOG; i++) {
        if(k & (1 << i)) {
            node = up[node][i];
            if(node == -1) return -1;
        }
    }
    return node;
}

int main()
{
	int n,q;
	cin>>n>>q;

	tree.resize(n+1);
	up.assign(n+1, vector<int>(LOG,-1));

	for(int i=2; i<=n; i++) {
		int x;
		cin>>x;

		tree[x].push_back(i);
	}
	
	dfs(1,-1);
	
	for(int i=0; i<q; i++) {
	    int a,b;
	    cin>>a>>b;
	   cout << kthAncestor(a,b) << "\n";
	}


	return 0;
}