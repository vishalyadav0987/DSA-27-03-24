//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int transitionPoint(int arr[], int n)
    {
        // code here
        int low = 0;
        int high = n - 1;
        int ans = -1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (arr[mid] == 1 && arr[mid - 1] == 0)
            {
                ans = mid;
                return ans;
            }
            else
            {
                if (arr[mid - 1] != 0)
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int transitionPoint(int arr[], int n);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n], i;
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.transitionPoint(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends