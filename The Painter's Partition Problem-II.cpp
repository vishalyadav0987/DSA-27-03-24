//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    bool isPossible(int arr[], long long mid, int n, int k)
    {
        int daysToPrint = 0;
        int painterCount = 1;
        for (int i = 0; i < n; i++)
        {
            if (daysToPrint + arr[i] <= mid)
            {
                daysToPrint += arr[i];
            }
            else
            {
                painterCount++;
                if (painterCount > k || arr[i] > mid)
                    return false;
                daysToPrint = 0;
                daysToPrint += arr[i];
            }
        }
        return true;
    }
    long long minTime(int arr[], int n, int k)
    {
        // code here
        // return minimum time
        long long low = 0;
        long long ans = -1;
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
        }
        long long high = sum;
        while (low <= high)
        {
            long long mid = low + (high - low) / 2;
            if (isPossible(arr, mid, n, k))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int k, n;
        cin >> k >> n;

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        cout << obj.minTime(arr, n, k) << endl;
    }
    return 0;
}
// } Driver Code Ends