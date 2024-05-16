//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int findMin(int arr[], int n)
    {
        // complete the function here
        int low = 0;
        int high = n - 1;
        int ans = INT_MAX;
        if (arr[low] < arr[high])
            return arr[low];
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (arr[low] < arr[mid])
            {
                ans = min(ans, arr[low]);
                low = mid + 1;
            }
            else if (arr[mid] > arr[high])
            {
                low = mid + 1;
            }
            else
            {
                ans = min(ans, arr[mid]);
                high = mid - 1;
            }
        }
        return ans;
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
        cin >> n;
        int i, a[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.findMin(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends