//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int getPairsCount(int arr[], int n, int k)
    {
        // code here
        map<int, int> mpp;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            int a = arr[i];
            int more = k - a;
            if (mpp.find(more) != mpp.end())
            {
                cnt += mpp[more];
            }
            mpp[a]++;
        }
        return cnt;
        // int i=0;
        // int j=n-1;
        // sort(arr,arr+n);
        // while(i <j){
        //     int a = arr[i] + arr[j];
        //     if(a == k){
        //         cnt++;
        //     }
        //     else if(a < k){
        //         i++;
        //     }
        //     else{
        //         j--;
        //     }
        // }
        // return cnt;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }

    return 0;
}
// } Driver Code Ends