// You are given a playlist of a radio station since its establishment. The playlist has a total of n songs.
// What is the longest sequence of successive songs where each song is unique?
// Input
// The first input line contains an integer n: the number of songs.
// The next line has n integers k_1,k_2,\ldots,k_n: the id number of each song.
// Output
// Print the length of the longest sequence of unique songs.
// Constraints

// 1 \le n \le 2 \cdot 10^5
// 1 \le k_i \le 10^9

// Example
// Input:
// 8
// 1 2 1 3 2 7 4 2

// Output:
// 5

#include <bits/stdc++.h>
using namespace std;

int longestSequence(vector<long long>& nums) {
    int n = nums.size();
    
    map<long long,long long> seq;
    int maxLen = 0;
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
        maxLen = max(maxLen,end-start+1);
    }
    
    return maxLen;
}

int main() {
    int n;
    cin>>n;
    
    vector<long long> nums(n);
    for(int i=0; i<n; i++) {
        cin>>nums[i];
    }
    
    cout<<longestSequence(nums);
    
    return 0;
}