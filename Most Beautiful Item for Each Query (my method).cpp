class Solution
{
public:
    vector<int> maximumBeauty(vector<vector<int>> &items,
                              vector<int> &queries)
    {
        map<int, int> mpp;
        vector<int> ans;
        for (int i = 0; i < items.size(); i++)
        {
            int price = items[i][0];
            int beauty = items[i][1];

            if (!mpp.empty())
            {
                // Check if the current value is greater than the existing
                // maximum
                if (beauty > mpp[price])
                {
                    mpp[price] = beauty; // Replace with the new max value
                }
            }
            else
            {
                mpp[price] = beauty;
            }
        }

        for (int i = 0; i < queries.size(); i++)
        {
            int maxBeauty = 0;
            for (auto num : mpp)
            {
                if (num.first <= queries[i])
                {
                    maxBeauty = max(maxBeauty, num.second);
                }
            }
            ans.push_back(maxBeauty);
        }

        return ans;
    }
};