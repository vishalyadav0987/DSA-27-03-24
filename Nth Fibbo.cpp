//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> Series(int n)
    {
        // Code here
        vector<int> res;
        int a = 0;
        int b = 1;
        int c = 0;
        for (int i = 0; i <= n; i++)
        {
            res.push_back(a);
            c = (a + b) % (1000000007);
            ;
            a = b;
            b = c;
        }
        return res;
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
        Solution obj;

        vector<int> ans = obj.Series(n);
        for (auto x : ans)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends