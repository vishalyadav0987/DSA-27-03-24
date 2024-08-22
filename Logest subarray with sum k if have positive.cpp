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
        int left = 0, right = 0;
        int sum = 0;
        int maxLength = 0;
        while (right < N)
        {
            // if sum badh jata hai toh usko lef se minus karege
            while (left <= right && sum > K)
            {
                sum -= arr[left];
                left++;
            }
            if (sum == K)
            {
                maxLength = max(maxLength, right - left + 1);
            }
            right++;
            if (right < N)
            {

                sum += arr[right];
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