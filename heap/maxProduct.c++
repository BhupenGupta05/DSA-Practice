// Given the array of integers nums, you will choose two different indices i and j of that array. Return the maximum value of (nums[i]-1)*(nums[j]-1).

#include <bits/stdc++.h>
using namespace std;

int maxProduct(vector<int> &nums)
{
    int n = nums.size();

    priority_queue<int> pq;

    for (int i = 0; i < n; i++)
    {
        pq.push(nums[i]);
    }

    int a = pq.top();
    pq.pop();
    int b = pq.top();
    pq.pop();

    return (a - 1) * (b - 1);
}

int main()
{
    vector<int> nums = {1, 5, 4, 5};
    cout << maxProduct(nums) << endl;

    return 0;
}