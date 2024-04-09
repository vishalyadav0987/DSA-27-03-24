//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> find(int arr[], int n, int x)
    {
        // code here
        int s = -1;
        int e = -1;
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == x)
            {
                s = i;
                break;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == x)
            {
                e = i;
            }
        }
        ans.push_back(s);
        ans.push_back(e);
        if (s == -1 && e == -1)
        {
            ans[0] = -1;
            ans[1] = -1;
            return ans;
        };
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
        int n, x;
        cin >> n >> x;
        int arr[n], i;
        for (i = 0; i < n; i++)
            cin >> arr[i];
        vector<int> ans;
        Solution ob;
        ans = ob.find(arr, n, x);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}

// } Driver Code Ends