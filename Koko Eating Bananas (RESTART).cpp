//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int maxElement(int n,vector<int>&arr){
      int maxi = INT_MIN;
      for(int i=0;i<n;i++){
          maxi=max(maxi,arr[i]);
      }
      return maxi;
  }
  int calculateTotalTimeToEatAllBanana(vector<int>&arr,int hrToEat,int n){
      int totalHr = 0;
      for(int i=0;i<n;i++){
          totalHr += ceil((double)arr[i] / (double)hrToEat);
      }
      return totalHr;
  }
    int Solve(int N, vector<int>& piles, int H) {
        // Code here
        int low = 1;
        int high = maxElement(N,piles);
        while(low<=high){
            int mid = (low + high) / 2;
            int totalHr = calculateTotalTimeToEatAllBanana(piles,mid,N);
            if(totalHr <= H){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends