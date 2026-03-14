// You are given two integer arrays nums1 and nums2 sorted in non-decreasing order and an integer k.

// Define a pair (u, v) which consists of one element from the first array and one element from the second array.

// Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
	int n1 = nums1.size();
	int n2 = nums2.size();
	vector<vector<int>> res;

	priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;

	for(int i=0; i<n1; i++) {
		pq.push({nums1[i] + nums2[0], i, 0});
	}

	while(!pq.empty()) {
		auto[sum,x,y] = pq.top();
		pq.pop();

		res.push_back({nums1[x],nums2[y]});
		
		if(y+1 < n2) {
		    pq.push({nums1[x] + nums2[y+1], x, y+1});
		}

		if(res.size() == k) break;
	}
	return res;
}

int main()
{
	vector<int> nums1 = {1,7,11}, nums2 = {2,4,6};
	int k = 3;

	vector<vector<int>> ans = kSmallestPairs(nums1,nums2,k);

	for(auto pairs: ans) {
		for(int num: pairs) {
			cout<<num<<" ";
		}
		cout<<endl;
	}

	return 0;
}