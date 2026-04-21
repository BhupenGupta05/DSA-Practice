// You are playing a game consisting of n planets. Each planet has a teleporter to another planet (or the planet itself).
// Your task is to process q queries of the form: when you begin on planet x and travel through k teleporters, which planet will you reach?
// Input
// The first input line has two integers n and q: the number of planets and queries. The planets are numbered 1,2,\dots,n.
// The second line has n integers t_1,t_2,\dots,t_n: for each planet, the destination of the teleporter. It is possible that t_i=i.
// Finally, there are q lines describing the queries. Each line has two integers x and k: you start on planet x and travel through k teleporters.
// Output
// Print the answer to each query.
// Constraints

// 1 \le n, q \le 2 \cdot 10^5
// 1 \le t_i \le n
// 1 \le x \le n
// 0 \le k \le 10^9

// Example
// Input:
// 4 3
// 2 1 1 4
// 1 2
// 3 4
// 4 1

// Output:
// 1
// 2
// 4

// Cycle detection (O(n*q))
#include <bits/stdc++.h>
using namespace std;

long long planetQueries(vector<vector<long long>>& graph, long long x, long long k) {

    if(k == 0) return x;
    
    long long curr = x;
    unordered_map<long long,long long> step;
    long long steps = 0;
    long long cycle_start = -1;
    long long cycle_length = 0;
    
    while(true) {
        if(step.count(curr)) {
            cycle_start = curr;
            cycle_length = steps - step[curr]; 
            break;
        }
        step[curr] = steps;
        steps++;
        curr = graph[curr][0];
    }
    
    // Before cycle
    if(k < step[cycle_start]) {
        curr = x;
        while(k--) {
            curr = graph[curr][0];
        }
        return curr;
    } 
    
    // Inside cycle
    long long d = step[cycle_start];
    long long rem = (k-d)%cycle_length;
    
    //Reach to cycle start
    curr = x;
    while(d--) {
        curr = graph[curr][0];
    }
    //Jump inside cycle
    while(rem--) {
        curr = graph[curr][0];
    }
    
    return curr;
}

int main() {
    long long n,q;
    cin>>n>>q;
    
    vector<vector<long long>> graph(n+1);
    for(int a=1; a<=n; a++) {
        long long b;
        cin>>b;
        graph[a].push_back(b);
    }
    
    while(q--) {
        long long a,b;
        cin>>a>>b;
        cout<<planetQueries(graph,a,b);
    }

    return 0;
}


// Binary Lifting (O(n log n))
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    const int LOG = 30; // since k ≤ 1e9

    vector<vector<int>> up(n + 1, vector<int>(LOG));

    // input: direct teleport (2^0 jumps)
    for (int i = 1; i <= n; i++) {
        cin >> up[i][0];
    }

    // build binary lifting table
    for (int j = 1; j < LOG; j++) {
        for (int i = 1; i <= n; i++) {
            up[i][j] = up[ up[i][j - 1] ][j - 1];
        }
    }

    // process queries
    while (q--) {
        int x;
        long long k;
        cin >> x >> k;

        int curr = x;

        for (int j = 0; j < LOG; j++) {
            if (k & (1LL << j)) {
                curr = up[curr][j];
            }
        }

        cout << curr << '\n';
    }

    return 0;
}