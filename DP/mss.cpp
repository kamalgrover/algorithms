//https://leetcode.com/problems/maximum-subarray/
#include <iostream>
#include <vector>
using namespace std;
int maxSubArray(vector<int> &nums)
{
    int i, n = nums.size(); // nums array is zero based.
    long long cMax, pMax;
    long long ans = INT_MIN;
    cMax = pMax = ans;
    for (int i = 0; i < n; i++)
    {
        //dp[i] is the maximum sum that you can get by the subarrays ending at the ith position
        cMax = nums[i];
        cMax = max (cMax, pMax + nums[i]);
        ans = max ( ans, cMax);
        pMax = cMax;
    }
    return ans;
}
int main()
{
    int n = 5;
    vector<int> input(n, 0);
    maxSubArray(input);
    return 0;
}
