class Solution
{
public:
    // cnt t
    int t[100001][3];
    int binarySearch(vector<vector<int>> &e, int endTime)
    {
        int low = 0;
        int high = e.size() - 1;
        int result = e.size();
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (e[mid][0] > endTime)
            {
                result = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return result;
    }
    int solve(vector<vector<int>> &e, int i, int cnt)
    {
        if (cnt == 2 || i >= e.size())
        {
            return 0;
        }

        if (t[i][cnt] != -1)
        {
            return t[i][cnt];
        }

        int nextValidIntervalIndex = binarySearch(e, e[i][1]);
        int take = e[i][2] + solve(e, nextValidIntervalIndex, cnt + 1);

        int not_take = solve(e, i + 1, cnt);

        return t[i][cnt] = max(take, not_take);
    }
    int maxTwoEvents(vector<vector<int>> &e)
    {
        int n = e.size();
        sort(e.begin(), e.end());
        memset(t, -1, sizeof(t));
        int count = 0;
        return solve(e, 0, count);
    }
};