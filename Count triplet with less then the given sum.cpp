//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    long long countTriplets(long long arr[], int n, long long target)
    {
        // Your code goes here
        long long cnt = 0;
        sort(arr, arr + n);
        for (int i = 0; i < n; i++)
        {
            if (i > 0 && arr[i] == arr[i - 1])
                continue;
            int j = i + 1;
            int k = n - 1;
            while (j < k)
            {
                long long sum = arr[i] + arr[j] + arr[k];
                if (sum < target)
                {
                    // cnt++;
                    // if sum is valid j to k so; cnt will
                    cnt += (k - j);
                    j++;
                }
                else if (sum >= target)
                {
                    k--;
                }
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        long long sum;
        cin >> n >> sum;
        long long arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.countTriplets(arr, n, sum);

        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends