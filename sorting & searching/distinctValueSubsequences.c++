// Given an array of n integers, count the number of subsequences where each element is distinct.
// A subsequence is a sequence of array elements from left to right that may have gaps.
// Input
// The first line has an integer n: the array size.
// The second line has n integers x_1,x_2,\dots,x_n: the array contents.
// Output
// Print the number of subsequences with distinct elements. The answer can be large, so print it modulo 10^9+7.
// Constraints

// 1 \le n \le 2 \cdot 10^5
// 1 \le x_i \le 10^9

// Example
// Input:
// 4
// 1 2 1 3

// Output:
// 11

// Explanation: The subsequences are [1] (two times), [2], [3], [1,2], [1,3] (two times), [2,1], [2,3], [1,2,3] and [2,1,3].

// Since the picking and excluding of elements are independent, we can count the frequency of each distinct element 
// and calculate the number of subsequences as (f+1) for each element, where f is the frequency of the i-th distinct element. We subtract 1 to exclude the empty subsequence.

#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;

    vector<long long> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    map<long long, long long> freq;
    for(auto x : nums) {
        freq[x]++;
    }

    long long ans = 1;

    for(auto [val, f] : freq) {
        ans = (ans * (f + 1)) % MOD; 
    }

    cout << (ans - 1 + MOD) % MOD;
}