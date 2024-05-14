//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    int lowerBound(int arr[], int n, int x)
    {
        int low = 0;
        int high = n - 1;
        int ans = n;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (arr[mid] >= x)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }

public:
    int findClosest(int n, int k, int arr[])
    {
        // Complete the function
        int ans = lowerBound(arr, n, k);
        //  return ans;
        // if(ans==n || arr[ans] != k) return -1;
        // int ans2 = upperBound(arr,n,k);
        int diff = k - arr[ans - 1];
        int diff2 = arr[ans] - k;
        if (diff == diff2 || diff > diff2)
            return arr[ans];
        else
            return arr[ans - 1];
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        cout << ob.findClosest(n, k, arr) << endl;
    }
}

// } Driver Code Ends