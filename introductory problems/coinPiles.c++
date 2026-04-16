// You have two coin piles containing a and b coins. On each move, you can either remove one coin from the left pile and two coins from the right pile, or two coins from the left pile and one coin from the right pile.
// Your task is to efficiently find out if you can empty both the piles.
// Input
// The first input line has an integer t: the number of tests.
// After this, there are t lines, each of which has two integers a and b: the numbers of coins in the piles.
// Output
// For each test, print "YES" if you can empty the piles and "NO" otherwise.
// Constraints

// 1 \le t \le 10^5
// 0 \le a, b \le 10^9

// Example
// Input:
// 3
// 2 1
// 2 2
// 3 3

// Output:
// YES
// NO
// YES

// Here the sum of a and b should be divisible by 3, and the larger pile should not have more than twice the coins of the smaller pile. 
// This is because in each move, you are removing a total of 3 coins (either 1 from one pile and 2 from the other, or vice versa). 
// Therefore, if the total number of coins is not divisible by 3, it is impossible to empty both piles. 
// Additionally, if one pile has more than twice the coins of the other pile, it will not be possible to balance them out and empty both piles at the same time.



#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    for(int i=0; i<t; i++) {
        long long a,b;
        cin>>a>>b;
        
        if((a+b)%3 == 0 && max(a,b) <= 2*min(a,b)) {
        cout<<"YES\n";    
            
        } else {
            cout<<"NO\n";
        }
    }
    
    return 0;
}