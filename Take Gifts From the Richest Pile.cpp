class Solution
{
public:
    long long pickGifts(vector<int> &gifts, int k)
    {
        long long sum = accumulate(gifts.begin(), gifts.end(), 0LL);
        cout << sum << endl;
        priority_queue<int> maxH(gifts.begin(), gifts.end());
        for (int i = 0; i < k; i++)
        {
            int val = maxH.top();
            maxH.pop();
            sum -= val;
            long long sqVal = floor(sqrt(val));
            maxH.push(sqVal);
            sum += sqVal;
        }
        return sum;
    }
};