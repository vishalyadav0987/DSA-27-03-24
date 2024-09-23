#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void solve(vector<int> nums, int index, vector<vector<int>> &ans)
    {
        if (index >= nums.size())
        {
            ans.push_back(nums);
        }

        for (int i = index; i < nums.size(); i++)
        {
            swap(nums[index], nums[i]);
            solve(nums, index + 1, ans);
            // backtracking back jo array reverse hui usse same state me lane ke agar
            // hum nh karenge toh swap array again swap hoke inconsistant pair ban
            // jayega
            swap(nums[index], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        int index = 0;
        vector<vector<int>> ans;
        solve(nums, index, ans);
        return ans;
    }
};