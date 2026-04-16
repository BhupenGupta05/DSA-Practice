// You are given the arrival and leaving times of n customers in a restaurant.
// What was the maximum number of customers in the restaurant at any time?
// Input
// The first input line has an integer n: the number of customers.
// After this, there are n lines that describe the customers. Each line has two integers a and b: the arrival and leaving times of a customer.
// You may assume that all arrival and leaving times are distinct.
// Output
// Print one integer: the maximum number of customers.
// Constraints

// 1 \le n \le 2 \cdot 10^5
// 1 \le a < b \le 10^9

// Example
// Input:
// 3
// 5 8
// 2 4
// 3 9

// Output:
// 2

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<pair<int,int>> events;
    
    for(int i=0; i<n; i++) {
        long long a,b;
        cin>>a>>b;
        events.push_back({a,1});
        events.push_back({b,-1});
    }
    
    sort(events.begin(),events.end());
    
    int curr = 0, max_people = 0;
    
    for(auto e: events) {
        curr += e.second;
        max_people = max(max_people,curr);
    }
    
    cout<<max_people;
    
    return 0;
}