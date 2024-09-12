#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isPossible(vector<int> &weights, int days, int capicityOfPerDay)
    {
        int calW = 0;
        int cntDays = 1;
        for (int i = 0; i < weights.size(); i++)
        {
            if (calW + weights[i] > capicityOfPerDay)
            {
                cntDays++;
                calW = 0;
            }
            calW += weights[i];
            if (cntDays > days)
                return false;
        }
        return true;
    }
    int shipWithinDays(vector<int> &weights, int days)
    {
        int low = *max_element(weights.begin(), weights.end());
        ;
        int totalWeight = 0;
        int ans = -1;
        for (int i = 0; i < weights.size(); i++)
        {
            totalWeight += weights[i];
        }
        int high = totalWeight;
        while (low <= high)
        {
            int capicityOfPerDay = low + (high - low) / 2;
            if (isPossible(weights, days, capicityOfPerDay))
            {
                ans = capicityOfPerDay;
                high = capicityOfPerDay - 1;
            }
            else
            {
                low = capicityOfPerDay + 1;
            }
        }
        return ans;
    }
};