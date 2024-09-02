class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int maxPro = 0;
        int stockPur = prices[0];
        for (int i = 0; i < prices.size() - 1; i++)
        {
            maxPro = max(maxPro, (prices[i + 1] - stockPur));
            stockPur = min(stockPur, prices[i + 1]);
        }
        return maxPro;
    }
};