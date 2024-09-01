class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &arr)
    {
        int n = arr.size();
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n; i++)
        {
            int start = arr[i][0];
            int end = arr[i][1];
            if (!ans.empty() && ans.back()[1] >= end)
            {
                continue;
            }
            for (int j = i + 1; j < n; j++)
            {
                if (arr[j][0] <= end)
                {
                    end = max(arr[j][1], end);
                }
                else
                {
                    break;
                }
            }
            ans.push_back({start, end});
        }
        return ans;
    }
};

// brute