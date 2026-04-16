// Given an array of n positive integers, your task is to count the number of subarrays having sum x.
// Input
// The first input line has two integers n and x: the size of the array and the target sum x.
// The next line has n integers a_1,a_2,\dots,a_n: the contents of the array.
// Output
// Print one integer: the required number of subarrays.
// Constraints

// 1 \le n \le 2 \cdot 10^5
// 1 \le x,a_i \le 10^9

// Example
// Input:
// 5 7
// 2 4 1 2 7

// Output:
// 3

#include <bits/stdc++.h>
using namespace std;

long long countSubarrays(vector<long long> &nums, long long k)
{
    int n = nums.size();

    map<long long, long long> prefix;

    prefix[0] = 1;
    long long currSum = 0;
    long long count = 0;

    for (int i = 0; i < n; i++)
    {
        currSum += nums[i];

        count += prefix[currSum - k];

        prefix[currSum]++;
    }
    return count;
}

int main()
{
    long long n, k;
    cin >> n >> k;

    vector<long long> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << countSubarrays(nums, k);

    return 0;
}