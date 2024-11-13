class Solution
{
public:
    long long countFairPairsLessThan(vector<int> &nums, int ts)
    {
        int i = 0;
        int j = nums.size() - 1;
        long long cnt = 0;
        while (i < j)
        {
            long long pairSum = nums[i] + nums[j];
            if (pairSum <= ts)
            {
                cnt += (j - i);
                i++;
            }
            else
            {
                j--;
            }
        }
        return cnt;
    }
    long long countFairPairs(vector<int> &nums, int lower, int upper)
    {
        sort(nums.begin(), nums.end());
        long long lowerCnt = countFairPairsLessThan(nums, lower - 1);
        long long upperCnt = countFairPairsLessThan(nums, upper);
        return upperCnt - lowerCnt;
    }
};