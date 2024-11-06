class Solution
{
public:
    bool canSortArray(vector<int> &nums)
    {

        bool swapped;
        do
        {
            swapped = false;
            for (size_t i = 1; i < nums.size(); ++i)
            {
                int cnt1 = __builtin_popcount(nums[i - 1]);
                int cnt2 = __builtin_popcount(nums[i]);
                if ((cnt1 == cnt2) && (nums[i - 1] > nums[i]))
                {
                    swap(nums[i - 1], nums[i]);
                    swapped = true;
                }
            }
        } while (swapped);

        for (int i = 0; i < nums.size(); i++)
        {
            int cnt1 = __builtin_popcount(nums[i]);
            cout << nums[i] << " ";
        }
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] > nums[i + 1])
            {
                return false;
            }
        }

        return true;
    }
};