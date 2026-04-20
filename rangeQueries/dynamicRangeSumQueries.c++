// Given an array of n integers, your task is to process q queries of the following types:

// update the value at position k to u
// what is the sum of values in range [a,b]?

// Input
// The first input line has two integers n and q: the number of values and queries.
// The second line has n integers x_1,x_2,\dots,x_n: the array values.
// Finally, there are q lines describing the queries. Each line has three integers: either "1 k u" or "2 a b".
// Output
// Print the result of each query of type 2.
// Constraints

// 1 \le n,q \le 2 \cdot 10^5
// 1 \le x_i, u \le 10^9
// 1 \le k \le n
// 1 \le a \le b \le n

// Example
// Input:
// 8 4
// 3 2 4 5 1 1 5 3
// 2 1 4
// 2 5 6
// 1 3 1
// 2 1 4

// Output:
// 14
// 2
// 11


#include <bits/stdc++.h>
using namespace std;

struct BIT {
    int n;
    vector<long long> tree;
    BIT(int n): n(n), tree(n+1,0) {}
    
    // Add val to index i (1-indexing)
    void update(int i, long long val) {
        for(; i<=n; i+=i & (-i)) {
            tree[i] += val;
        }
    }
    
    // Sum of [1...i]
    long long query(int i) {
        long long sum = 0;
        for(; i>0; i-=i & (-i)) {
            sum += tree[i];
        }
        return sum;
    }
    
    // Sum of [l...r]
    long long query(int l, int r) {
        return query(r) - query(l-1);
    }
    
    // Value at index i
    long long pointQuery(int i) {
        return query(i,i);
    }
};

int main() {
    int n,q;
    cin >> n>>q;
    
   
    vector<long long> nums(n);
    for(int i=0; i<n; i++) {
        cin>>nums[i];
    }
    
    // Build bit
    BIT bit(n);
    for(int i=0; i<n; i++) {
        bit.update(i+1,nums[i]);
    }
    
    for(int i=0; i<q; i++) {
        long long a,b,c;
        cin>>a>>b>>c;
        if(a == 1) {
            long long oldVal = bit.pointQuery(b);
            bit.update(b,c-oldVal);
        } else if(a == 2) {
            cout<<bit.query(b,c)<<"\n";
        }
    }
    
    return 0;
}