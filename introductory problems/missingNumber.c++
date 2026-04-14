// You are given all numbers between 1,2,\ldots,n except one. Your task is to find the missing number.
// Input
// The first input line contains an integer n.
// The second line contains n-1 numbers. Each number is distinct and between 1 and n (inclusive).
// Output
// Print the missing number.
// Constraints

// 2 \le n \le 2 \cdot 10^5

// Example
// Input:
// 5
// 2 3 1 5

// Output:
// 4


// Approach 1 - Using extra space
// TC - O(N)
// SC - O(N)

#include<bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>& nums) {
    int n = nums.size();
    
    vector<int> temp(n+1,0);
    
    for(int i=0; i<n-1; i++) {
        temp[nums[i]]++;
    }
    
    for(int i=1; i<=n; i++) {
        if(temp[i] == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n;
    cin>>n;
    
    vector<int> nums(n);
    
    for(int i=0; i<n; i++) {
        cin>>nums[i];
    }
    
    cout<<missingNumber(nums);
    return 0;
}



// Approach 2 - Using sum formula
// TC - O(N)
// SC - O(1)

#include<bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>& nums) {
    int n = nums.size();
    
    long long actualSum = 0;
    long long expectedSum = n*(n+1)/2;
    
    for(int i=0; i<n; i++) {
        actualSum += nums[i];
    }
    
    return expectedSum-actualSum;
}

int main() {
    int n;
    cin>>n;
    
    vector<int> nums(n);
    
    for(int i=0; i<n; i++) {
        cin>>nums[i];
    }
    
    cout<<missingNumber(nums);
    return 0;
}