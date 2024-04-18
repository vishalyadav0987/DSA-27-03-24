//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    vector<int> findMissing(int a[], int b[], int n, int m)
    {
        // Your code goes here
        vector<int> ans;
        unordered_set<int> used;
        // int val=0;
        // for(int i = 0; i<n; i++){
        //     for(int j = 0; j < m ; j++){
        //         if(a[i] == b[j]){
        //             break;
        //         }
        //         else if(j == m-1){
        //             ans.push_back(a[i]);

        //         }
        //     }
        // }

        for (int i = 0; i < m; i++)
        {
            used.insert(b[i]);
        }
        for (int i = 0; i < n; i++)
        {
            // agar nh hai toh
            if (used.find(a[i]) == used.end())
            {
                ans.push_back(a[i]);
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
        int m;
        cin >> m;
        int a[n];
        int b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];
        vector<int> ans;

        Solution ob;
        ans = ob.findMissing(a, b, n, m);
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";

        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends