#include <bits/stdc++.h>
using namespace std;

vector<long long> slidingWindowDistinct(vector<long long>& nums, long long k) {
    long long n = nums.size();
    map<long long,long long> umap;
    vector<long long> res;
    long long start = 0;
    
    for(int end=0; end<n; end++) {
        umap[nums[end]]++;
        while(end-start > k-1) {
            umap[nums[start]]--;
            if(umap[nums[start]] == 0) {
                umap.erase(nums[start]);
            }
            start++;
        }
        if(end-start == k-1) {
            res.push_back(umap.size());
        }
    }
    
    return res;
}

int main() {
    long long n,k;
    cin>>n>>k;
    
    vector<long long> nums(n);
    for(int i=0; i<n; i++) {
        cin>>nums[i];
    }
    
    vector<long long> ans = slidingWindowDistinct(nums,k);
    
    for(auto x: ans) {
        cout<<x<<" ";
    }

    return 0;
}