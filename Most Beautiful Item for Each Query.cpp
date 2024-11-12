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

        vector<pair<int, int>> sh(mpp.begin(), mpp.end()); // items hai

        // MaxPrifix array
        vector<int> pma(sh.size());

        pma[0] = sh[0].second;
        for (int i = 1; i < sh.size(); i++)
        {
            pma[i] = max(pma[i - 1], sh[i].second);
        }

        for (auto num : pma)
        {
            cout << num << " ";
        }

        for (auto q : queries)
        {
            // use binary search
            // Binary search to find the first item where price > q
            auto it = upper_bound(sh.begin(), sh.end(), make_pair(q, INT_MAX));

            // Check if there is no item with price <= q
            if (it == sh.begin())
            {
                ans.push_back(0); // No items with price <= q
            }
            else
            {
                // humne q jo woh price hai
                // humne q se bada price dundha in item pair array
                // using upper bound
                // so humne 1 index piche jana hoga
                int index = distance(sh.begin(), it) - 1;
                ans.push_back(pma[index]);
            }
        }

        return ans;
    }
};