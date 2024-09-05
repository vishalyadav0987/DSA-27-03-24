#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isPossible(vector<int> &piles, int h, long long mid)
    {
        int hr = 0;
        int prev = 0;
        for (int i = 0; i < piles.size(); i++)
        {
            // if (piles[i] < mid) {
            //     hr++;
            // } else {
            hr += (piles[i] + mid - 1) / mid; // if mid = 15
            // (20+15-1)/15 = 2
            // else {
            // hr+=(prev+piles[i])/mid;
            // prev=piles[i]/mid;
            if (hr > h)
                return false;
            // }
            // }
        }
        return true;
    }
    int minEatingSpeed(vector<int> &piles, int h)
    {
        long long low = 1;
        long long high = *max_element(piles.begin(), piles.end());
        long long ans = 0;
        while (low <= high)
        {
            long long mid = low + (high - low) / 2;
            if (isPossible(piles, h, mid))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return (int)ans;
    }
};