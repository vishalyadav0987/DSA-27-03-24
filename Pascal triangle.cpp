class Solution
{
public:
    vector<int> generateRow(int row)
    {
        long long ans = 1;
        vector<int> rows;
        rows.push_back(1);
        for (int j = 1; j < row; j++)
        {
            ans = ans * (row - j);
            ans = ans / j;
            rows.push_back(ans);
        }
        return rows;
    }

public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans;
        for (int i = 1; i <= numRows; i++)
        {
            ans.push_back(generateRow(i));
        }
        return ans;
    }
};