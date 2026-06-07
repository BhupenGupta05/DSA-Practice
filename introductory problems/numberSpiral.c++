// A number spiral is an infinite grid whose upper-left square has number 1. Here are the first five layers of the spiral:

// Your task is to find out the number in row y and column x.
// Input
// The first input line contains an integer t: the number of tests.
// After this, there are t lines, each containing integers y and x.
// Output
// For each test, print the number in row y and column x.
// Constraints

// 1 \le t \le 10^5
// 1 \le y,x \le 10^9

// Example
// Input:
// 3
// 2 3
// 1 1
// 4 2

// Output:
// 8
// 1
// 15

// 1   2   9   10   25
// 4   3   8   11   24 
// 5   6   7   12   23
// 16  15  14  13   22
// 17  18  19  20   21

// We can divide this into layers. Layer will be defined as whenever one spiral completes
// Let's say, it move from 1(LAYER 1), then 2 -> 3 -> 4(LAYER 2)
// It can be derived as max(y,x) (1-based index)
// We can notice that odd numbers' square are on uppermost row (1,n) and even ones are on leftmost column (n,1)
// Say, we have to find the value of (3,5). It sits closest to 25(5*5), we can just add the difference of (1,5) and (3,5) to 25
// Another example, say, we have to find the value of (2,4), the closest square we can see is 9, which 4-1 = 3's square.
// And then, we can add y to the square.
// Logic is to find which is greater (y or x), then based on it being even or odd, figure out, which is the closest square to it
// And then from there add the distance to the square or decrease from the square.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        long long y, x;
        cin >> y >> x;

        long long ans;

        if (x >= y)
        {
            if (x % 2 == 1)
                ans = x * x - y + 1;
            else
                ans = (x - 1) * (x - 1) + y;
        }
        else
        {
            if (y % 2 == 1)
                ans = (y - 1) * (y - 1) + x;
            else
                ans = y * y - x + 1;
        }
        cout << ans << "\n";
    }

    return 0;
}