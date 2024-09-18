#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool comapreMatrix(vector<vector<int>> &a, vector<vector<int>> &b)
    {
        int row = a.size();
        int col = a[0].size();
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                if (a[i][j] != b[i][j])
                    return 0;
        return 1;
    }
    bool rotateMatrix(vector<vector<int>> &mat, vector<vector<int>> &target)
    {
        int row = mat.size();
        int col = mat[0].size();
        for (int i = 0; i < row; i++)
        {
            for (int j = i + 1; j < col; j++)
            {
                swap(mat[i][j], mat[j][i]);
            }
        }

        for (int i = 0; i < row; i++)
        {
            reverse(mat[i].begin(), mat[i].end());
        }
        return comapreMatrix(mat, target);
        // return mat==target;
    }
    bool findRotation(vector<vector<int>> &mat, vector<vector<int>> &target)
    {
        int flag = 0;
        for (int i = 0; i < 4; i++)
        {
            if (rotateMatrix(mat, target))
            {
                flag = 1;
                break;
            }
        }
        return flag ? true : false;
    }
};