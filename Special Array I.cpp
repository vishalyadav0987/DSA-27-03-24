class Solution
{
public:
    bool isArraySpecial(vector<int> &nums)
    {
        if (nums.size() == 1)
            return true;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i - 1] % 2 == 0 && nums[i] % 2 == 1)
            {
                continue;
            }
            else if (nums[i - 1] % 2 == 1 && nums[i] % 2 == 0)
            {
                continue;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};