class Solution
{
public:
    long long maxMatrixSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        long long sum = 0;
        int negCnt = 0, minAbsVal = 1e5 + 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                sum += abs(matrix[i][j]);
                if (matrix[i][j] < 0)
                    negCnt++;
                minAbsVal = min(minAbsVal, abs(matrix[i][j]));
            }
        }
        if (negCnt & 1)
            sum -= 2 * minAbsVal;
        return sum;
    }
};