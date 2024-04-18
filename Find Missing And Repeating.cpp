//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        int hash[n+1]={0};
        vector<int>res;
        for(int i = 0; i<n;i++){
            hash[arr[i]] +=1;
            if(hash[arr[i]] == 2){
                res.push_back(arr[i]);
                    
            }
                
        }
        for(int i = 1; i <= n; i++){
             if(hash[i] == 0){
                res.push_back(i);
                    
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends