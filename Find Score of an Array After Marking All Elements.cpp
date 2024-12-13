class Solution
{
public:
    long long findScore(vector<int> &nums)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minH;
        // 1. value;
        // 2. idx;
        long long ans = 0LL;
        for (int i = 0; i < nums.size(); i++)
        {
            minH.push({nums[i], i});
        }

        int j = 0;
        while (j < nums.size())
        {
            pair<int, int> vi = minH.top();
            int value = vi.first;
            int idx = vi.second;
            minH.pop();

            if (nums[idx] != -1)
            {
                ans += value;
                if (idx - 1 >= 0)
                {
                    nums[idx - 1] = -1;
                }
                if (idx + 1 < nums.size())
                {
                    nums[idx + 1] = -1;
                }
            }
            j++;
        }
        return ans;
    }
};