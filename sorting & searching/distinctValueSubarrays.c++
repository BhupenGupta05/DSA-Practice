// Given an array of n integers, count the number of subarrays where each element is distinct.
// Input
// The first line has an integer n: the array size.
// The second line has n integers x_1,x_2,\dots,x_n: the array contents.
// Output
// Print the number of subarrays with distinct elements.
// Constraints

// 1 \le n \le 2 \cdot 10^5
// 1 \le x_i \le 10^9

// Example
// Input:
// 4
// 1 2 1 3

// Output:
// 8

// Explanation: The subarrays are [1] (two times), [2], [3], [1,2], [1,3], [2,1] and [2,1,3].

#include <bits/stdc++.h>
using namespace std;

long long longestDistinctSubarrays(vector<long long>& nums) {
    int n = nums.size();
    
    map<long long,long long> seq;
    long long count = 0;
    int start = 0;
    
    for(int end=0; end<n; end++) {
        seq[nums[end]]++;
        
        while(seq[nums[end]] > 1) {
            seq[nums[start]]--;
            if(seq[nums[start]] == 0) {
                seq.erase(nums[start]);
            }
            start++;
        }
        count += end-start+1;
    }
    
    return count;
}

int main() {
    int n;
    cin>>n;
    
    vector<long long> nums(n);
    for(int i=0; i<n; i++) {
        cin>>nums[i];
    }
    
    cout<<longestDistinctSubarrays(nums);
    
    return 0;
}