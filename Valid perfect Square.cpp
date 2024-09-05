class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        if (num == 1)
            return true;
        int low = 1;
        int high = num;
        while (low <= high)
        {
            long long mid = low + (high - low) / 2;
            long long sq = mid * mid;
            if (sq > (long)num)
            {
                high = mid - 1;
            }
            else if (sq == (long)num)
            {
                return true;
            }
            else
            {
                low = mid + 1;
            }
        }
        return false;
    }
};