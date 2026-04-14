// You are given a DNA sequence: a string consisting of characters A, C, G, and T. Your task is to find the longest repetition in the sequence. This is a maximum-length substring containing only one type of character.
// Input
// The only input line contains a string of n characters.
// Output
// Print one integer: the length of the longest repetition.
// Constraints

// 1 \le n \le 10^6

// Example
// Input:
// ATTCGGGA

// Output:
// 3


#include<bits/stdc++.h>
using namespace std;

int maxDNASequence(vector<char>& dna) {
    int n = dna.size();
    int currLen=1;
    int maxLen=1;
    
    for(int i=1; i<n; i++) {
        int len;
        if(dna[i] == dna[i-1]) {
            currLen++;
        } else {
            currLen = 1;
        }
        maxLen = max(maxLen,currLen);
    }
    return maxLen;
}

int main() {
    string s;
    cin >> s;

    vector<char> dna(s.begin(), s.end());
    
    cout<<maxDNASequence(dna);
    return 0;
}