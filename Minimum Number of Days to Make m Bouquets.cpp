#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isPossible(vector<int> &bloomDay, int m, int k, int mid)
    {
        int cnt = 0;
        int boquetCnt = 0;
        for (int i = 0; i < bloomDay.size(); i++)
        {
            if (bloomDay[i] <= mid)
            {
                cnt++;
            }
            else
            {
                boquetCnt += (cnt / k);
                cnt = 0;
            }
            // if array at the end [7,7,7,13,13,(11,11,7)] when array ended
        }
        boquetCnt += (cnt / k);
        if (boquetCnt >= m)
            return true;
        else
            return false;
    }
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        // thre array is related to how many day in 1 flower is bloomed
        // make bquet taking acdjent follower
        // bloom 1st min arr days
        // bloom all flower to max array days
        // m ->kitne boquet
        // k -> flower need
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (isPossible(bloomDay, m, k, mid))
            {
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