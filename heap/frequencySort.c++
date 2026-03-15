// Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

// Return the sorted string. If there are multiple answers, return any of them.

#include <bits/stdc++.h>
using namespace std;

string frequencySort(string s) {
    int n = s.length();
    string res = "";
    
    unordered_map<char,int> freq;
    priority_queue<pair<int,char>> pq;
    
    for(int i=0; i<n; i++) {
        freq[s[i]]++;
    }
    
    for(auto[ch,cnt]: freq) {
        pq.push({cnt,ch});
    }
    
    while(!pq.empty()) {
        auto[cnt,ch] = pq.top();
        pq.pop();
        
        while(cnt > 0) {
            res += ch;
            cnt--;
        }
    }
    return res;
}

int main()
{
	string s = "tree";
	
	string ans = frequencySort(s);
	
	for(int i=0; i<ans.length(); i++) {
	    cout<<ans[i];
	}

	return 0;
}