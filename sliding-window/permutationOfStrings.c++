// Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

// In other words, return true if one of s1's permutations is the substring of s2.

#include <bits/stdc++.h>

using namespace std;

bool checkInclusion(string s1, string s2) {
	int len1 = s1.length();
	int len2 = s2.length();

	if(len1 > len2) return false;

	unordered_map<char,int> freq1, freq2;
	int i=0, j=0;

	for(int i=0; i<len1; i++) {
		freq1[s1[i]]++;
		freq2[s2[i]]++;
	}

	if(freq1 == freq2) return true;

	for(int i=len1; i<len2; i++) {
		freq2[s2[i]]++;

		char toBeErased = s2[i-len1];
		freq2[toBeErased]--;
		if(freq2[toBeErased] == 0) {
			freq2.erase(toBeErased);
		}
		
		if(freq1 == freq2) return true;
	}
	return false;
}

int main()
{
	string s1 = "ab", s2 = "eidbaooo";

	cout<<checkInclusion(s1,s2);

	return 0;
}