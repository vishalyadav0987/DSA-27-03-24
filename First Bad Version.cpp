// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(int n)
    {
        int low = 1;
        int high = n;
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if (isBadVersion(mid))
            {
                high = mid;
                // When isBadVersion(mid) returns true, it means that
                // version mid is a bad version. However, since we want to find the
                // first bad version, we cannot rule out mid itself as being the first bad one.
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};