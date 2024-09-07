#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isPossible(int n, vector<int> &quantities, int mid)
    {
        for (int i = 0; i < quantities.size(); i++)
        {
            int wayToDivide = (quantities[i] + mid - 1) / mid;
            if (wayToDivide <= n)
            {
                n -= wayToDivide;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
    int minimizedMaximum(int n, vector<int> &quantities)
    {
        int low = 1;
        int high = *max_element(quantities.begin(), quantities.end());
        int ans = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (isPossible(n, quantities, mid))
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