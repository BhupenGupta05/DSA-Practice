// You are given an array of n integers. You want to modify the array so that it is increasing, i.e., every element is at least as large as the previous element.
// On each move, you may increase the value of any element by one. What is the minimum number of moves required?
// Input
// The first input line contains an integer n: the size of the array.
// Then, the second line contains n integers x_1,x_2,\ldots,x_n: the contents of the array.
// Output
// Print the minimum number of moves.
// Constraints

// 1 \le n \le 2 \cdot 10^5
// 1 \le x_i \le 10^9

// Example
// Input:
// 5
// 3 2 5 1 7

// Output:
// 5

#include<bits/stdc++.h>
using namespace std;

long long increasingArray(vector<long long>& nums) {
    int n = nums.size();
    long long moves = 0;
    
    for(int i=1; i<n; i++) {
        if(nums[i] < nums[i-1]) {
            moves += (nums[i-1] - nums[i]);
            nums[i] = nums[i-1];        
        }
    }
    return moves;
}

int main() {
    int n;
    cin >> n;

    vector<long long> nums(n);
    
    for(int i=0; i<n; i++) {
        cin>>nums[i];
    }
    
    cout<<increasingArray(nums);
    return 0;
}