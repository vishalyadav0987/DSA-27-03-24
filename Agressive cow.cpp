#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isPossible(vector<int> &arr, int m, int mid)
    {
        // mid == possible distance to situate cow
        int posCow = 1;
        int position = arr[0];
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] > position >= mid)
            {
                posCow++;
                if (posCow == m)
                {
                    return true;
                }
                position = arr[i];
            }
        }
        return false;
    }
    int maxDistance(vector<int> &arr, int m)
    {
        sort(arr.begin(), arr.end());
        int low = 0;
        int high = *max_element(arr.begin(), arr.end());
        int ans = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (isPossible(arr, m, mid))
            {
                // [1,2,3,4,5,6]
                // mid = 3
                // 1,2,3 is not posible
                // max distance chiye
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