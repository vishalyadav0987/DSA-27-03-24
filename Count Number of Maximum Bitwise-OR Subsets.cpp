class Solution
{
public:
    void sets(vector<int> &nums, vector<int> output, int index, int &ans,
              int &maxi)
    {
        // base case

        if (index >= nums.size())
        {
            int val = 0;
            for (int i = 0; i < output.size(); i++)
            {
                val |= output[i];
            }
            if (val > maxi)
            {
                maxi = val;
                ans = 1;
            }
            else if (val == maxi)
            {
                ans++; // increment count for this maximum value
            }
            return;
        }

        // exclude call
        sets(nums, output, index + 1, ans, maxi);
        int element = nums[index];

        output.push_back(element);
        sets(nums, output, index + 1, ans, maxi);

        output.pop_back();
    }
    int countMaxOrSubsets(vector<int> &nums)
    {
        int ans = 0;
        int index = 0;
        int maxi = INT_MIN;
        vector<int> output;
        sets(nums, output, index, ans, maxi);
        return ans;
    }
};