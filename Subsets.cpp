#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void sets(vector<int> &nums, int index, vector<int> output, vector<vector<int>> &ans)
    {
        if (index >= nums.size())
        {
            ans.push_back(output);
            return;
        }

        // exclude , means ouput me include nh karenge iska mtlb ek index++
        sets(nums, index + 1, output, ans);
        int element = nums[index];
        // include karenge usko ouput me;
        output.push_back(element);
        sets(nums, index + 1, output, ans);
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;
        sets(nums, index, output, ans);
        return ans;
    }
};