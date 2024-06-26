//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    long long int largestPrimeFactor(int N)
    {
        // code here
        long long int i = 2;
        while ((i * i) <= N)
            if (N % i == 0)
                N /= i;

            else
                i++;
        return N;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0;
}
// } Driver Code Ends