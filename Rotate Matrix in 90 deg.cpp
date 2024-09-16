#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int rowLen = matrix.size();
        int colLen = matrix[0].size();
        for (int i = 0; i < rowLen; i++)
        {
            for (int j = i + 1; j < colLen; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (int i = 0; i < rowLen; i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};