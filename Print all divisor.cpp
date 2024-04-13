//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void print_divisors(int n) {
        vector<int>res;
        //o(sqrt(n))
        if(n == 1) cout << 1;
        else{
        for(int i = 1; i*i <= n; i++){
            if(n % i == 0){
                res.push_back(i);
                if((n / i) != i){
                    res.push_back(n/i);
                }
            }
        }
        // n factor
        // n * logn 
        sort(res.begin(),res.end());
        // o(n)
        for(auto j : res) cout << j <<" ";
        }
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        Solution ob;
        ob.print_divisors(n);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends