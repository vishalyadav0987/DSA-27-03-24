class Solution
{
public:
    int maxEqualRowsAfterFlips(vector<vector<int>> &matrix)
    {
        // step 1 : store all same and inverter colum in map
        // for do that

        // check ever 1st no of each row compare with all the ro values

        // example

        // 1 0 0 0 1 = a  '1' = S -> "SBBBS"
        // 0 1 1 1 0 = b. '0' = S -> "SBBBS"
        // 1 0 0 0 1 = c  '1' = S -> "SBBBS"
        // 1 0 1 0 1 = d  '1' = S -> "SBSBS"

        unordered_map<string, int> mpp;

        overall complexity = O(n * m);
        space complexity = O(n);

        for (auto currRow : matrix)
        {
            // compare nature of 1st row value to all its row val
            string rowValueNature = "";

            int firstRowVal = currRow[0];
            for (int j = 0; j < matrix[0].size(); j++)
            {
                rowValueNature += (firstRowVal == currRow[j]) ? "S" : "B";
            }

            mpp[rowValueNature]++;
        }

        // iterate map for maxcount
        int maxCnt = 0;
        for (auto [stringVal, count] : mpp)
        {
            maxCnt = max(maxCnt, count);
        }

        return maxCnt;
    }
};