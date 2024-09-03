class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        // int mp=0; // max profile
        // int tp=0; // total profit
        // int sp=prices[0]; // stock purchase
        // for(int i=0;i<prices.size()-1;i++){
        //     // hold the profilt
        //     int hp=prices[i+1]-sp;
        //     mp=max(mp,hp);
        //     if(hp<mp){
        //         sp=prices[i+1];
        //         tp+=mp;
        //         mp=0;
        //     }
        // }
        // return tp;
        int tp = 0;         // total profit accumulated from all transactions
        int sp = prices[0]; // initial stock purchase price

        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] > sp)
            {
                // Calculate profit if selling at current price
                tp += prices[i] - sp;
                // Update the minimum price to current price for the next transaction
                sp = prices[i];
            }
            else
            {
                // Update the minimum price if current price is lower
                sp = prices[i];
            }
        }
        return tp;
    }
};