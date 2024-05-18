//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int findPeakElement(vector<int> &arr)
    {
        // Code here.
        int low = 0;
        int high = arr.size() - 1;
        int ans = INT_MIN;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (((mid == 0) || (arr[mid] > arr[mid - 1])) && ((mid == arr.size() - 1) || (arr[mid] > arr[mid + 1])))
            {
                return arr[mid];
            }
            else if ((mid < arr.size() - 1) && arr[mid] < arr[mid + 1])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
            // if(low==mid && mid==high) return arr[mid];
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        int ans = ob.findPeakElement(a);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends