// You are in a book shop which sells n different books. You know the price and number of pages of each book.
// You have decided that the total price of your purchases will be at most x. What is the maximum number of pages you can buy? You can buy each book at most once.
// Input
// The first input line contains two integers n and x: the number of books and the maximum total price.
// The next line contains n integers h_1,h_2,\ldots,h_n: the price of each book.
// The last line contains n integers s_1,s_2,\ldots,s_n: the number of pages of each book.
// Output
// Print one integer: the maximum number of pages.
// Constraints

// 1 \le n \le 1000
// 1 \le x \le 10^5
// 1 \le h_i, s_i \le 1000

// Example
// Input:
// 4 10
// 4 8 5 3
// 5 12 8 1

// Output:
// 13


#include <bits/stdc++.h>
using namespace std;

long long bookShop(int n, int x, vector<long long>& prices, vector<long long>& pages) {
    vector<long long> dp(x+1,0);
    
    for(int i = 0; i < n; i++) {
        for(int j=x; j>=prices[i]; j--) {
            dp[j] = max(dp[j],dp[j-prices[i]] + pages[i]);
        }
    }
    
    return dp[x];
}


int main() {
    int n,x;
    cin >> n >> x;
    
    vector<long long> prices(n);
    for(int i = 0; i < n; i++) {
        cin >> prices[i];
    }
    
    vector<long long> pages(n);
    for(int i = 0; i < n; i++) {
        cin >> pages[i];
    }
    
    cout << bookShop(n, x, prices, pages);
    return 0;
}


// #include <bits/stdc++.h>
// using namespace std;

// long long bookShop(int n, int x, vector<long long>& prices, vector<long long>& pages, vector<vector<long long>>& dp) {
  
//     if(n == 0 || x == 0) return 0;
    
//     if(dp[n][x] != -1) return dp[n][x];
    
//     if(prices[n-1] <= x) {
//         dp[n][x] = max(pages[n-1] + bookShop(n-1,x-prices[n-1], prices, pages, dp), bookShop(n-1,x, prices, pages, dp));
//     } else if(prices[n-1] > x) {
//          dp[n][x] = bookShop(n-1,x, prices, pages, dp);
//     }
//     return dp[n][x];
// }


// int main() {
//     int n,x;
//     cin >> n >> x;
    
//     vector<long long> prices(n);
//     for(int i = 0; i < n; i++) {
//         cin >> prices[i];
//     }
    
//     vector<long long> pages(n);
//     for(int i = 0; i < n; i++) {
//         cin >> pages[i];
//     }
    
//     vector<vector<long long>> dp(n+1, vector<long long>(x+1, -1));
//     cout << bookShop(n, x, prices, pages, dp);
//     return 0;
// }