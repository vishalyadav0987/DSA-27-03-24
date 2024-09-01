class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &arr)
    {
        // optimal
        // tc = nlogn + n
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++)
        {
            if (ans.empty() || arr[i][0] > ans.back()[1])
            {
                ans.push_back(arr[i]);
            }
            else
            {
                ans.back()[1] = max(arr[i][1], ans.back()[1]);
            }
        }
        return ans;
    }
};