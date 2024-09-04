class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int low = 0;
        int high = nums.size() - 1;
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] < nums[mid + 1])
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
                // why mid+1;
                // becaus i i have peck ele on mid
            }
        }
        return low;
    }
};