// Memory limit: 512 MB

// You are given a list of n integers, and your task is to calculate the number of distinct values in the list.
// Input
// The first input line has an integer n: the number of values.
// The second line has n integers x_1,x_2,\dots,x_n.
// Output
// Print one integers: the number of distinct values.
// Constraints

// 1 \le n \le 2 \cdot 10^5
// 1 \le x_i \le 10^9

// Example
// Input:
// 5
// 2 3 2 2 3

// Output:
// 2

// Approach 1: Using unordered_set
#include <bits/stdc++.h>
using namespace std;

int distinctNumbers(vector<int>& nums) {
    int n = nums.size();
    unordered_set<int> s;
    
    for(int i=0; i<n; i++) {
        s.insert(nums[i]);
    }
    return s.size();
}


int main()
{
    int n;
    cin>>n;
    
    vector<int> nums(n);
    
    for(int i=0; i<n; i++) {
        cin>>nums[i];
    }
    
    cout<<distinctNumbers(nums);


    return 0;
}


// Approach 2: Using set and sorting
int distinctNumbers(vector<int>& nums) {
    set<int> s(nums.begin(), nums.end());
    return s.size();
}
