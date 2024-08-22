//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int lenOfLongSubarr(int arr[], int N, int K)
    {
        // Complete the function
        map<int, int> mpp;
        int maxLength = 0;
        int sum = 0;
        for (int i = 0; i < N; i++)
        {
            sum += arr[i];
            if (sum == K)
            {
                maxLength = max(maxLength, i + 1);
            }
            int rem = sum - K;
            if (mpp.find(rem) != mpp.end())
            {
                int len = i - mpp[rem];
                maxLength = max(maxLength, len);
            }
            // aur usko mapp me dalo do
            // it is for if array have negative value
            // toh hume map me check karna padega ush pair ko
            // agar hoga toh nh daalenge
            if (mpp.find(sum) == mpp.end())
            {
                mpp[sum] = i;
            }
        }
        return maxLength;
    }
};

//{ Driver Code Starts.

int main()
{
    // code

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n];

        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        cout << ob.lenOfLongSubarr(a, n, k) << endl;
    }

    return 0;
}
// } Driver Code Ends