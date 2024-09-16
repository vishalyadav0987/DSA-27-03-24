#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int row = 0;
        int col = matrix[0].size() - 1;
        while (row < matrix.size() && col >= 0)
        {
            int element = matrix[row][col];
            if (element == target)
            {
                return true;
            }
            else if (element < target)
            {
                row++;
            }
            else
            {
                col--;
            }
        }
        return false;
    }
};