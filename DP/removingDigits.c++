// You are given an integer n. On each step, you may subtract one of the digits from the number.
// How many steps are required to make the number equal to 0?
// Input
// The only input line has an integer n.
// Output
// Print one integer: the minimum number of steps.
// Constraints

// 1 \le n \le 10^6

// Example
// Input:
// 27

// Output:
// 5

// Explanation: An optimal solution is 27 \rightarrow 20 \rightarrow 18 \rightarrow 10 \rightarrow 9 \rightarrow 0.

#include <bits/stdc++.h>
using namespace std;

long long maxDigitValue(long long n) {
    long long maxVal = LLONG_MIN;
    long long temp = n;

    while(temp != 0) {
        long long digit = temp%10;
        temp /= 10;
        maxVal = max(maxVal,digit);
    }
    return maxVal;
}


int main() {
    long long n;
    cin>>n;

    long long count = 0;
    long long temp = n;
    while(temp != 0) {
        temp -= maxDigitValue(temp);
        count++;
    }
    
    cout<<count;
    return 0;
}