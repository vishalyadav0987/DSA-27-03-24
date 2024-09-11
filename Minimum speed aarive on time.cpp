#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isPossible(vector<int> &dist, double hr, int mid)
    {
        double sum = 0;
        for (int i = 0; i < dist.size() - 1; i++)
        {
            sum += ceil((double)dist[i] / mid);
        }
        sum += ((double)dist[dist.size() - 1] / mid);

        if (sum <= hr)
            return true;
        else
            return false;
    }
    int minSpeedOnTime(vector<int> &dist, double hour)
    {
        int low = 1;
        // if time descrese speed increeses
        // [1,1,100000] hr=2.01;
        // 1+1+100000/0.01 = 10000002
        double maxSpeed = 0;
        int n = dist.size();
        for (int i = 0; i < n; i++)
        {
            maxSpeed += ((double)dist[i] / (hour - n + 1)); // (hour-n+1) 0.01
        }
        int high = ceil(min(maxSpeed, 10e7));
        ;
        int ans = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (isPossible(dist, hour, mid))
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