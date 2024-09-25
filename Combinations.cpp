#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void solve(int n, int k, int index, vector<int> output, vector<vector<int>> &ans)
    {
        if (output.size() == k)
        {
            ans.push_back(output);
            return;
        }

        for (int i = index; i <= n; i++)
        {
            output.push_back(i);
            solve(n, k, i + 1, output, ans);
            output.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k)
    {
        int index = 1;
        vector<int> output;
        vector<vector<int>> ans;
        solve(n, k, index, output, ans);
        return ans;
    }
};