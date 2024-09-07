//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    bool isPossible(int N, vector<int> &arr, int L, int mid)
    {
        int donut = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            int t = 0;
            int k = 0;
            while (k <= mid)
            {
                t = t + 1;
                k += (t * arr[i]);
                if (k <= mid)
                {
                    donut++;
                }
                if (donut >= N)
                    return true; // Return true if the required number of donuts is reached
            }
        }
        return false;
    }
    int findMinTime(int N, vector<int> &A, int L)
    {
        // write your code here
        int low = 1;
        // int high=N*(*max_element(A.begin(),A.end()));
        int high = N * (N + 1) / 2 * (*min_element(A.begin(), A.end()));
        int ans = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (isPossible(N, A, L, mid))
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
        int l;
        cin >> l;
        vector<int> arr(l);
        for (int i = 0; i < l; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        int ans = ob.findMinTime(n, arr, l);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends