#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isPossible(vector<int> &nums, int n, int k, long long mid)
    {
        int studentCount = 1;
        long long pageSum = 0;
        for (int i = 0; i < n; i++)
        {
            if (pageSum + nums[i] <= mid)
            {
                pageSum += nums[i];
            }
            else
            {
                studentCount++;
                if (nums[i] > mid || studentCount > k)
                {
                    return false;
                }
                pageSum = 0;
                pageSum += nums[i];
            }
        }
        return true;
    }

public:
    int splitArray(vector<int> &nums, int k)
    {
        long long sum = 0;
        int ans = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        long long low = 0;
        long long high = sum;
        while (low <= high)
        {
            long long mid = low + (high - low) / 2;
            if (isPossible(nums, nums.size(), k, mid))
            {
                // if the range is
                // 1 to 100 if mid 50 if it posible so is ke age wale toh possible
                // honge hi but hume minimal chiye so,
                // mid is our possible answer here
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};