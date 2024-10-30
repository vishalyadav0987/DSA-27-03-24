class Solution
{
public:
    int minimumMountainRemovals(vector<int> &nums)
    {
        int n = nums.size();

        // 1. find LIS
        // 2. find LDS

        vector<int> LIS(n, 1);
        vector<int> LDS(n, 1);

        // storing of longest incresing subsequent till i
        // initialize with because at staring for all
        // value LIS = 1;
        // LIS[i] ==LIS ending at i-th index

        // Compute LIS from each index
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    LIS[i] = max(LIS[i], LIS[j] + 1);

                    // why +1 because nums[j] < nums[i]
                    // hum check karnge LIS me LIS[i] ==LIS ending at i-th index
                    // we know nums[j]<nums[i] toh hum ek or value add karke
                    // squence ko bda sakte hai
                }
            }
        }

        // Compute LDS from each index
        for (int i = n - 1; i > 0; i--)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[j] < nums[i])
                {
                    LDS[i] = max(LDS[i], LDS[j] + 1);

                    // why +1 because nums[j] < nums[i]
                    // hum check karnge LIS me LIS[i] ==LIS ending at i-th index
                    // we know nums[j]<nums[i] toh hum ek or value add karke
                    // squence ko bda sakte hai
                }
            }
        }

        int cnt = n;

        for (int i = 0; i < n; i++)
        {
            if (LIS[i] > 1 && LDS[i] > 1)
            {
                // left - right
                // ((i+1)-LIS[i]) + ((n-i) - LDS[i]); === ⤵️
                cnt = min(cnt, n - LIS[i] - LDS[i] + 1); // this
            }
        }

        return cnt;
    }
};