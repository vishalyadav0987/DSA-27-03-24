#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void uniqueSets(vector<int> &nums, vector<int> output, int index, vector<vector<int>> &ans)
    {
        if (index >= nums.size())
        {
            if (find(ans.begin(), ans.end(), output) == ans.end())
            { // Compare vectors
                ans.push_back(output);
            }
            return;
        }

        // exclude
        uniqueSets(nums, output, index + 1, ans);
        int element = nums[index];
        // include karenge usko ouput me;
        output.push_back(element);
        uniqueSets(nums, output, index + 1, ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> ans;
        int index = 0;
        vector<int> output;
        sort(nums.begin(), nums.end());
        uniqueSets(nums, output, index, ans);
        return ans;
    }
};
