class Solution
{
public:
    int longestSquareStreak(vector<int> &nums)
    {
        int range = *max_element(nums.begin(), nums.end());
        unordered_set<int> mp;
        for (auto num : nums)
        {
            mp.insert(num);
        }

        int maxLength = -1;
        for (auto num : nums)
        {
            int sqL = 0;
            long long current = num;
            while (mp.find(current) != mp.end())
            {
                sqL++;
                current = current * current;
                if (current > 100000)
                    break;
            }
            if (sqL > 1)
            {
                maxLength = max(sqL, maxLength);
            }
        }
        return maxLength;
    }
};