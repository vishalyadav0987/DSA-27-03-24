class Solution
{
public:
    bool isSortedAndConsecutive(vector<int> &arr, int start, int end)
    {
        int n = arr.size();

        if (n <= 1)
            return true;

        for (int i = start; i < end - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                return false;
            }

            if (arr[i + 1] - arr[i] != 1)
            {
                return false;
            }
        }

        return true;
    }
    vector<int> resultsArray(vector<int> &nums, int k)
    {
        vector<int> ans;
        int start = 0;
        int end = k;

        if (isSortedAndConsecutive(nums, start, end))
        {
            ans.push_back(nums[end - 1]);
        }
        else
        {
            ans.push_back(-1);
        }

        for (int i = k; i < nums.size(); i++)
        {
            start++;
            end = i + 1;
            if (isSortedAndConsecutive(nums, start, end))
            {
                ans.push_back(nums[end - 1]);
            }
            else
            {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};