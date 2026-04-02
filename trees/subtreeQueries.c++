// You are given a rooted tree consisting of n nodes. The nodes are numbered 1,2,\ldots,n, and node 1 is the root. Each node has a value.
// Your task is to process following types of queries:

// change the value of node s to x
// calculate the sum of values in the subtree of node s

// Input
// The first input line contains two integers n and q: the number of nodes and queries. The nodes are numbered 1,2,\ldots,n.
// The next line has n integers v_1,v_2,\ldots,v_n: the value of each node.
// Then there are n-1 lines describing the edges. Each line contans two integers a and b: there is an edge between nodes a and b.
// Finally, there are q lines describing the queries. Each query is either of the form "1 s x" or "2 s".
// Output
// Print the answer to each query of type 2.
// Constraints

// 1 \le n, q \le 2 \cdot 10^5
// 1 \le a,b, s \le n
// 1 \le v_i, x \le 10^9

// Example
// Input:
// 5 3
// 4 2 5 2 1
// 1 2
// 1 3
// 3 4
// 3 5
// 2 3
// 1 5 3
// 2 3

// Output:
// 8
// 10

// Approach 1: Run DFS for each query of type 2. 
// This will be O(n) per query, which is not efficient for large q.

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> tree;
vector<int> subtree_size;
vector<int> subtree_sum;
vector<int> node_val;

void dfs(int node, int parent) {
    subtree_size[node] = 1;
    subtree_sum[node] = node_val[node];
    
    for(auto child: tree[node]) {
        if(child != parent) {
            dfs(child,node);
            subtree_size[node] += subtree_size[child];
            subtree_sum[node] += subtree_sum[child];
        }
    }
}

vector<int> subtreeQueries(vector<vector<int>>& tree) {
    
}

int main()
{
    int n,q;
    cin>>n>>q;
    
    tree.resize(n+1);
    subtree_size.assign(n+1,0);
    node_val.resize(n+1);
    subtree_sum.assign(n+1, 0);
    
    for(int i=1; i<=n; i++) {
        cin>>node_val[i];
    }
    
    for(int i=0; i<n-1; i++) {
        int a,b;
        cin>>a>>b;
        
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    
    dfs(1,-1);
    
    for(int i=0; i<q; i++) {
        int type;
        cin>>type;
        
        if(type == 1) {
            int s,x;
            cin>>s>>x;
            node_val[s] = x;
            dfs(1,-1);
        } else if(type == 2) {
            int s;
            cin>>s;
            cout << subtree_sum[s] << endl;
        }
    }

    return 0;
}


// Approach 2: Use Euler Tour and Fenwick Tree (Binary Indexed Tree) for efficient updates and queries.
// Not implemented yet, but the idea is to perform an Euler Tour of the tree to flatten it into an array.

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> tree;
vector<int> node_val;
vector<int> in;
vector<int> out;
vector<int> euler;
vector<int> flat;
vector<long long> bit;
int timer=0;

void dfs(int node, int parent) {
    in[node] = timer;
    euler.push_back(node);
    flat[timer] = node_val[node];
    timer++;
    
    for(auto child: tree[node]) {
        if(child != parent) {
            dfs(child,node);
        }
    }
    out[node] = timer-1;
}

void update(int i, long long val) {
    
}

vector<int> subtreeQueries(vector<vector<int>>& tree) {
    
}

int main()
{
    int n;
    cin>>n;
    
    tree.resize(n+1);
    node_val.resize(n+1);
    flat.resize(n);
    in.resize(n+1);
    out.resize(n+1);
    bit.resize(n+1,0);
    
    for(int i=1; i<=n; i++) {
        cin>>node_val[i];
    }
    
    for(int i=0; i<n-1; i++) {
        int a,b;
        cin>>a>>b;
        
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    
    dfs(1,-1);
    
    for(int i=0; i<n; i++) {
        cout<<euler[i]<<" ";
    }
    cout<<endl;
    
     for(int i=1; i<=n; i++) {
        cout<<in[i]<<" ";
    }
    cout<<endl;
    
    for(int i=1; i<=n; i++) {
        cout<<out[i]<<" ";
    }
    
    cout<<endl;
    
    for(int i=0; i<n; i++) {
        cout<<flat[i]<<" ";    
        
    }
    
    // for(int i=0; i<q; i++) {
    //     int type;
    //     cin>>type;
        
    //     if(type == 1) {
    //         int s,x;
    //         cin>>s>>x;
    //         node_val[s] = x;
    //         dfs(1,-1);
    //     } else if(type == 2) {
    //         int s;
    //         cin>>s;
    //         cout << subtree_sum[s] << endl;
    //     }
    // }

    return 0;
}