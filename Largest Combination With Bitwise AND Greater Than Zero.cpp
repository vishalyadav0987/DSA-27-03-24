class Solution
{
public:
    int largestCombination(vector<int> &candidates)
    {
        int maxCountLen = 0;
        for (int i = 0; i < 32; i++)
        {                // o(24) // aur konsi place pe aarahai isliye
                         // 32 tak loop ko chala rahe hai  1 <= candidates[i] <= 107
            int cnt = 0; // no of 1s kitne number me aa raha hai
            for (int num : candidates)
            { // o(n)
                if ((num & (1 << i)))
                { // o(1)
                    cnt++;
                }
            }
            maxCountLen = max(maxCountLen, cnt);
        }
        return maxCountLen;
    }
};