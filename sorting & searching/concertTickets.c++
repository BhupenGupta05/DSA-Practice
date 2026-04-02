// There are n concert tickets available, each with a certain price. Then, m customers arrive, one after another.
// Each customer announces the maximum price they are willing to pay for a ticket, and after this, they will get a ticket with the nearest possible price such that it does not exceed the maximum price.
// Input
// The first input line contains integers n and m: the number of tickets and the number of customers.
// The next line contains n integers h_1,h_2,\ldots,h_n: the price of each ticket.
// The last line contains m integers t_1,t_2,\ldots,t_m: the maximum price for each customer in the order they arrive.
// Output
// Print, for each customer, the price that they will pay for their ticket. After this, the ticket cannot be purchased again.
// If a customer cannot get any ticket, print -1.
// Constraints

// 1 \le n, m \le 2 \cdot 10^5
// 1 \le h_i, t_i \le 10^9

// Example
// Input:
// 5 3
// 5 3 7 8 5
// 4 8 3

// Output:
// 3
// 8
// -1

#include <bits/stdc++.h>
using namespace std;

vector<int> concertTickets(vector<int>& prices, vector<int>& maxPrices) {
    vector<int> ans;
    
    // Stores the ticket prices in a sorted manner, 
    // allowing for efficient searching and deletion. (O(logN) for search and O(1) for deletion)
    // Allows duplicates
    multiset<int> tickets(prices.begin(),prices.end());
    for(int x: maxPrices) {

        // Find the ticket price just greater than x
        auto it = tickets.upper_bound(x);
        
        // If there is no ticket price less than or equal to x, return -1
        if(it == tickets.begin()) {
            ans.push_back(-1);
        } 
        // Otherwise, we have to push the ticket price at it-1
        else {
            it--; 
            ans.push_back(*it); // * it gives the value at the iterator it
            tickets.erase(it); // Erase the ticket price at it
        }
    }
    return ans;
}

int main()
{
    int n,m;
    cin>>n>>m;
    
    vector<int> prices(n);
    vector<int> maxPrices(m);
    
    for(int i=0; i<n; i++) {
        cin>>prices[i];
    }
    
    for(int i=0; i<m; i++) {
        cin>>maxPrices[i];
    }
    
    vector<int> res = concertTickets(prices,maxPrices);
    
    for(auto p: res) {
        cout<<p<<" ";
    }


    return 0;
}