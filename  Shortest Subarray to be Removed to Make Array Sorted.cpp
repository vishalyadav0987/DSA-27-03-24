class Solution
{
public:
    int findLengthOfShortestSubarray(vector<int> &arr)
    {
        int n = arr.size();

        int prefixEnd = 0;
        while (prefixEnd + 1 < n && arr[prefixEnd] <= arr[prefixEnd + 1])
        {
            prefixEnd++;
        }
        int suffixStart = n - 1;
        while (suffixStart - 1 >= 0 &&
               arr[suffixStart] >= arr[suffixStart - 1])
        {
            suffixStart--;
        }

        if (prefixEnd == n - 1)
        {
            return 0;
        }

        int result = min(n - prefixEnd - 1,
                         suffixStart); // Case 1: Remove prefix or suffix

        // check it possible to make suffix anf prefix merge
        int i = 0;
        int j = suffixStart;
        while (i <= prefixEnd && j < n)
        {
            if (arr[i] <= arr[j])
            {
                result = min(result, j - i - 1);
                i++;
            }
            else
            {
                j++;
            }
        }

        return result;
    }
};
