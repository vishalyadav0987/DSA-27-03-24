class Solution
{
public:
    void prefixArray(vector<int> &arr, vector<int> &prefix)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            if (i + 1 < arr.size() && arr[i] <= arr[i + 1])
            {
                prefix.push_back(arr[i]);
            }
            else
            {
                prefix.push_back(arr[i]);
                break;
            }
        }
    }

    void suffixArray(vector<int> &arr, vector<int> &suffix)
    {
        int n = arr.size();
        suffix.push_back(arr[n - 1]);

        for (int i = n - 2; i >= 0; i--)
        {
            if (arr[i] <= arr[i + 1])
            {
                suffix.push_back(arr[i]);
            }
            else
            {
                break;
            }
        }

        reverse(suffix.begin(), suffix.end());
    }

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

        cout << prefixEnd << " " << suffixStart;
        cout << endl;
        vector<int> prefix, suffix;
        prefixArray(arr, prefix);
        suffixArray(arr, suffix);
        cout << prefix.size() - 1 << " " << n - suffix.size();

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
