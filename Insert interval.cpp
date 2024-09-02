class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &arr, vector<int> &newInterval)
    {
        int n = arr.size();
        vector<vector<int>> ans;
        bool inserted = false;

        for (int i = 0; i < n; i++)
        {
            if (arr[i][0] >= newInterval[0] && !inserted)
            {
                arr.insert(arr.begin() + i, newInterval);
                inserted = true;
                break;
            }
        }

        if (!inserted)
        {
            arr.push_back(newInterval);
        }
        for (int i = 0; i < n + 1; i++)
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