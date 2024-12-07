class Solution
{
public:
    bool isPossible(vector<int> &nums, int maxOperations, int mid)
    {
        int totalOps = 0;
        for (auto num : nums)
        {
            // if odd num
            int ops = num / mid;
            // if even 1 op subtract
            if (num % mid == 0)
            {
                ops -= 1;
            }
            totalOps += ops;
        }

        return totalOps <= maxOperations;
    }
    int minimumSize(vector<int> &nums, int maxOperations)
    {
        // minmize tne max no of ball of maximum at end in array

        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        // item possible case me thod sakte hai

        int result = high; // maximize this

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (isPossible(nums, maxOperations, mid))
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
};