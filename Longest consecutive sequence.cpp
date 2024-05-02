//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // arr[] : the input array
    // N : size of the array arr[]

    // Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        // Your code here
        int longestL = 0;
        unordered_set<int> s;
        for (int i = 0; i < N; i++)
        {
            s.insert(arr[i]);
        }
        for (int it : s)
        {
            if (s.find(it - 1) == s.end())
            { // yani ki end tak nh mila hai
                int cnt = 1;
                int x = it;
                while (s.find(x + 1) != s.end())
                { // iska ushe milega
                    cnt++;
                    x += 1;
                }
                longestL = max(cnt, longestL);
            }
        }
        return longestL;
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t, n, i, a[100001];
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        cout << obj.findLongestConseqSubseq(a, n) << endl;
    }

    return 0;
}
// } Driver Code Ends