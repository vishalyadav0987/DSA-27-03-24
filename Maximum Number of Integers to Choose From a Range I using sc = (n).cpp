class Solution
{
public:
    int maxCount(vector<int> &banned, int n, int maxSum)
    {
        unordered_set<int> st(banned.begin(), banned.end());
        int sum = 0;
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (st.find(i) == st.end())
            {
                sum += i;
                if (sum <= maxSum)
                {
                    ans++;
                }
                else
                {
                    break;
                }
            }
        }
        return ans;
    }
};