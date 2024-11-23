class Solution
{
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>> &box)
    {
        int row = box.size();
        int col = box[0].size();
        vector<vector<char>> ans(col, vector<char>(row));

        // Alternative code of roatate 90deg 2d array
        for (int i = 0; i < col; i++)
        {
            for (int j = 0; j < row; j++)
            {
                ans[i][j] = box[row - 1 - j][i];
            }
        }

        box.clear();

        for (int i = 0; i < row; i++)
        {
            vector<char> v;
            for (int j = 0; j < col; j++)
            {
                v.push_back(ans[j][i]);
            }

            int k = 0;
            int l = 0;
            while (k < col)
            {
                if (v[k] == '*')
                {
                    k++;
                    l = k;
                }
                else if (v[k] != '.')
                {
                    k++;
                }
                else
                {
                    swap(v[k], v[l]);
                    l++;
                    k++;
                }
            }
            box.push_back(v);
        }

        reverse(box.begin(), box.end());

        // Alternative code of roatate 90deg 2d array
        for (int i = 0; i < col; i++)
        {
            for (int j = 0; j < row; j++)
            {
                ans[i][j] = box[row - 1 - j][i];
            }
        }

        return ans;
    }
};