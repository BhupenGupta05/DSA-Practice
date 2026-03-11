// You are given two lists of closed intervals, firstList and secondList, where firstList[i] = [starti, endi] and secondList[j] = [startj, endj]. Each list of intervals is pairwise disjoint and in sorted order.

// Return the intersection of these two interval lists.

// A closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.

// The intersection of two closed intervals is a set of real numbers that are either empty or represented as a closed interval. For example, the intersection of [1, 3] and [2, 4] is [2, 3].


#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
    int m = firstList.size();
    int n = secondList.size();
    
    if(m == 0) return firstList;
    
    if(n == 0) return secondList;
    
    int i=0, j=0;
    vector<vector<int>> res;
    
    while(i < m && j < n) {
        int lo = max(firstList[i][0], secondList[j][0]);
        int hi = min(firstList[i][1], secondList[j][1]);
        
        if(lo <= hi) {
            res.push_back({lo,hi});
        }
        
        if(firstList[i][1] < secondList[j][1]) {
            i++;
        } else {
            j++;
        }
    }
    return res;
}

int main()
{
    vector<vector<int>> firstList = {{0,2},{5,10},{13,23},{24,25}};
    vector<vector<int>> secondList = {{1,5},{8,12},{15,24},{25,26}};
    
    vector<vector<int>> ans = intervalIntersection(firstList, secondList);
    
    for(auto pairs: ans) {
        for(auto x: pairs) {
            cout<<x<<" ";
        }
        cout<<endl;
    }

	return 0;
}