class Solution
{
public:
    vector<int> findTwoElement(vector<int> arr, int n)
    {
        vector<int> result(2);

        long long sum = 0, sumOfSquares = 0;
        for (int i = 0; i < n; ++i)
        {
            sum += arr[i];
            sumOfSquares += (long long)arr[i] * arr[i];
        }

        long long expectedSum = (long long)n * (n + 1) / 2;
        long long expectedSumOfSquares = (long long)n * (n + 1) * (2 * n + 1) / 6;

        long long diffSum = expectedSum - sum;
        long long diffSumOfSquares = expectedSumOfSquares - sumOfSquares;

        int missing = (int)((diffSumOfSquares - diffSum * diffSum) / (2 * diffSum));
        int duplicate = (int)(missing + diffSum);
        result[0] = missing;
        result[1] = duplicate;
        return result;
    }
};