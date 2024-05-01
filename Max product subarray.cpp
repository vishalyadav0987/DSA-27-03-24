//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    // Function to find maximum product subarray
    long long maxProduct(vector<int> arr, int n)
    {
        // code here
        long long maxi = arr[0];
        long long l = 1;
        long long r = 1;
        for (int i = 0; i < n; i++)
        {
            l = l == 0 ? 1 : l;
            r = r == 0 ? 1 : r;
            l *= arr[i];
            r *= arr[n - 1 - i];
            maxi = max(maxi, max(l, r));
        }
        // for(int i=0;i<n;i++){
        //     pro*=arr[i];
        //    maxi=max(pro,maxi);
        //    if(pro==0){ pro = 1;}
        // }
        return maxi;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends