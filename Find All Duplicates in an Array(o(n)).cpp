#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        int i = 0;
        vector<int> ans;
        while (i <= nums.size() - 1)
        {
            if (nums[i] != i + 1 && nums[i] <= nums.size() &&
                nums[i] != nums[nums[i] - 1])
            {
                swap(nums[i], nums[nums[i] - 1]);
            }
            else if (nums[i] <= nums.size() && (nums[i] - 1) != i && nums[i] == nums[nums[i] - 1])
            {
                nums[nums[i] - 1] = -1;
                ans.push_back(nums[i]);
                i++;
            }
            else
            {
                i++;
            }
        }
        return ans;
    }
};