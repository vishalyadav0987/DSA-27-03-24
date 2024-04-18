//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> countElements(vector<int> &a, vector<int> &b, int n, vector<int> &query,
                              int q) {
        // Your code goes here;
        vector<int>ans;
        // 1100 cases pass
        // for(int i=0; i<q; i++){
        // int cnt = 0;
        //     int cm = query[i];
        //     for(int j=0; j<n; j++){
        //         if(a[cm] >= b[j]){
        //             cnt++;
        //         }
        //     }
        //     ans.push_back(cnt);
        // } 
        sort(b.begin(),b.end());
        for(int i=0;i<q;i++){
            int cnt = upper_bound(b.begin() , b.end() , a[query[i]]) - b.begin();
             ans.push_back(cnt);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;

    cin >> t;

    while (t--) {

        int n;
        cin >> n;
        vector<int> a, b, ans;
        int input;
        for (int i = 0; i < n; i++) {
            cin >> input;
            a.push_back(input);
        }
        for (int i = 0; i < n; i++) {
            cin >> input;
            b.push_back(input);
        }
        int q;
        cin >> q;
        vector<int> query;
        for (int i = 0; i < q; i++) {
            cin >> input;
            query.push_back(input);
        }
        Solution obj;
        ans = obj.countElements(a, b, n, query, q);
        for (int i = 0; i < q; i++) {
            cout << ans[i] << endl;
        }
    }
    return 0;
}
// } Driver Code Ends