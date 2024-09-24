#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void solve(vector<int> nums, int index, vector<vector<int>> &ans)
    {
        if (index == nums.size())
        {
            ans.push_back(nums);
            return;
        }

        for (int j = index; j < nums.size(); j++)
        {
            if (j != index && nums[j] == nums[index])
                continue;
            swap(nums[index], nums[j]);
            solve(nums, index + 1, ans);
            // swap(nums[index], nums[j]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int index = 0;
        solve(nums, index, ans);
        return ans;
    }
};