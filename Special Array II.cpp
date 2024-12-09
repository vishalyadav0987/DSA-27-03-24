class Solution
{
public:
    bool isArraySpecial(vector<int> &nums, int s, int e)
    {
        if (nums.size() == 1)
            return true;
        for (int i = s + 1; i <= e; i++)
        {
            if (nums[i - 1] % 2 == 0 && nums[i] % 2 == 1)
            {
                continue;
            }
            else if (nums[i - 1] % 2 == 1 && nums[i] % 2 == 0)
            {
                continue;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
    vector<bool> isArraySpecial(vector<int> &nums,
                                vector<vector<int>> &queries)
    {
        vector<int> parity(nums.size(), 0);
        vector<bool> ans;
        for (int i = 1; i < nums.size(); i++)
        {
            parity[i] = parity[i - 1];
            if ((nums[i - 1] % 2 == 0 && nums[i] % 2 == 1) ||
                (nums[i - 1] % 2 == 1 && nums[i] % 2 == 0))
            {
                parity[i]++;
            }
        }

        for (auto q : queries)
        {
            int f = q[0];
            int s = q[1];

            if (s == f)
            {
                ans.push_back(true);
            }

            else
            {
                int validPairs = parity[s] - parity[f];
                ans.push_back(validPairs == (s - f));
            }
        }

        return ans;
    }
};