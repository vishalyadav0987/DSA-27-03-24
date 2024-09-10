#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isPossible(vector<int> &candies, long long k, long long mid)
    {
        long long sum = 0;
        for (long long i = 0; i < candies.size(); i++)
        {
            sum += candies[i] / mid;
            if (sum >= k)
                return true;
        }
        return false;
    }
    int maximumCandies(vector<int> &candies, long long k)
    {
        long long low = 1;
        long long high = *max_element(candies.begin(), candies.end());
        long long ans = 0;
        while (low <= high)
        {
            long long mid = low + (high - low) / 2;
            if (isPossible(candies, k, mid))
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return ans;
    }
};