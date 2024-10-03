#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int smallestSubarrayLength(vector<int> &nums, long long int k, int p)
    {
        long long sum = 0;
        int minLength = nums.size();
        map<int, int> mpp;
        mpp[0] = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            int currentMod = sum % p;
            int remModSum = (currentMod - k + p) % p;
            if (mpp.find(remModSum) != mpp.end())
            {
                int len = i - mpp[remModSum];
                minLength = min(minLength, len);
            }

            mpp[currentMod] = i;
        }
        return minLength == nums.size() ? -1 : minLength;
    }
    int minSubarray(vector<int> &nums, int p)
    {
        long long sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        long long k = sum % p;
        if (k == 0)
            return 0;
        return smallestSubarrayLength(nums, k, p);
    }
};