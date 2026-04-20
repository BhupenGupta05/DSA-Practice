// Given an array of n integers, your task is to process q queries of the form: what is the xor sum of values in range [a,b]?
// Input
// The first input line has two integers n and q: the number of values and queries.
// The second line has n integers x_1,x_2,\dots,x_n: the array values.
// Finally, there are q lines describing the queries. Each line has two integers a and b: what is the xor sum of values in range [a,b]?
// Output
// Print the result of each query.
// Constraints

// 1 \le n,q \le 2 \cdot 10^5
// 1 \le x_i \le 10^9
// 1 \le a \le b \le n

// Example
// Input:
// 8 4
// 3 2 4 5 1 1 5 3
// 2 4
// 5 6
// 1 8
// 3 3

// Output:
// 3
// 0
// 6
// 4

#include <bits/stdc++.h>
using namespace std;

struct SegTree {
    int n;
    vector<long long> tree;
    SegTree(int n): n(n), tree(4*n,0) {}
    
    // Building XOR for each range in segment tree
    void build(vector<long long>& nums, int node, int l, int r) {
        if(l == r) { //leaf node
            tree[node] = nums[l];
            return;
        }
        int mid = l + (r-l)/2;
        build(nums,2*node,l,mid); //left
        build(nums,2*node+1,mid+1,r); //right
        tree[node] = tree[2*node] ^ tree[2*node+1];
    }
    
    // Update val to index i (1-indexing)
    void update(int node, int l, int r, int idx, long long val) {
        if(l == r) {
            tree[node] = val;
            return;
        }
        int mid = l + (r-l)/2;
        if(idx <= mid) {
            update(2*node,l,mid,idx,val);
        } else {
             update(2*node+1,mid+1,r,idx,val);
        }
        tree[node] = tree[2*node] ^ tree[2*node+1];
    }
    
    //XOR query [ql....qr]
    int query(int node, int l, int r, int ql, int qr) {
        if(qr < l || r < ql) return 0; //out of bounds
        if(ql <= l && r <= qr) return tree[node]; //in range
        int mid = l + (r-l)/2;
        return query(2*node,l,mid,ql,qr) ^ query(2*node+1,mid+1,r,ql,qr);
    }
};

int main() {
    int n,q;
    cin >> n>>q;
    
   
    vector<long long> nums(n+1);
    for(int i=1; i<=n; i++) {
        cin>>nums[i];
    }
    
    // Build SegTree
    SegTree sTree(n);
    sTree.build(nums,1,1,n);
    
    for(int i=0; i<q; i++) {
        long long a,b;
        cin>>a>>b;
        cout<<sTree.query(1,1,n,a,b)<<"\n";
    }
    
    return 0;
}