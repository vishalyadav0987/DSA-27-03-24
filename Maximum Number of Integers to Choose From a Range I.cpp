class Solution
{
public:
    int maxCount(vector<int> &banned, int n, int maxSum)
    {
        unordered_set<int> st(banned.begin(), banned.end());
        vector<int> ub;
        for (int i = 1; i <= n; i++)
        {
            if (st.find(i) == st.end())
            {
                ub.push_back(i);
            }
        }

        int sum = 0;
        int ans = 0;
        for (int z = 0; z < ub.size(); z++)
        {
            sum += ub[z];
            if (sum <= maxSum)
            {
                ans++;
            }
        }

        return ans;
    }
};