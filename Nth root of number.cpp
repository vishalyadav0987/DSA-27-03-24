//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int mulFunc(int mid, int n, int m)
    {
        long long int ans = 1;
        for (int i = 1; i <= n; i++)
        {
            ans = ans * mid;
            if (ans > m)
                return 2;
        }
        if (ans == m)
            return 1;
        else
            return 0;
    }

public:
    int NthRoot(int n, int m)
    {
        // Code here.
        long long int low = 1;
        long long int high = m;
        while (low <= high)
        {
            long long int mid = (low + high) / 2;
            int ans = mulFunc(mid, n, m);
            if (ans == 1)
            {
                return mid;
            }
            else if (ans == 0)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        Solution ob;
        int ans = ob.NthRoot(n, m);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends