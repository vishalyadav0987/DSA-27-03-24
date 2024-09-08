#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isPossible(vector<int> &nums, int th, int mid)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int div = ceil((double)nums[i] / (double)mid);
            sum += div;
        }
        cout << sum;
        if (sum > th)
        {
            return false;
        }
        return true;
    }
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        // [6,5,10,9] th=3 example do that dry run
        // th can grater than th=10 so we want take = low = 1;
        // high = max of array when it th >= length of array;
        if (threshold < nums.size())
            return -1;
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (isPossible(nums, threshold, mid))
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