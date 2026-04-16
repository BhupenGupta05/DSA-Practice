// In a movie festival n movies will be shown. You know the starting and ending time of each movie. What is the maximum number of movies you can watch entirely?
// Input
// The first input line has an integer n: the number of movies.
// After this, there are n lines that describe the movies. Each line has two integers a and b: the starting and ending times of a movie.
// Output
// Print one integer: the maximum number of movies.
// Constraints

// 1 \le n \le 2 \cdot 10^5
// 1 \le a < b \le 10^9

// Example
// Input:
// 3
// 3 5
// 4 9
// 5 8

// Output:
// 2

// We can try to wathc movies which end earliest so we can watch more.
// So, we try to sort the movies by their ending times and then we can greedily select the movies which start after the last selected movie's ending time.


#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<pair<long long,long long>> movies(n);
    
    for(int i=0; i<n; i++) {
        cin>>movies[i].first>>movies[i].second;
    }
    
    sort(movies.begin(),movies.end(),[](auto &a, auto &b) {
        return a.second < b.second;
    });
    
    long long lastEnd=0;
    int count=0;
    
    for(auto& movie: movies) {
        if(movie.first >= lastEnd) {
            count++;
            lastEnd = movie.second;
        }
    }
    
    cout<<count;
    
    return 0;
}