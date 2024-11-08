class Solution
{
public:
    vector<int> getMaximumXor(vector<int> &nums, int maximumBit)
    {
        vector<int> ans;
        int currXOR = 0;
        for (int num : nums)
        {
            currXOR = currXOR ^ num;
        }
        int maxK = pow(2, maximumBit) - 1;
        int k = currXOR ^ maxK;
        ans.push_back(k);
        for (int i = nums.size() - 1; i > 0; i--)
        {
            currXOR = currXOR ^ nums[i];
            k = currXOR ^ maxK;
            ans.push_back(k);
        }

        return ans;
    }
};