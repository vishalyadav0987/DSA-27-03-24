//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    long long int fibSum(long long int N){
        //code here
        long long int a = 0;
        long long int b = 1;
        long long int temp = 0;
        long long int sum = 0;
        for(int i = 0; i <= N; i++){
            sum = (sum + a) % 1000000007;
            int temp = a;
            a = b;
            b = (temp + b) % 1000000007;
        }
        return sum;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        Solution ob;
        cout << ob.fibSum(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends