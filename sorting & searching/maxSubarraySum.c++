// Given an array of n integers, your task is to find the maximum sum of values in a contiguous, nonempty subarray.
// Input
// The first input line has an integer n: the size of the array.
// The second line has n integers x_1,x_2,\dots,x_n: the array values.
// Output
// Print one integer: the maximum subarray sum.
// Constraints

// 1 \le n \le 2 \cdot 10^5
// -10^9 \le x_i \le 10^9

// Example
// Input:
// 8
// -1 3 -2 5 3 -5 2 2

// Output:
// 9

// TC - O(N)

#include<bits/stdc++.h>
using namespace std;

long long maxSubarraySum(vector<int>& nums) {
    int n = nums.size();

    long long globalMax = nums[0];
    long long currMax = nums[0];

    for(int i=1; i<n; i++) {
        currMax = max(currMax + nums[i],(long long)nums[i]);

        globalMax = max(currMax,globalMax);
    }
    return globalMax;
}

int main() {
    int n;
    cin>>n;
    
    vector<int> nums(n);
    
    for(int i=0; i<n; i++) {
        cin>>nums[i];
    }
    
    cout<<maxSubarraySum(nums);
    return 0;
}