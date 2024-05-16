//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int findExtra(int a[], int b[], int n)
    {
        // add code here.
        int low = 0;
        int high = n - 1;
        int ans = -1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (a[mid] == b[mid])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
            if (low == mid && mid == high)
            {
                ans = high;
                return ans;
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
        int n;
        cin >> n;
        int a[n], b[n - 1];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n - 1; i++)
        {
            cin >> b[i];
        }
        Solution obj;
        cout << obj.findExtra(a, b, n) << endl;
    }
}
// } Driver Code Ends