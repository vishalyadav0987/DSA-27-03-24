//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    int nthFibonacci(int n)
    {
        // code here
        int a = 1;
        int b = 1;
        int z = 0;
        for (int i = 3; i <= n; i++)
        {
            z = (a + b) % 1000000007;
            a = b;
            b = z;
        }
        return b;
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
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends