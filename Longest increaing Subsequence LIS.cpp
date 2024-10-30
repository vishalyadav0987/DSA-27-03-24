class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();

        // storing of longest incresing subsequent till i
        vector<int> dp(n, 1); // initialize with because at staring for all
        // value LIS = 1;
        // dp[i] ==LIS ending at i-th index

        int maxLIS = 1;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    dp[i] = max(dp[i], dp[j] + 1);

                    // why +1 because nums[j] < nums[i]
                    // hum check karnge dp me dp[i] ==LIS ending at i-th index
                    // we know nums[j]<nums[i] toh hum ek or value add karke
                    // squence ko bda sakte hai
                    maxLIS = max(maxLIS, dp[i]);
                }
            }
        }

        return maxLIS;
    }
};