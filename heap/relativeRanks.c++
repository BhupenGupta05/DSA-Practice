// You are given an integer array score of size n, where score[i] is the score of the ith athlete in a competition. All the scores are guaranteed to be unique.

// The athletes are placed based on their scores, where the 1st place athlete has the highest score, the 2nd place athlete has the 2nd highest score, and so on. The placement of each athlete determines their rank:

// The 1st place athlete's rank is "Gold Medal".
// The 2nd place athlete's rank is "Silver Medal".
// The 3rd place athlete's rank is "Bronze Medal".
// For the 4th place to the nth place athlete, their rank is their placement number (i.e., the xth place athlete's rank is "x").
// Return an array answer of size n where answer[i] is the rank of the ith athlete.
#include <bits/stdc++.h>
using namespace std;

vector<string> findRelativeRanks(vector<int>& score) {
	int n = score.size();
	vector<string> answer(n,"");
	priority_queue<pair<int,int>> pq;

	for(int i=0; i<n; i++) {
		pq.push({score[i],i});
		answer[i] = to_string(score[i]);
	}

	int count=0;
	while(!pq.empty()) {

		auto[val,idx] = pq.top();
		count++;
		pq.pop();


		if(count == 1) {
			answer[idx] = "Gold Medal";
		} else if(count == 2) {
			answer[idx] = "Silver Medal";
		} else if(count == 3) {
			answer[idx] = "Bronze Medal";
		} else {
		    answer[idx] = to_string(count);
		}
	}

	return answer;

}
int main()
{
	vector<int> score = {10,3,8,9,4};

	vector<string> ans = findRelativeRanks(score);

	for(auto num: ans) {
		cout<<num<<" ";
	}

	return 0;
}